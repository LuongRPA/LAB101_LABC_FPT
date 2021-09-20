#include<stdio.h>
#include<conio.h>
#include<math.h>
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
		if(k != 2 || tmp != '\n' ) printf("%s",error);
		else if(n >= min && n <= max) break;
		else printf("%s",error);
	}while (1);
	return n;
}




void sumodd(int n, int a[]){
	int sumod=0;  
	for (int i=0; i<n; i++){
		if(a[i]%2==1)
			sumod+=a[i];
	}
	printf("\nSum of odd: %d",sumod);
}





void sumeven(int n, int a[]){
	int sumeve=0;
	for(int i=0; i<n; i++){
		if(a[i]%2==0){
			sumeve+=a[i];
		}
	}
	printf("\nSum of even: %d",sumeve);
}





int main(){
	printf("----------------Sum even odd program-----------------");
		while(1){
		int n = checkInt("\nEnter a number of element n=", "\n", 0, INT_MAX);
		int *a=(int*) malloc(n*sizeof(int));
			fflush(stdin);
		printf("Input elements: \n");
		for(int i=0; i<n; i++){
		printf("Element %d: ",i+1);
		scanf("%d",&a[i]);	
		printf("%d",a[0]);}
		
	sumeven(n,a);
	sumodd(n,a);
	return 0;

}
}

