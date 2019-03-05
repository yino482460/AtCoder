#include <stdio.h>
#include <stdlib.h>

#define N_max 200000

int main(int argc, char const *argv[]) {
  int N;
  int A[N_max];
  int B[N_max];
  int i, j;
  //入力
  scanf("%d", &N );
  for ( i = 0; i < N; i++) {
    scanf("%d", &A[i] );
    A[i] = abs( A[i] -(i+1) );
  }
  //前処理(降順ソート)
  int t;
  for ( i = 1; i < N; i++) {
    for ( j = i-1; j >= 0; j--) {
      if ( B[j] < B[j+1] ) {
        t = B[j];   A[j] = B[j+1];   B[j+1] = t;
      }
      else
      break;
    }
  }
//計算
int median = 0;
if ( N%2 == 0) {
  median = A[N/2];
} else {
  median = A[N/2];
}
long sum = 0;

  long Sum = 0;
  for ( i = 0; i < N; i++) {
    A[i] = abs(A[i] - (i+1) );
    Sum += A[i];
  }
  //探索
  int b = 0;
  for ( i = 0; i < N_max; i++) {
    for ( j = 0; j < N; j++) {
      B[j] = abs(A[j] - b);
      sum += B[j];
    }
    if ( sum < Sum) {
      Sum = sum;
    }
    b++;
    sum = 0;
  }
  //出力
  printf("%ld\n", Sum );

  return 0;
}
