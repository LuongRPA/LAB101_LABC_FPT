#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int checkInt(char *mess,  char *error, int min, int max) {
	int n, k;
	char tmp, l;
	do {
		printf("%s",mess);
		fflush(stdin);
		k = scanf("%d%c",&n,&tmp);
		if(k != 2 ) printf("%s",error);
		else if(n >= min && n <= max) break;
		else printf("%s",error);
	}while (1);
	return n;
}


void bubble(int a[], int n) {
	for (int i = 0; i < n-1;i++){
        for (int j = i+1; j < n;j++){
            if (a[i]>a[j]) 
            {
                  int k = a[i];  
                  a[i] = a[j];  
                  a[j] = k;  
            }
        }
    }
}


int check(char c){
	printf("\n\n Do you want to continue? (Y/N) : ");
	fflush(stdin);
	 c = getchar();
		if(c == 89 || c == 121);
	 else if (c == 78 || c == 110)
	 {exit(c == 78 || c == 110);}
	else{
			check(c);
}
return 0;
}


///////////////////////////////////////////////////////////////////////////////////
void input (int &n, int a[]){

  for(int i=0;i<n;i++)
  { printf(" phan tu thu %d :",i);
  
    scanf("%d",&a[i]);
  }
}



///////////////////////////////////////////////////////////////////////////////////
void output(int n, int a[]){
	printf("mang da nhap \n");
  for(int i=0;i<n;i++)
    {
      printf(" %4d ",a[i]);
    }
}


///////////////////////////////////////////////////////////////////////////////////




void add(int a[], int n, int x){
	int temp;
	x =checkInt("\n nhap so can them: ", " again\n", 0, INT_MAX);
  		fflush(stdin);
  	n++;
  	a = (int*) realloc(a, n* sizeof(int));
  	
    for(int i = 0; i < n; i++){
        if(a[i] >= x){
        	temp=i;
        	break;
        }
        }
        for(int j = n; j > temp; j--){
                a[j] = a[j-1];
        }
        a[temp] = x;
		output(n,a);
}



/////////////////////////////////////////////////////////////////////////////////////
int main(){
	int i,j,k,x;
	int *a;
	char c;
	while(1){
		printf("\n The Program must have interface as below:\n\n");
		int n = checkInt("Please enter new value: ", "\n", 0, INT_MAX);
		a=(int*) malloc(n*sizeof(int));
			fflush(stdin);
		printf("\n");
	
		input(n,a);
		bubble(a,n);
		output(n,a);
	
	    add(a, n, x);
	
		check(c);
	
	}
	free(a);
}





