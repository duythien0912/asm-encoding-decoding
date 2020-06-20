// gcc -g -m64 -o decode.o decode.c tv.o

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
extern char *en_code ();
extern char *de_code ();
int
main ()
{
  char textInFile[1024];

  //file input
  FILE *fptr;
  fptr = fopen ("myfile_encode.txt", "r");
  fscanf (fptr, "%[^EOF]", textInFile);
  fclose (fptr);

  //file save
  FILE *fptr_save;
  fptr_save = fopen ("myfile_decode.txt", "w+");

  int key[20] = { 1, 2, 3, 14, 3, 6, 7, 12 };
  int len_key_text = 8;
  int ikey = 0;

  for (int i = 0; i < strlen (textInFile); i++)
    {
      char n[5] = "";
      strncat (n, &textInFile[i], 2);
      //   fputs(en_code(n,key[ikey]), fptr_save);
      fputs (de_code (n, key[ikey]), fptr_save);
      //printf("%d \n", key[ikey]);
      ikey++;
      if (ikey >= len_key_text)
	ikey = 0;
      i++;
    }
  fclose (fptr_save);
}
