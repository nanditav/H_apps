make clean
make
for size in 1 2 4 8 16
do 
    arr_size=$(( $size * 1024 ))
    c=$arr_size
    while [ $c -ge 1 ]
    do 
        echo "Size:$size TileSize:$c"
        echo "Size:$size TileSize:$c" 
        ./mat_mul 0 $size $c
        c=$(( $c / 2 ))
    done
done
