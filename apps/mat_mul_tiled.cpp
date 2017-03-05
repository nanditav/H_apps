#include <stdio.h>
#include <stdlib.h>

#define BS 32
#define N 16384 

int main() {
    int* A = new int[N*N];
    int* B = new int[N*N];
    int* C = new int[N*N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            A[i*N+j] = rand();
            B[i*N+j] = rand();
            C[i*N+j] = 0;
        }
    }
    while(1){
    for(int l2=0; l2<N; l2+=BS) {
        for(int j2=0; j2<N; j2+=BS) {
            for(int i=0; i<N; i++) {
                for(int l=l2; l<(l2+BS); l++) {
                    for(int j=j2; j<(j2+BS); j++) {
                        C[i*N+j] += A[i*N+l]*B[l*N+j];
                    }
                }
            }
        }
    }
    }
}

                                                                        

