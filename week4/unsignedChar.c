#include <stdio.h>
#include <limits.h>

//unsignedChar(0~255) to binary 함수 
void unsCharTobin(unsigned char c) {
    for (int i = CHAR_BIT * sizeof(c) - 1; i >= 0; i--) {
        putchar(c & (1 << i) ? '1' : '0'); //비트 마스크 사용=> 1이면 1, 0이면 0출력
    }
}

int main() {
    int minValue = 0;
    int maxValue = 255;

    printf("정수\t\t비트(이진 수)\t\t16진 수\n");

    for (int value = minValue; value <= maxValue; value++) {
        printf("%d\t\t", value);
        unsCharTobin(value);
        printf("\t\t0x%08x\n", value);
    }

    return 0;
}
