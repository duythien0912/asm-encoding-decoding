# Project #5

### Given an encoding scheme:

![schema](https://scontent.fsgn5-6.fna.fbcdn.net/v/t1.15752-9/104356443_3298968110136791_5271451598992830385_n.png?_nc_cat=109&_nc_sid=b96e70&_nc_ohc=_MHq3Y03JpkAX9odKbT&_nc_ht=scontent.fsgn5-6.fna&oh=f118361ec8a1e48c4ceb7bbd3d954f51&oe=5F0F796A "schema")

### Develop encoding / decoding functions in assembly, write C program to encode a file, use a decoding function to check the encoding functionality. Compare the time taken to encode/decode a large file in C and Assembly language.


# Run this project 
This project running on Ubuntu 16.04.6 LTS (Xenial Xerus) 64bit

*The command line may require adjusting for other models*

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/UFLJdTyGTCU/0.jpg)](https://www.youtube.com/watch?v=UFLJdTyGTCU)


### Tutorial:
Build object and list of data file from assembly file
```bash
nasm -g -f elf64 tv.asm -l tv.lst
```

Create object file result.o from assembly file tv.o and c.c file
```bash
gcc -g -m64 -o result.o c.c tv.o
```

Run file and check result
```bash
./result.o
```
