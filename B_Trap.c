#include <stdio.h>

int main(int argc, char const *argv[]) {
    char W[31];
    int i = 0;
    scanf("%s", W );
    while(W[i]!='\0'){
    if(W[i]!='a' && W[i]!='i' && W[i]!='u' && W[i]!='e' && W[i]!='o'){
      printf("%c",W[i]);
    }
    i++;
  }
    printf("\n");
    return 0;
}
