#include <stdio.h>
#include <limits.h>

//unsigned Long to binary 함수
void unsLongTobin(long num) {
    for (int i = CHAR_BIT * sizeof(num) - 1; i >= 0; i--) {
        putchar(num & (1L << i) ? '1' : '0');
    }
}

int main() {
    unsigned long minValue = 0;
    unsigned long maxValue = ULONG_MAX;

    printf("정수\t\t비트(이진 수)\t\t16진 수\n");

    for (unsigned long value = minValue; value <= maxValue; value++) {
        printf("%lu\t\t", value);
        unsLongTobin(value);
        printf("\t\t0x%016lx\n", value); //형식 지정자가 long 타입에서 다른 것을 주의해야한다.
    }

    return 0;
}
