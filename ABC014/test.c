#include <stdio.h>
#define swap(a, b) (a+=b, b=a-b, a-=b)

int main(int argc, char const *argv[]) {
    //入力
    int a = 9;
    int b = 4;
    swap(a, b);
    printf("a:%d b:%d \n", a, b);

    return 0;
}
