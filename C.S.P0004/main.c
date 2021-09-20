/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on August 5, 2021, 4:23 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void countLetters(char *c) {
    int i;
    int size = strlen(c);
    int b[97+26] = {0};
    for(i = 0; i< size; i++){
        char w = tolower(c[i]);
        b[w]++;
    }
    for(i = 97; i< 123; i++){
        if(b[i]> 0){
        printf("%c: %d\n", (char)i, b[i]);
        }
        int max = b[0];
        if(b[i]> b[0]){
            b[i]= max;
            printf("%c : %d \n", (char)i,max);
        }
  }
}

void countLettersA(char *c) {
    int i;
    int size = strlen(c);
    int b[97+26] = {0};
    for(i = 0; i< size; i++){
        b[c[i]]++;
    }
    for(i = 65; i< 91; i++){
        if(b[i]> 0)
        printf("%c: %d\n", (char)i, b[i]);
    }
    for(i = 97; i< 123; i++){
        if(b[i]> 0)
        printf("%c: %d\n", (char)i, b[i]);
    }
}

int main(int argc, char** argv) {
    printf("The Program must have interface as below:");
    printf("\nPlease enter string: ");
    char x[100];
    fgets(x, 99, stdin);

    puts("\nTimes of appearance for each characterA: ");
    countLettersA(x);
    printf("\n\n");

    puts("\nTimes of appearance for each character ");
    countLetters(x);

    return 0;
    
}

