make clean
make man1
make man2
for size in 1 2 4 8 16
do 
    echo "Man 1, size = $size"
    echo "Man 1, size = $size\n" >> test_par.out
    for i in 1 2 3 4
    do 
        echo "./test_man1 $size &\n" >> temp.sh
    done
    echo "wait" >> temp.sh 
    sh temp.sh >> test_par.out
    rm temp.sh
    echo "Man 2, size = $size"
    echo "Man 2, size = $size\n" >> test_par.out
    for i in 1 2 3 4
    do
        echo "./test_man2 $size &\n" >> temp.sh
    done
    echo "wait" >> temp.sh 
    sh temp.sh >> test_par.out
    rm temp.sh
done
for tile in 4 8 16 32 64 128 256 512
do 
    make man3 TILE=$tile
    for size in 1 2 4 8 16
    do 
        echo "Man 3, size = $size, tile = $tile"
        echo "Man 3, size = $size, tile = $tile\n" >> test_par.out
        for i in 1 2 3 4
        do 
            echo "./test_man3 $size &\n" >> temp.sh
        done
        echo "wait" >> temp.sh 
        sh temp.sh >> test_par.out
        rm temp.sh
    done
    make clean
done
