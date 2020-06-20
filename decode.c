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

  //đọc file txt có tên myfile_encode.txt và lưu nội dung đọc được vào biến textInFile
  FILE *fptr;
  fptr = fopen ("myfile_encode.txt", "r");
  fscanf (fptr, "%[^EOF]", textInFile);
  fclose (fptr);

  //mở file lưu kết quả decode có tên myfile_decode.txt
  FILE *fptr_save;
  fptr_save = fopen ("myfile_decode.txt", "w+");
  //khởi tạo key có 8 giá trị
  int key[20] = { 1, 2, 3, 14, 3, 6, 7, 12 };
  //biến len_key_text lưu đọ dài key và ở đây là 8
  int len_key_text = 8;
  //biến ikey dùng để định vị khi chạy vòng lặp ta đã dùng đến key thứ mấy để decode
  int ikey = 0;

  //vòng lặp lấy từng cặp ký tự truyền vào function assembly để decode 
  //có số vòng chạy là một nữa chiều dài ký tự của file truyền vào vì ta đọc từng cặp ký tự
  for (int i = 0; i < strlen (textInFile); i++)
    {
      //biến n dùng để lưu từng cặp ký tự lấy ra từ biến textInFile
      char n[5] = "";
      //strcat lấy hai ký tự trong biến textInFile kể từ ký tự thứ i cho vào biến n
      strncat (n, &textInFile[i], 2);
      //function de_code được gọi từ assebly code nhận 2 ký tự (cặp ký tự cần xoay) và 1 số(số bit xoay là một giá trị key)
      //lưu hai ký tự decode vào fptr_save tức là file lưu kết quả decode myfile_decode.txt
      fputs (de_code (n, key[ikey]), fptr_save);
      //ikey tằng lên 1 tức là sẽ lấy giá trị key típ theo ở vòng lặp sau
      ikey++;
      //if nếu giá trị key hiện tại lớn hơn độ dày chuổi key thì lấy lại giá trị key đầu tiên  
      if (ikey >= len_key_text)
	        ikey = 0;
      // cho i tăng lên 1 để bỏ qua 1 giá trị vì chương trình đọc từng cặp ký tự
      i++;
    }
  //đóng file lưu kết quả decode
  fclose (fptr_save);
}
