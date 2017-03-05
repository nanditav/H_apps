#include "Halide.h"
#include <math.h>
#include "../support/auto_build.h"
using namespace Halide;

int main(int argc, char **argv) {

    ImageParam input(Float(32), 2);
    Func blur_x("blur_x"), blur_y("blur_y");
    Var x("x"), y("y"), xi("xi"), yi("yi"), xo("xo"), yo("yo");
    int tile_size = 4;
    
    // The algorithm
    blur_x(x, y) = (sin(input(x, y)) + sin(input(x+1, y)) + sin(input(x+2, y)))/3;
    blur_y(x, y) = (sin(blur_x(x, y)) + sin(blur_x(x, y+1)) + sin(blur_x(x, y+2)))/3;

    // Adding bounds
    //blur_y.bound(x, 0, 6400).bound(y, 0, 4800);
    blur_y.estimate(x, 0, 6400).estimate(y, 0, 4800);

    // Pick a schedule
    int schedule = atoi(argv[1]);

    if(argc > 2)
        tile_size = atoi(argv[2]);

    Target target = get_target_from_environment();

// Inlined 
    if(schedule == 1) {
        blur_y.compute_root();
    }

// Compute root 
    if(schedule == 2) {
        blur_x.compute_root();
        blur_y.compute_root();
    }

// Tile sweep 
    if(schedule == 3) {
        printf("Tile size: %d\n",tile_size);
        blur_y.compute_root().tile(x, y, xo, yo, xi, yi, tile_size, tile_size);
        blur_x.compute_at(blur_y, xo);
    }

    if (schedule == 0) {
        if (target.has_gpu_feature()) {
            blur_y.compute_root().gpu_tile(x, y, 16, 16);
            blur_x.compute_at(blur_y, Var::gpu_blocks()).gpu_threads(x, y);
        } else {
            // Repository schedule
            blur_y.split(y, y, yi, 8).parallel(y).vectorize(x, 8);
            blur_x.store_at(blur_y, y).compute_at(blur_y, yi).vectorize(x, 8);
        }
    }

    if (schedule == -2) {
        target.set_feature(Halide::Target::CUDACapability35);
        target.set_feature(Halide::Target::CUDA);
        //target.set_feature(Halide::Target::Debug);
    }

    auto_build(blur_y, "halide_sin_blur", {input}, target,
                                        (schedule == -1 || schedule == -2));

    /*
    blur_y.split(y, y, yi, 4).split(x, x, xi, 64).reorder(xi, yi, x, y).
                                                parallel(y).vectorize(xi);
    blur_x.compute_at(blur_y, x).vectorize(x);

    blur_y.compile_to_lowered_stmt("halide_blur_lower", {input});
    blur_y.compile_to_c("halide_gen_blur.cpp",  {input});
    blur_y.compile_to_header("halide_gen_blur.h",  {input});
    */

    return 0;
}
