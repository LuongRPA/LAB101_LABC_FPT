/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on August 3, 2021, 6:45 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * 
 */
int main(int argc, char** argv) {
    printf("The Program must have interface as below:");
    printf("\nPlease enter any string: ");
    char str[100];
	fgets(str, 99, stdin); //read string STR  , max length 100, 
	int len = 0;
	int pos = Find(str, &len);
	Display(str, pos, len);
	return 0;
}

////////////////////////////////////////////////////////////////////////
//check space

int Space(char c) { // space
	return c == ' ' || c == '\t' || c == '\n';
}

//////////////////////////////////////////////////////////////////////////////
//output
void Display(char *str, int pos, int length) {
	printf("The longest substring: \'");
	int i;
	for(i = pos; i < pos + length; i++) {
		printf("%c", str[i]);
	}
	printf("\'\nLength of Longest subString : [%d]\nLocation in String: %d", length, pos);
}

///////////////////////////////////////////////////////////////////////////////
//find max length
int Find(char* str, int* length) {
	int len = 0;
	int lenMax = 0; /// max
	int pos = 0;
	int posCurrent = 0; /// location
	int size = strlen(str);
	int i;
	for(i = 0; i< size; i++) {
		if(!Space(str[i])) { 
			posCurrent = i - len;
			len++;
		} else {
			if(len > lenMax) {
				lenMax = len;
				pos = posCurrent;
			}
			len = 0;
		}
	}
	
	*length = lenMax;
	return pos;
}

