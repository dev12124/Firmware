@echo off
set CC=clang
set LD=ld.lld
set CFLAGS=--target=x86_64-elf -ffreestanding -fno-builtin -Wall -Wextra -fno-exceptions -fno-rtti -mno-red-zone -nostdlib -I.
set LDFLAGS=-m elf_x86_64 -T linker.ld

%CC% %CFLAGS% -c IMAGE_BIOS_PDD.c -o IMAGE_BIOS_PDD.o && %LD% %LDFLAGS% IMAGE_BIOS_PDD.o -o IMAGE_BIOS_PDD.exe
    echo sucessfully generated!