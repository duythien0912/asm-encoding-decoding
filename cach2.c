// rm -rf 1_encode.png && rm -rf 1_decode.png && nasm -g -f elf64 tv.asm -l ror.lst -o ror.o && gcc -g -m64 -o test ./cach2.c ror.o && ./test 1.png 1_encode.png 1_decode.png 1

// rm -rf myfile_encode.txt && rm -rf myfile_decode.txt && nasm -g -f elf64 tv.asm -l ror.lst -o ror.o && gcc -g -m64 -o test ./cach2.c ror.o && ./test myfile.txt myfile_encode.txt myfile_decode.txt 1

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *en_code ();
extern char *de_code ();

#define ROR(x, r) ((x >> r) | (x << (64 - r)))
#define ROL(x, r) ((x << r) | (x >> (64 - r)))

int
main (int args, char *argv[])
{
  char key = argv[4][0];

  FILE *file_input;
  FILE *file_encode;
  file_input = fopen (argv[1], "r, ccs=UTF-8");
  file_encode = fopen (argv[2], "w+");

  while (1)
    {
      // char ch;
      // fscanf (file_input, "%c", &ch);

      char char_inputarr [1024] = {0};
      fscanf (file_input, "%c", char_inputarr);
      // fread(char_inputarr, sizeof(char_inputarr), 1, file_input); 

      if (feof (file_input)) { break; }
      // printf ("%s", char_inputarr);
      
      // printf ("\n");

      // printf ("%s", char_inputarr);
      fputs (" ", file_encode);
      fputs (en_code (char_inputarr, key), file_encode);
    }

  fclose (file_input);
  fclose (file_encode);
  printf ("\n");
  // return 0;

  FILE *file_encode_read;
  FILE *file_decode;
  file_encode_read = fopen (argv[2], "r");
  file_decode = fopen (argv[3], "w+");

  while (1)
    {
      if (feof (file_encode_read)) { break; }
      char char_encodearr [1024] = {0};
      fscanf (file_encode_read, "%s", char_encodearr);
      // fread(char_encodearr, sizeof(char_encodearr), 1, file_encode_read); 

      fputs (de_code (char_encodearr, key), file_decode);
    }

  fclose (file_encode_read);
  fclose (file_decode);
  printf ("\n");

  return 0;
}
