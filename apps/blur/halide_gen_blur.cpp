#include <iostream>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#ifndef HALIDE_ATTRIBUTE_ALIGN
  #ifdef _MSC_VER
    #define HALIDE_ATTRIBUTE_ALIGN(x) __declspec(align(x))
  #else
    #define HALIDE_ATTRIBUTE_ALIGN(x) __attribute__((aligned(x)))
  #endif
#endif
#ifndef BUFFER_T_DEFINED
#define BUFFER_T_DEFINED
#include <stdbool.h>
#include <stdint.h>
typedef struct buffer_t {
    uint64_t dev;
    uint8_t* host;
    int32_t extent[4];
    int32_t stride[4];
    int32_t min[4];
    int32_t elem_size;
    HALIDE_ATTRIBUTE_ALIGN(1) bool host_dirty;
    HALIDE_ATTRIBUTE_ALIGN(1) bool dev_dirty;
    HALIDE_ATTRIBUTE_ALIGN(1) uint8_t _padding[10 - sizeof(void *)];
} buffer_t;
#endif
struct halide_filter_metadata_t;
extern "C" {
void *halide_malloc(void *ctx, size_t);
void halide_free(void *ctx, void *ptr);
void *halide_print(void *ctx, const void *str);
void *halide_error(void *ctx, const void *str);
int halide_debug_to_file(void *ctx, const char *filename, int, struct buffer_t *buf);
int halide_start_clock(void *ctx);
int64_t halide_current_time_ns(void *ctx);
void halide_profiler_pipeline_end(void *, void *);
}

#ifdef _WIN32
float roundf(float);
double round(double);
#else
inline float asinh_f32(float x) {return asinhf(x);}
inline float acosh_f32(float x) {return acoshf(x);}
inline float atanh_f32(float x) {return atanhf(x);}
inline double asinh_f64(double x) {return asinh(x);}
inline double acosh_f64(double x) {return acosh(x);}
inline double atanh_f64(double x) {return atanh(x);}
#endif
inline float sqrt_f32(float x) {return sqrtf(x);}
inline float sin_f32(float x) {return sinf(x);}
inline float asin_f32(float x) {return asinf(x);}
inline float cos_f32(float x) {return cosf(x);}
inline float acos_f32(float x) {return acosf(x);}
inline float tan_f32(float x) {return tanf(x);}
inline float atan_f32(float x) {return atanf(x);}
inline float sinh_f32(float x) {return sinhf(x);}
inline float cosh_f32(float x) {return coshf(x);}
inline float tanh_f32(float x) {return tanhf(x);}
inline float hypot_f32(float x, float y) {return hypotf(x, y);}
inline float exp_f32(float x) {return expf(x);}
inline float log_f32(float x) {return logf(x);}
inline float pow_f32(float x, float y) {return powf(x, y);}
inline float floor_f32(float x) {return floorf(x);}
inline float ceil_f32(float x) {return ceilf(x);}
inline float round_f32(float x) {return roundf(x);}

inline double sqrt_f64(double x) {return sqrt(x);}
inline double sin_f64(double x) {return sin(x);}
inline double asin_f64(double x) {return asin(x);}
inline double cos_f64(double x) {return cos(x);}
inline double acos_f64(double x) {return acos(x);}
inline double tan_f64(double x) {return tan(x);}
inline double atan_f64(double x) {return atan(x);}
inline double sinh_f64(double x) {return sinh(x);}
inline double cosh_f64(double x) {return cosh(x);}
inline double tanh_f64(double x) {return tanh(x);}
inline double hypot_f64(double x, double y) {return hypot(x, y);}
inline double exp_f64(double x) {return exp(x);}
inline double log_f64(double x) {return log(x);}
inline double pow_f64(double x, double y) {return pow(x, y);}
inline double floor_f64(double x) {return floor(x);}
inline double ceil_f64(double x) {return ceil(x);}
inline double round_f64(double x) {return round(x);}

