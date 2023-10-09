#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

void Magic(const unsigned char *magic, int sizeofArray) { //magic 은 읽기 전용 
    printf(" ");
    for (int i = 0; i < sizeofArray; i++) {
        printf("%02x ", magic[i]);
    }
    printf("\n");
}

void Endian(unsigned char elf_class) {
    printf("Endian: ");
    if (elf_class == ELFDATA2LSB) {
        printf("Little-endian \n");
    } else if (elf_class == ELFDATA2MSB) {
        printf("Big-endian \n");
    } else {
        printf("엔디안 방식 모름\n");
    }
}

void Type(unsigned char elf_type) { //타입 중 해당되는 타입 출력, hello.c의 경우 공유객체파일임
    printf("Type: ");
    switch (elf_type) {
        case ET_NONE:
            printf("없음 \n");
            break;
        case ET_REL: // 재배치 가능한 객체 파일- 코드,데이터의 일부 포함함
            printf("Relocatable Type\n");
            break;
        case ET_EXEC: //직접 로드되는 실행가능한 파일
            printf("Exec Type\n");
            break;
        case ET_DYN: // 공유 라이브러리를 포함한 동적 실행 파일임
            printf("DYN Type\n");
            break;
        case ET_CORE: // 프로그램 비정상적 종료시 발생, 메모리 덤프 포함
            printf("Core Dump Type\n");
            break;
        default:
            printf("그 외 타입 : (0x%x)\n", elf_type);
            break;
    }
}

void Osabi(unsigned char osabi) {
    printf("OS/ABI: "); //운영체제 응용프로그램 바이너리 인터페이스를 의미하는 필드임
    switch (osabi) {
        case ELFOSABI_NONE: //운영체제와 관련된 특별한 요구사항 없는 일반 파일일 때
            printf("UNIX - System V\n");
            break;
        default:
            printf("그 외 os/abi: (0x%x)\n", osabi);
            break;
    }
}

void Machine(Elf64_Half machine) { //어떤 종류의 프로세서에서 실행되는지를 지정하는 것.
    printf("Machine: ");
    switch (machine) {
        case EM_X86_64: //64비트 아키텍쳐-일반적임, 그외 타입은 많지만 논외로 처리
            printf("Advanced Micro Devices X86-64\n");
            break;
        default:
            printf("그 외 machine: (0x%x)\n", machine);
            break;
    }
}

void elfHeader(Elf64_Ehdr *header) {
    printf("ELF Header 출력 정보 ----------------------------------------------------\n");
    Magic(header->e_ident, 64);
    printf("Class: ");
    if (header->e_ident[EI_CLASS] == ELFCLASS32) {
        printf("32 bit\n");
    } else if (header->e_ident[EI_CLASS] == ELFCLASS64) {
        printf("64 bit\n");
    } else {
        printf("몇 비트 클래스인지 모름\n");
    }

    Endian(header->e_ident[EI_DATA]);
    printf("Version: %d \n", header->e_version);
    Osabi(header->e_ident[EI_OSABI]);
    printf("ABI Version: %d \n", header->e_ident[EI_ABIVERSION]);
    Type(header->e_type);
    Machine(header->e_machine);
    printf("Version: 0x%02x\n", header->e_version);
    printf("Entry point: 0x%lx\n", (unsigned long)header->e_entry);
    printf("Program header offset: %ld (bytes into file)\n", (long)header->e_phoff);
    printf("Section header offset: %ld (bytes into file)\n", (long)header->e_shoff);
    printf("Flags: 0x%x\n", header->e_flags);

    printf("Elf header size: %zu \n", sizeof(*header)); //포인터로 설정 주의
    printf("Program header entry size: %d (bytes)\n", header->e_phentsize);
    printf("Program header enty count: %d\n", header->e_phnum);
    printf("Section header entry size: %d (bytes)\n", header->e_shentsize);
    printf("Section header entry count: %d\n", header->e_shnum);
    printf("Section header string table index: %d\n", header->e_shstrndx);
}

int main(int argc, char *argv[]) {
    if (argc != 2) { // 프로그램 이름과 elf 파일 경로를 필요로 하기때문에 2개의 명령줄 인수만 필요! 그외에는 처리x
        printf("명령줄 인수가 올바르지 않습니다: ");
        exit(1);
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("파일을 여는데 오류 발생. ");
        exit(1);
    }

    Elf64_Ehdr header;
    fread(&header, 1, sizeof(header), file);

    elfHeader(&header);

    fclose(file);
    return 0;
}
