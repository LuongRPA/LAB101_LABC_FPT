/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on August 4, 2021, 7:11 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
/*
 * 
 */
int main(int argc, char** argv) {
    printf("The Program must have interface as below:");
    printf("\nPlease enter main string: ");
    char str[100];
	fgets(str, 99, stdin); //read string STR  , max length 100, 
        
    printf("Please enter substring: ");
    char sub[100];
        fgets(sub, 99, stdin); //read string SUB  , max length 100, 
        
        
        Find(str,sub);
	
        
   return 0;
}


///////////////////////////////////////////////////////////////////////////////
//find location
int Find(char *str, char *sub) {
   char *rs = strstr(str, sub);
	if(rs!=NULL){
		printf("Tim thay chuoi con!");
		printf("\n");
		printf("%s", rs);
	}else{
		printf("Khong tim thay chuoi con!");
	}
}

