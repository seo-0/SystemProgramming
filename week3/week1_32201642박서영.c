#include <stdio.h>

int main(){
    signed char x= 100;
    signed char y= -100;

    printf("\n<x, y의 초기값> \n");
    printf("x= %d, (0x%02X), ", x, x & 0xFF);
    for (int i = 7; i>=0; i--){ 
        printf("%d", (x >>i) & 1); //가장 오른쪽 비트만 추출하려고 1와 and 연산 수행!
    }
    printf(" => 시프트 0 \n");

    printf("y= %d, (0x%02X), ", y, y & 0xFF);
    for (int i = 7; i>=0; i--){ 
        printf("%d", (y >>i) & 1);
    }
    printf(" => 시프트 0 \n");

    for (int shift =1; shift<= 8; shift++){
        x >>= 1;
        y >>= 1; //오른쪽 시프트 연산
        printf("\n비트연산 %d번 수행한 후의 결과: \n", shift);

        printf("x= %d, (0x%02X), ", x, x & 0xFF);
        for (int i = 7; i>=0; i--){ 
            printf("%d", (x >>i) & 1);
        }
        printf(" => 시프트 %d \n", shift); //x의 시프트연산 끝

        printf("y= %d, (0x%02X), ", y, y & 0xFF );
        for (int i = 7; i >= 0; i--) {
            printf("%d", (y >> i) & 1);
        }
        printf(" => 시프트 %d \n", shift);//y의 시프트연산 끝
    }
    return 0;
}
