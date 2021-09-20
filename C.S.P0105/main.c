/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on August 3, 2021, 9:14 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char s[100];
    gets(s);
    reverse(s);
    printf("%s",s);	
    return (0);
}
///////////////////////////////////////////////////////////////////////////
// reverse
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


