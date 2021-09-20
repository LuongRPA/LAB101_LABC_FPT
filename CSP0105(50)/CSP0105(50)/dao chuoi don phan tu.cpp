#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




void reverse(char s[]) {
	char c;
	int i;
	for(i= 0; i<= strlen(s)/2; i++) {
		c =s[strlen(s)-i-1];
		s[strlen(s)-i-1]= s[i];
		s[i]=c;
	}
	s[strlen(s)]=0;
	}


int main() {
	char s[100];
	gets(s);
  
	reverse(s);
	printf("%s",s);

	return 0;
}

