make clean
make man1
make man2
echo "Man 1, size = 1"
echo "Man 1, size = 1\n\n" >> test.out
./test_man1 >> test.out 
echo "Man 1, size = 2"
echo "Man 1, size = 2\n\n" >> test.out
./test_man1 2 >> test.out 
echo "Man 1, size = 4"
echo "Man 1, size = 4\n\n" >> test.out
./test_man1 4 >> test.out 
echo "Man 1, size = 8"
echo "Man 1, size = 8\n\n" >> test.out
./test_man1 8 >> test.out 
echo "Man 1, size = 16"
echo "Man 1, size = 16\n\n" >> test.out
./test_man1 16 >> test.out 
echo "Man 2, size = 1"
echo "Man 2, size = 1\n\n" >> test.out
./test_man2 >> test.out 
echo "Man 2, size = 2"
echo "Man 2, size = 2\n\n" >> test.out
./test_man2 2 >> test.out 
echo "Man 2, size = 4"
echo "Man 2, size = 4\n\n" >> test.out
./test_man2 4 >> test.out 
echo "Man 2, size = 8"
echo "Man 2, size = 8\n\n" >> test.out
./test_man2 8 >> test.out 
echo "Man 2, size = 16"
echo "Man 2, size = 16\n\n" >> test.out
./test_man2 16 >> test.out 
make man3 TILE=4
echo "Man 3, size = 1, tile = 4"
echo "Man 3, size = 1, tile = 4\n\n" >> test.out
./test_man3 >> test.out
echo "Man 3, size = 2, tile = 4"
echo "Man 3, size = 2, tile = 4\n\n" >> test.out
./test_man3 2 >> test.out
echo "Man 3, size = 4, tile = 4"
echo "Man 3, size = 4, tile = 4\n\n" >> test.out
./test_man3 4 >> test.out
echo "Man 3, size = 8, tile = 4"
echo "Man 3, size = 8, tile = 4\n\n" >> test.out
./test_man3 8 >> test.out
echo "Man 3, size = 16, tile = 4"
echo "Man 3, size = 16, tile = 4\n\n" >> test.out
./test_man3 16 >> test.out
make clean
make man3 TILE=8
echo "Man 3, size = 1, tile = 8"
echo "Man 3, size = 1, tile = 8\n\n" >> test.out
./test_man3 >> test.out
echo "Man 3, size = 2, tile = 8"
echo "Man 3, size = 2, tile = 8\n\n" >> test.out
./test_man3 2 >> test.out
echo "Man 3, size = 4, tile = 8"
echo "Man 3, size = 4, tile = 8\n\n" >> test.out
./test_man3 4 >> test.out
echo "Man 3, size = 8, tile = 8"
echo "Man 3, size = 8, tile = 8\n\n" >> test.out
./test_man3 8 >> test.out
echo "Man 3, size = 16, tile = 8"
echo "Man 3, size = 16, tile = 8\n\n" >> test.out
./test_man3 16 >> test.out
make clean
make man3 TILE=16
echo "Man 3, size = 1, tile = 16"
echo "Man 3, size = 1, tile = 16\n\n" >> test.out
./test_man3 >> test.out
echo "Man 3, size = 2, tile = 16"
echo "Man 3, size = 2, tile = 16\n\n" >> test.out
./test_man3 2 >> test.out
echo "Man 3, size = 4, tile = 16"
echo "Man 3, size = 4, tile = 16\n\n" >> test.out
./test_man3 4 >> test.out
echo "Man 3, size = 8, tile = 16"
echo "Man 3, size = 8, tile = 16\n\n" >> test.out
./test_man3 8 >> test.out
echo "Man 3, size = 16, tile = 16"
echo "Man 3, size = 16, tile = 16\n\n" >> test.out
./test_man3 16 >> test.out
make clean
make man3 TILE=32
echo "Man 3, size = 1, tile = 32"
echo "Man 3, size = 1, tile = 32\n\n" >> test.out
./test_man3 >> test.out
echo "Man 3, size = 2, tile = 32"
echo "Man 3, size = 2, tile = 32\n\n" >> test.out
./test_man3 2 >> test.out
echo "Man 3, size = 4, tile = 32"
echo "Man 3, size = 4, tile = 32\n\n" >> test.out
./test_man3 4 >> test.out
echo "Man 3, size = 8, tile = 32"
echo "Man 3, size = 8, tile = 32\n\n" >> test.out
./test_man3 8 >> test.out
echo "Man 3, size = 16, tile = 32"
echo "Man 3, size = 16, tile = 32\n\n" >> test.out
./test_man3 16 >> test.out
make clean 
make man3 TILE=64
echo "Man 3, size = 1, tile = 64"
echo "Man 3, size = 1, tile = 64\n\n" >> test.out
./test_man3 >> test.out
echo "Man 3, size = 2, tile = 64"
echo "Man 3, size = 2, tile = 64\n\n" >> test.out
./test_man3 2 >> test.out
echo "Man 3, size = 4, tile = 64"
echo "Man 3, size = 4, tile = 64\n\n" >> test.out
./test_man3 4 >> test.out
echo "Man 3, size = 8, tile = 64"
echo "Man 3, size = 8, tile = 64\n\n" >> test.out
./test_man3 8 >> test.out
echo "Man 3, size = 16, tile = 64"
echo "Man 3, size = 16, tile = 64\n\n" >> test.out
./test_man3 16 >> test.out
make clean 
make man3 TILE=128
echo "Man 3, size = 1, tile = 128"
echo "Man 3, size = 1, tile = 128\n\n" >> test.out
./test_man3 >> test.out
echo "Man 3, size = 2, tile = 128"
echo "Man 3, size = 2, tile = 128\n\n" >> test.out
./test_man3 2 >> test.out
echo "Man 3, size = 4, tile = 128"
echo "Man 3, size = 4, tile = 128\n\n" >> test.out
./test_man3 4 >> test.out
echo "Man 3, size = 8, tile = 128"
echo "Man 3, size = 8, tile = 128\n\n" >> test.out
./test_man3 8 >> test.out
echo "Man 3, size = 16, tile = 128"
echo "Man 3, size = 16, tile = 128\n\n" >> test.out
./test_man3 16 >> test.out
make clean 
make man3 TILE=256
echo "Man 3, size = 1, tile = 256"
echo "Man 3, size = 1, tile = 256\n\n" >> test.out
./test_man3 >> test.out
echo "Man 3, size = 2, tile = 256"
echo "Man 3, size = 2, tile = 256\n\n" >> test.out
./test_man3 2 >> test.out
echo "Man 3, size = 4, tile = 256"
echo "Man 3, size = 4, tile = 256\n\n" >> test.out
./test_man3 4 >> test.out
echo "Man 3, size = 8, tile = 256"
echo "Man 3, size = 8, tile = 256\n\n" >> test.out
./test_man3 8 >> test.out
echo "Man 3, size = 16, tile = 256"
echo "Man 3, size = 16, tile = 256\n\n" >> test.out
./test_man3 16 >> test.out
make clean 
make man3 TILE=512
echo "Man 3, size = 1, tile = 512"
echo "Man 3, size = 1, tile = 512\n\n" >> test.out
./test_man3 >> test.out
echo "Man 3, size = 2, tile = 512"
echo "Man 3, size = 2, tile = 512\n\n" >> test.out
./test_man3 2 >> test.out
echo "Man 3, size = 4, tile = 512"
echo "Man 3, size = 4, tile = 512\n\n" >> test.out
./test_man3 4 >> test.out
echo "Man 3, size = 8, tile = 512"
echo "Man 3, size = 8, tile = 512\n\n" >> test.out
./test_man3 8 >> test.out
echo "Man 3, size = 16, tile = 512"
echo "Man 3, size = 16, tile = 512\n\n" >> test.out
./test_man3 16 >> test.out
make clean 

