#include <stdio.h>

int main(int argc, char const *argv[]) {
    long X, Y;
    scanf("%ld%ld", &X, &Y );
    if ( X > Y) {
        printf("%ld\n", X );
    } else {
        printf("%ld\n", Y );
    }
    return 0;
}
