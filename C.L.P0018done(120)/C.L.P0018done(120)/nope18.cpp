#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <dirent.h>
#include<stdlib.h>



//check I/O
int checkInp(char *mess,  char *error, int min, int max) {
	int n, k;
	char tmp;
	do {
		printf("%s",mess);	
		fflush(stdin);
		k = scanf("%d%c",&n,&tmp);
		if(k != 2 || tmp != '\n' ) printf("%s",error);
		else if(n >= min && n <= max) break;
		else printf("%s",error);
	}while (1);
	return n;
}



//doc toan bo file
void read(){
	fflush(stdin);
	FILE *f;
	int len=500,c;
	char *save;
	
	save = (char *)malloc(len* sizeof(char));
	fflush(stdin);

	
	printf("Enter file name: ");
	gets(save);
	
	
	len=(strlen(save));
	
	save = (char*) realloc(save, len * sizeof(char));
	fflush(stdin);
	
	
	if(strlen(save)>255)
	
	{
		printf("out range %d", strlen(save));
		return;
	}
	
	f=fopen(save,"r");
	if (f==NULL){
	printf("This file is not exist!\n");
	}
	
 while(1)
   {
      c = fgetc(f);
      if( feof(f) )
      {
         break;
      }
      printf("%c", c);
   }
	fclose(f);
	free(save);
	
}




//dung fputs de ghi file khong nhan gia tri null
void copy(){
	fflush(stdin);
	FILE *f1,*f2;
	char buffer;
	int len=500;
	char *file1,*file2;
	
	file1 = (char *)malloc(len* sizeof(char));
	file2 = (char *)malloc(len* sizeof(char));
	fflush(stdin);
	
	printf("Enter file name to copy: ");
	gets(file1);
	
	len=(strlen(file1));
	
	file1 = (char*) realloc(file2, len * sizeof(char));
	fflush(stdin);

	
	if(strlen(file1)>255)
	{
		printf("out range %d", strlen(file1));	
		return;
		
	}
	
	  
	if (!f1){
	printf("This file is not exist!");
	return;
	}
	
	printf("Enter target file: ");
	gets(file2);
	
	len=(strlen(file2));
	
	file2 = (char*) realloc(file2, len * sizeof(char));
	fflush(stdin);
	
	
	if(strlen(file2)>255)
	{
		printf("out range %d", strlen(file2));
	}
	
	f2=fopen(file2,"w");
	while((buffer=fgetc(f1)) != EOF){
	fputc(buffer,f2);
	}
	printf("Copied!");
	fclose(f1);
	fclose(f2);
	
	free(file1);
	free(file2);
}



//ghep 2 file 
void merge(){
	fflush(stdin);
	FILE * f1,*f2,*f3;
	char buffer,*file1,*file2,*result;
	int len=255;
	
	
	file1 = (char *)malloc(len* sizeof(char));
	file2 = (char *)malloc(len* sizeof(char));
	result = (char *)malloc(len* sizeof(char));
	fflush(stdin);
	
	
	printf("Enter name of first file: ");
	gets(file1);
	
	len=(strlen(file1));
	
	file1 = (char*) realloc(file1, len * sizeof(char));
	fflush(stdin);
	
	
	if(strlen(file1)>255)
	{
		printf("out range %d", strlen(file2));
	}
	
	
	
	
	printf("Enter name of second file:");
	gets(file2);
	
	
	len=(strlen(file2));
	
	file2 = (char*) realloc(file2, len * sizeof(char));
	fflush(stdin);
	
	
	if(strlen(file2)>255)
	{
		printf("out range %d", strlen(file2));
	}
	
	
	
	printf("Enter the name of file which will store contents of two files: ");
	gets(result);
	
	
	len=(strlen(result));
	
	result = (char*) realloc(result, len * sizeof(char));
	fflush(stdin);
	
	
	if(strlen(result)>255)
	{
		printf("out range %d", strlen(file2));
	}
	
	
	
	f1=fopen(file1,"r");
	f2=fopen(file2,"r");
	if (!f1 || !f2){
	printf("This file is not exist!");
	return;
	}
	f3=fopen(result,"a");
	while ((buffer=fgetc(f1))!=EOF)
	{
	fputc(buffer,f3);
	}
	while((buffer=fgetc(f2))!=EOF)
	{
	fputc(buffer,f3);
	}
	printf("Merged!");
	fclose(f1);
	fclose(f2);
	fclose(f3);
	
	free(file1);
	free(file2);
	free(result);
}





//in ra danh sach file
void list(){
	fflush(stdin);
	DIR *f;
	struct dirent *dir;
	f= opendir(".");
	while ((dir= readdir(f))!= NULL){
		
		printf("%d\n", dir->d_ino);

	}
	closedir(f);
}





//dùng remove de xoa file name va khong truy cap vao duoc nua
void remove(){
	char save[255];
	fflush(stdin);
	printf("Enter the name of file you wish to delete: ");
	gets(save);
            if (remove(save) == 0)
                printf("Deleted!");
            else
                printf("This file is not exist!");
}


int main (){

	while(1){
		
		printf("\nMenu\n");
		
		printf("\n1-Read file\n");
		printf("2-Copy file\n");
		printf("3-Merge two files\n");
		printf("4-List file in a directory\n");
		printf("5-Delete file\n");
		printf("6-Exit\n");
		printf("Enter your choice: ");
		
		int	opt = checkInp("Enter opt 1-6: ","\nYou can only enter the number: 1-6, Pls enter again\n", 1, 6);
		
		
		switch (opt){
		case 1: read(); 
				break;
		case 2:	copy();
				break;
		case 3: merge(); 
				break;
		case 4: list(); 
				break;
		case 5: remove(); 
				break;
		case 6: printf("Exited!");
				exit(0);
				
		}
	}
}

