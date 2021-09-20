#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


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




bool checkPrime(int n){
	if(n<2) return false;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0)	return false;
	}
	return true;
}



bool isPerfectSquare(int x){
	int s=sqrt(x);
	return (s*s==x);
}




void firstprimes(){
	int num,i=2,count=0;
	do{
		printf("Number of primes:");
		scanf("%d",&num);
		if(num<0||num>50){
			printf("Re-input:");
			scanf("%d",&num);
		} 
	}while(num<=0||num>50);
	while(1){
		if(checkPrime(i)) {
			printf("%d ",i);
			printf("\n"); count++;
			if(count==num) return;
				}i++;
			}
}


void fibona(){
	int n;
	bool check=false;
	do{
		printf("Number tested:");
		scanf("%d",&n);
		if(n<0||n>1000) printf("Re-input");
	}while(n<0||n>1000);
	if(isPerfectSquare(5*n*n+4)||isPerfectSquare(5*n*n-4)) check=true;
	if(check==true) printf("true\n");
	else printf("false\n");
}





void sumdigit(){
	int sum=0,n,i;
	n = checkInp("Enter an integer: ","\nYou can only enter the number positive integer, Pls enter again\n", 0, INT_MAX);

	
	while(n!=0){
		i=n%10; 
		n=n/10;
		sum+=i;
	}
	printf("Sum of it's digits:%d\n",sum);
}

int main(){
	while(1){
	
		printf("1 - The first primes\n");
		printf("2 - Fibonacci element\n");
		printf("3 - Sum of digits\n");
		printf("4 - Exit! \n");
		printf("Choosen an option:");
		
		int	opt = checkInp("Enter opt 1-6: ","\nYou can only enter the number: 1-6, Pls enter again\n", 1, 4);
		switch(opt){
		
			case 1: firstprimes(); break;
			case 2: fibona(); break;
			case 3: sumdigit(); break;
			case 4: exit(0);
		}
}

}
