#include <stdio.h>
#include <limits.h>

//unsigned int to binary 함수
void unsintTobin(unsigned int num) {
    for (int i = CHAR_BIT * sizeof(num) - 1; i >= 0; i--) {
        putchar(num & (1U << i) ? '1' : '0'); //비트 마스크 U 사용=> 1이면 1, 0이면 0출력
    }
}

int main() {
    int minValue = 0;
    int maxValue = UINT_MAX;

    printf("정수\t\t비트(이진 수)\t\t16진 수\n");

    for (unsigned int value = minValue; value <= maxValue; value++) {
        printf("%u\t\t", value); //지정형식자 %u 주의
        unsintTobin(value);
        printf("\t\t0x%08x\n", value);
    }

    return 0;
}
