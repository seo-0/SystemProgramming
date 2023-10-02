#include <stdio.h>
#include <limits.h>

//unsigned short Int to binary 함수
void unsShortintTobin(int num) {
    for (int i = CHAR_BIT * sizeof(num) - 1; i >= 0; i--) {
        putchar(num & (1 << i) ? '1' : '0'); //비트 마스크 사용=> 1이면 1, 0이면 0출력
    }
}

int main() {
    int maxValue = USHRT_MAX;
    int minValue = 0;

    printf("정수\t\t비트(이진 수)\t\t16진 수\n");

    for (int value = minValue; value <= maxValue; value++) {
        printf("%d\t\t", value);
        unsShortintTobin(value);
        printf("\t\t0x%08x\n", value);
    }

    return 0;
}
