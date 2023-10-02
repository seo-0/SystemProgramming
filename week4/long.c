#include <stdio.h>
#include <limits.h>

//long to binary 함수
void longTobin(long num) {
    for (int i = CHAR_BIT * sizeof(num) - 1; i >= 0; i--) {
        putchar(num & (1L << i) ? '1' : '0'); //비트 마스크 사용=> 1이면 1, 0이면 0출력
    }
}

int main() {
    long minValue = LONG_MIN;
    long maxValue = LONG_MAX;

    printf("정수\t\t비트(이진 수)\t\t16진 수\n");

    for (long value = minValue; value <= maxValue; value++) {
        printf("%ld\t\t", value);
        longTobin(value);
        printf("\t\t0x%016lx\n", value);
    }

    return 0;
}
