#include<stdio.h>
#include<string.h>
#include<stdlib.h>
extern char* en_code();
extern char* de_code();
int main()
{
	
	
	
	char textInFile[100];
	
	
	//file input
	FILE *fptr;
	fptr = fopen("myfile_encode.txt", "r");
   	fscanf(fptr,"%[^\n]", textInFile);
    	fclose(fptr);
	//file save
	FILE *fptr_save;
	fptr_save = fopen("myfile_decode.txt", "w+");
	
	int key[20] = {1,2,3,14}; 
	int len_key_text = 4;
	int ikey = 0;

	

	for(int i = 0; i < strlen(textInFile)-1; i++)
	{
		char n[5] ="";
		strncat(n, &textInFile[i], 2);
		fputs(en_code(n,key[ikey]), fptr_save);
		//fputs(de_code(n,key[ikey]), fptr_save);
		printf("%d \n", key[ikey]);

		ikey++;
		if(ikey >= len_key_text)
			ikey = 0;
		i++;
	}

	
   	
    	fclose(fptr_save);

	
}




