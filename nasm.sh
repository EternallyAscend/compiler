#/bin/bash
nasm -f elf ass.asm -o assembly.o
gcc -m32 assembly.o -o final
./final ; echo $?
rm assembly.o -f
