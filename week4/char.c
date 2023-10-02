#include <stdio.h>
#include <limits.h>

void charTobin(char c){ //char to binary 함수
    for(int i= CHAR_BIT * sizeof(c) -1; i>=0 ; i--){
        putchar(c & (1 << i) ? '1' :'0');
    }
}

char main(){
    int minValue = CHAR_MIN;
    int maxValue = CHAR_MAX;

    printf("정수\t\t비트(이진 수)\t\t16진 수\n");

    for(int val= minValue; val<=maxValue; val++){
        printf("%d\t\t", val);
        charTobin(val);
        printf("\t\t0x%08x\n", val);
    }
    return 0;
}