inline float nan_f32() {return NAN;}
inline float neg_inf_f32() {return -INFINITY;}
inline float inf_f32() {return INFINITY;}
inline bool is_nan_f32(float x) {return x != x;}
inline bool is_nan_f64(double x) {return x != x;}
inline float float_from_bits(uint32_t bits) {
 union {
  uint32_t as_uint;
  float as_float;
 } u;
 u.as_uint = bits;
 return u.as_float;
}
inline int64_t make_int64(int32_t hi, int32_t lo) {
    return (((int64_t)hi) << 32) | (uint32_t)lo;
}
inline double make_float64(int32_t i0, int32_t i1) {
    union {
        int32_t as_int32[2];
        double as_double;
    } u;
    u.as_int32[0] = i0;
    u.as_int32[1] = i1;
    return u.as_double;
}

template<typename T> T max(T a, T b) {if (a > b) return a; return b;}
template<typename T> T min(T a, T b) {if (a < b) return a; return b;}
template<typename A, typename B> A reinterpret(B b) {A a; memcpy(&a, &b, sizeof(a)); return a;}

static bool halide_rewrite_buffer(buffer_t *b, int32_t elem_size,
                           int32_t min0, int32_t extent0, int32_t stride0,
                           int32_t min1, int32_t extent1, int32_t stride1,
                           int32_t min2, int32_t extent2, int32_t stride2,
                           int32_t min3, int32_t extent3, int32_t stride3) {
 b->min[0] = min0;
 b->min[1] = min1;
 b->min[2] = min2;
 b->min[3] = min3;
 b->extent[0] = extent0;
 b->extent[1] = extent1;
 b->extent[2] = extent2;
 b->extent[3] = extent3;
 b->stride[0] = stride0;
 b->stride[1] = stride1;
 b->stride[2] = stride2;
 b->stride[3] = stride3;
 return true;
}
#ifndef HALIDE_FUNCTION_ATTRS
#define HALIDE_FUNCTION_ATTRS
#endif
#ifdef __cplusplus
extern "C" {
#endif

int32_t  halide_error_bad_elem_size(void *, const char *, const char *, int32_t , int32_t );
int32_t  halide_error_access_out_of_bounds(void *, const char *, int32_t , int32_t , int32_t , int32_t , int32_t );
int32_t  halide_error_constraint_violated(void *, const char *, int32_t , const char *, int32_t );
int32_t  halide_error_buffer_allocation_too_large(void *, const char *, int64_t , int64_t );
int32_t  halide_error_buffer_extents_too_large(void *, const char *, int64_t , int64_t );

static int __halide_blur(buffer_t *_input_buffer, buffer_t *_blur_y_buffer) HALIDE_FUNCTION_ATTRS {
 uint16_t *_input = (uint16_t *)(_input_buffer->host);
 (void)_input;
 const bool _input_host_and_dev_are_null = (_input_buffer->host == nullptr) && (_input_buffer->dev == 0);
 (void)_input_host_and_dev_are_null;
 const int32_t _input_min_0 = _input_buffer->min[0];
 (void)_input_min_0;
 const int32_t _input_min_1 = _input_buffer->min[1];
 (void)_input_min_1;
 const int32_t _input_min_2 = _input_buffer->min[2];
 (void)_input_min_2;
 const int32_t _input_min_3 = _input_buffer->min[3];
 (void)_input_min_3;
 const int32_t _input_extent_0 = _input_buffer->extent[0];
 (void)_input_extent_0;
 const int32_t _input_extent_1 = _input_buffer->extent[1];
 (void)_input_extent_1;
 const int32_t _input_extent_2 = _input_buffer->extent[2];
 (void)_input_extent_2;
 const int32_t _input_extent_3 = _input_buffer->extent[3];
 (void)_input_extent_3;
 const int32_t _input_stride_0 = _input_buffer->stride[0];
 (void)_input_stride_0;
 const int32_t _input_stride_1 = _input_buffer->stride[1];
 (void)_input_stride_1;
 const int32_t _input_stride_2 = _input_buffer->stride[2];
 (void)_input_stride_2;
 const int32_t _input_stride_3 = _input_buffer->stride[3];
 (void)_input_stride_3;
 const int32_t _input_elem_size = _input_buffer->elem_size;
 (void)_input_elem_size;
 uint16_t *_blur_y = (uint16_t *)(_blur_y_buffer->host);
 (void)_blur_y;
 const bool _blur_y_host_and_dev_are_null = (_blur_y_buffer->host == nullptr) && (_blur_y_buffer->dev == 0);
 (void)_blur_y_host_and_dev_are_null;
 const int32_t _blur_y_min_0 = _blur_y_buffer->min[0];
 (void)_blur_y_min_0;
 const int32_t _blur_y_min_1 = _blur_y_buffer->min[1];
 (void)_blur_y_min_1;
 const int32_t _blur_y_min_2 = _blur_y_buffer->min[2];
 (void)_blur_y_min_2;
 const int32_t _blur_y_min_3 = _blur_y_buffer->min[3];
 (void)_blur_y_min_3;
 const int32_t _blur_y_extent_0 = _blur_y_buffer->extent[0];
 (void)_blur_y_extent_0;
 const int32_t _blur_y_extent_1 = _blur_y_buffer->extent[1];
 (void)_blur_y_extent_1;
 const int32_t _blur_y_extent_2 = _blur_y_buffer->extent[2];
 (void)_blur_y_extent_2;
 const int32_t _blur_y_extent_3 = _blur_y_buffer->extent[3];
 (void)_blur_y_extent_3;
 const int32_t _blur_y_stride_0 = _blur_y_buffer->stride[0];
 (void)_blur_y_stride_0;
 const int32_t _blur_y_stride_1 = _blur_y_buffer->stride[1];
 (void)_blur_y_stride_1;
 const int32_t _blur_y_stride_2 = _blur_y_buffer->stride[2];
 (void)_blur_y_stride_2;
 const int32_t _blur_y_stride_3 = _blur_y_buffer->stride[3];
 (void)_blur_y_stride_3;
 const int32_t _blur_y_elem_size = _blur_y_buffer->elem_size;
 (void)_blur_y_elem_size;
 if (_blur_y_host_and_dev_are_null)
 {
  bool _0 = halide_rewrite_buffer(_blur_y_buffer, 2, _blur_y_min_0, _blur_y_extent_0, 1, _blur_y_min_1, _blur_y_extent_1, _blur_y_extent_0, 0, 0, 0, 0, 0, 0);
  (void)_0;
 } // if _blur_y_host_and_dev_are_null
 if (_input_host_and_dev_are_null)
 {
  int32_t _1 = _blur_y_extent_0 + 2;
  int32_t _2 = _blur_y_extent_1 + 2;
  bool _3 = halide_rewrite_buffer(_input_buffer, 2, _blur_y_min_0, _1, 1, _blur_y_min_1, _2, _1, 0, 0, 0, 0, 0, 0);
  (void)_3;
 } // if _input_host_and_dev_are_null
 bool _4 = _blur_y_host_and_dev_are_null || _input_host_and_dev_are_null;
 bool _5 = !(_4);
 if (_5)
 {
  bool _6 = _blur_y_elem_size == 2;
  if (!_6)   {
   int32_t _7 = halide_error_bad_elem_size(nullptr, "Output buffer blur_y", "uint16", _blur_y_elem_size, 2);
   return _7;
  }
  bool _8 = _input_elem_size == 2;
  if (!_8)   {
   int32_t _9 = halide_error_bad_elem_size(nullptr, "Input buffer input", "uint16", _input_elem_size, 2);
   return _9;
  }
  bool _10 = _input_min_0 <= _blur_y_min_0;
  int32_t _11 = _blur_y_min_0 + _blur_y_extent_0;
  int32_t _12 = _11 - _input_extent_0;
  int32_t _13 = _12 + 2;
  bool _14 = _13 <= _input_min_0;
  bool _15 = _10 && _14;
  if (!_15)   {
   int32_t _16 = _blur_y_min_0 + _blur_y_extent_0;
   int32_t _17 = _16 + 1;
   int32_t _18 = _input_min_0 + _input_extent_0;
   int32_t _19 = _18 + -1;
   int32_t _20 = halide_error_access_out_of_bounds(nullptr, "Input buffer input", 0, _blur_y_min_0, _17, _input_min_0, _19);
   return _20;
  }
  bool _21 = _input_min_1 <= _blur_y_min_1;
  int32_t _22 = _blur_y_min_1 + _blur_y_extent_1;
  int32_t _23 = _22 - _input_extent_1;
  int32_t _24 = _23 + 2;
  bool _25 = _24 <= _input_min_1;
  bool _26 = _21 && _25;
  if (!_26)   {
   int32_t _27 = _blur_y_min_1 + _blur_y_extent_1;
   int32_t _28 = _27 + 1;
   int32_t _29 = _input_min_1 + _input_extent_1;
   int32_t _30 = _29 + -1;
   int32_t _31 = halide_error_access_out_of_bounds(nullptr, "Input buffer input", 1, _blur_y_min_1, _28, _input_min_1, _30);
   return _31;
  }
  bool _32 = _blur_y_stride_0 == 1;
  if (!_32)   {
   int32_t _33 = halide_error_constraint_violated(nullptr, "blur_y.stride.0", _blur_y_stride_0, "1", 1);
   return _33;
  }
  bool _34 = _input_stride_0 == 1;
  if (!_34)   {
   int32_t _35 = halide_error_constraint_violated(nullptr, "input.stride.0", _input_stride_0, "1", 1);
   return _35;
  }
  int64_t _36 = (int64_t)(_blur_y_extent_1);
  int64_t _37 = (int64_t)(_blur_y_extent_0);
  int64_t _38 = _36 * _37;
  int64_t _39 = (int64_t)(_input_extent_1);
  int64_t _40 = (int64_t)(_input_extent_0);
  int64_t _41 = _39 * _40;
  int64_t _42 = (int64_t)(2147483647);
  bool _43 = _37 <= _42;
  if (!_43)   {
   int64_t _44 = (int64_t)(_blur_y_extent_0);
   int64_t _45 = (int64_t)(2147483647);
   int32_t _46 = halide_error_buffer_allocation_too_large(nullptr, "blur_y", _44, _45);
   return _46;
  }
  int64_t _47 = (int64_t)(_blur_y_extent_1);
  int64_t _48 = (int64_t)(_blur_y_stride_1);
  int64_t _49 = _47 * _48;
  int64_t _50 = (int64_t)(2147483647);
  bool _51 = _49 <= _50;
  if (!_51)   {
   int64_t _52 = (int64_t)(_blur_y_extent_1);
   int64_t _53 = (int64_t)(_blur_y_stride_1);
   int64_t _54 = _52 * _53;
   int64_t _55 = (int64_t)(2147483647);
   int32_t _56 = halide_error_buffer_allocation_too_large(nullptr, "blur_y", _54, _55);
   return _56;
  }
  int64_t _57 = (int64_t)(2147483647);
  bool _58 = _38 <= _57;
  if (!_58)   {
   int64_t _59 = (int64_t)(2147483647);
   int32_t _60 = halide_error_buffer_extents_too_large(nullptr, "blur_y", _38, _59);
   return _60;
  }
  int64_t _61 = (int64_t)(_input_extent_0);
  int64_t _62 = (int64_t)(2147483647);
  bool _63 = _61 <= _62;
  if (!_63)   {
   int64_t _64 = (int64_t)(_input_extent_0);
   int64_t _65 = (int64_t)(2147483647);
   int32_t _66 = halide_error_buffer_allocation_too_large(nullptr, "input", _64, _65);
   return _66;
  }
  int64_t _67 = (int64_t)(_input_extent_1);
  int64_t _68 = (int64_t)(_input_stride_1);
  int64_t _69 = _67 * _68;
  int64_t _70 = (int64_t)(2147483647);
  bool _71 = _69 <= _70;
  if (!_71)   {
   int64_t _72 = (int64_t)(_input_extent_1);
   int64_t _73 = (int64_t)(_input_stride_1);
   int64_t _74 = _72 * _73;
   int64_t _75 = (int64_t)(2147483647);
   int32_t _76 = halide_error_buffer_allocation_too_large(nullptr, "input", _74, _75);
   return _76;
  }
  int64_t _77 = (int64_t)(2147483647);
  bool _78 = _41 <= _77;
  if (!_78)   {
   int64_t _79 = (int64_t)(2147483647);
   int32_t _80 = halide_error_buffer_extents_too_large(nullptr, "input", _41, _79);
   return _80;
  }
  {
   int64_t _81 = _blur_y_extent_0;
   int32_t _82 = _blur_y_extent_1 + 2;
   int64_t _83 = _81 * _82;
   if ((_83 > ((int64_t(1) << 31) - 1)) || ((_83 * sizeof(uint16_t)) > ((int64_t(1) << 31) - 1)))
   {
    halide_error(nullptr, "32-bit signed overflow computing size of allocation blur_x\n");
    return -1;
   } // overflow test blur_x
   int64_t _84 = _83;
   uint16_t *_blur_x = (uint16_t *)halide_malloc(nullptr, sizeof(uint16_t)*_84);
   // produce blur_x
   int32_t _85 = _blur_y_extent_1 + 2;
   for (int _blur_x_s0_y = _blur_y_min_1; _blur_x_s0_y < _blur_y_min_1 + _85; _blur_x_s0_y++)
   {
    for (int _blur_x_s0_x = _blur_y_min_0; _blur_x_s0_x < _blur_y_min_0 + _blur_y_extent_0; _blur_x_s0_x++)
    {
     int32_t _86 = _blur_x_s0_x - _blur_y_min_0;
     int32_t _87 = _blur_x_s0_y - _blur_y_min_1;
     int32_t _88 = _87 * _blur_y_extent_0;
     int32_t _89 = _86 + _88;
     int32_t _90 = _blur_x_s0_y * _input_stride_1;
     int32_t _91 = _blur_x_s0_x + _90;
     int32_t _92 = _input_min_1 * _input_stride_1;
     int32_t _93 = _input_min_0 + _92;
     int32_t _94 = _91 - _93;
     uint16_t _95 = _input[_94];
     int32_t _96 = _94 + 1;
     uint16_t _97 = _input[_96];
     uint16_t _98 = _95 + _97;
     int32_t _99 = _94 + 2;
     uint16_t _100 = _input[_99];
     uint16_t _101 = _98 + _100;
     uint16_t _102 = (uint16_t)(3);
     uint16_t _103 = _101 / _102;
     _blur_x[_89] = _103;
    } // for _blur_x_s0_x
   } // for _blur_x_s0_y
   // consume blur_x
   // produce blur_y
   for (int _blur_y_s0_y = _blur_y_min_1; _blur_y_s0_y < _blur_y_min_1 + _blur_y_extent_1; _blur_y_s0_y++)
   {
    for (int _blur_y_s0_x = _blur_y_min_0; _blur_y_s0_x < _blur_y_min_0 + _blur_y_extent_0; _blur_y_s0_x++)
    {
     int32_t _104 = _blur_y_s0_y * _blur_y_stride_1;
     int32_t _105 = _blur_y_s0_x + _104;
     int32_t _106 = _blur_y_min_1 * _blur_y_stride_1;
     int32_t _107 = _blur_y_min_0 + _106;
     int32_t _108 = _105 - _107;
     int32_t _109 = _blur_y_s0_x - _blur_y_min_0;
     int32_t _110 = _blur_y_s0_y - _blur_y_min_1;
     int32_t _111 = _110 * _blur_y_extent_0;
     int32_t _112 = _109 + _111;
     uint16_t _113 = _blur_x[_112];
     int32_t _114 = _110 + 1;
     int32_t _115 = _114 * _blur_y_extent_0;
     int32_t _116 = _109 + _115;
     uint16_t _117 = _blur_x[_116];
     uint16_t _118 = _113 + _117;
     int32_t _119 = _110 + 2;
     int32_t _120 = _119 * _blur_y_extent_0;
     int32_t _121 = _109 + _120;
     uint16_t _122 = _blur_x[_121];
     uint16_t _123 = _118 + _122;
     uint16_t _124 = (uint16_t)(3);
     uint16_t _125 = _123 / _124;
     _blur_y[_108] = _125;
    } // for _blur_y_s0_x
   } // for _blur_y_s0_y
   halide_free(nullptr, _blur_x);
   // consume blur_y
  } // alloc _blur_x
 } // if _5
 return 0;
}


int halide_blur(buffer_t *_input_buffer, buffer_t *_blur_y_buffer) HALIDE_FUNCTION_ATTRS {
 uint16_t *_input = (uint16_t *)(_input_buffer->host);
 (void)_input;
 const bool _input_host_and_dev_are_null = (_input_buffer->host == nullptr) && (_input_buffer->dev == 0);
 (void)_input_host_and_dev_are_null;
 const int32_t _input_min_0 = _input_buffer->min[0];
 (void)_input_min_0;
 const int32_t _input_min_1 = _input_buffer->min[1];
 (void)_input_min_1;
 const int32_t _input_min_2 = _input_buffer->min[2];
 (void)_input_min_2;
 const int32_t _input_min_3 = _input_buffer->min[3];
 (void)_input_min_3;
 const int32_t _input_extent_0 = _input_buffer->extent[0];
 (void)_input_extent_0;
 const int32_t _input_extent_1 = _input_buffer->extent[1];
 (void)_input_extent_1;
 const int32_t _input_extent_2 = _input_buffer->extent[2];
 (void)_input_extent_2;
 const int32_t _input_extent_3 = _input_buffer->extent[3];
 (void)_input_extent_3;
 const int32_t _input_stride_0 = _input_buffer->stride[0];
 (void)_input_stride_0;
 const int32_t _input_stride_1 = _input_buffer->stride[1];
 (void)_input_stride_1;
 const int32_t _input_stride_2 = _input_buffer->stride[2];
 (void)_input_stride_2;
 const int32_t _input_stride_3 = _input_buffer->stride[3];
 (void)_input_stride_3;
 const int32_t _input_elem_size = _input_buffer->elem_size;
 (void)_input_elem_size;
 uint16_t *_blur_y = (uint16_t *)(_blur_y_buffer->host);
 (void)_blur_y;
 const bool _blur_y_host_and_dev_are_null = (_blur_y_buffer->host == nullptr) && (_blur_y_buffer->dev == 0);
 (void)_blur_y_host_and_dev_are_null;
 const int32_t _blur_y_min_0 = _blur_y_buffer->min[0];
 (void)_blur_y_min_0;
 const int32_t _blur_y_min_1 = _blur_y_buffer->min[1];
 (void)_blur_y_min_1;
 const int32_t _blur_y_min_2 = _blur_y_buffer->min[2];
 (void)_blur_y_min_2;
 const int32_t _blur_y_min_3 = _blur_y_buffer->min[3];
 (void)_blur_y_min_3;
 const int32_t _blur_y_extent_0 = _blur_y_buffer->extent[0];
 (void)_blur_y_extent_0;
 const int32_t _blur_y_extent_1 = _blur_y_buffer->extent[1];
 (void)_blur_y_extent_1;
 const int32_t _blur_y_extent_2 = _blur_y_buffer->extent[2];
 (void)_blur_y_extent_2;
 const int32_t _blur_y_extent_3 = _blur_y_buffer->extent[3];
 (void)_blur_y_extent_3;
 const int32_t _blur_y_stride_0 = _blur_y_buffer->stride[0];
 (void)_blur_y_stride_0;
 const int32_t _blur_y_stride_1 = _blur_y_buffer->stride[1];
 (void)_blur_y_stride_1;
 const int32_t _blur_y_stride_2 = _blur_y_buffer->stride[2];
 (void)_blur_y_stride_2;
 const int32_t _blur_y_stride_3 = _blur_y_buffer->stride[3];
 (void)_blur_y_stride_3;
 const int32_t _blur_y_elem_size = _blur_y_buffer->elem_size;
 (void)_blur_y_elem_size;
 int32_t _126 = __halide_blur(_input_buffer, _blur_y_buffer);
 bool _127 = _126 == 0;
 if (!_127)  {
  return _126;
 }
 return 0;
}
#ifdef __cplusplus
}  // extern "C"
#endif
