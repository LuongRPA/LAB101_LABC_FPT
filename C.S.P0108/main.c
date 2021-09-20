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
#include <limits.h>

/*
 * 
 */
int getInt(char*Msg, int Min, int Max) {
    char ch;
    int Number, check;
    do {
        printf("%s", Msg);
        fflush(stdin);
        check = scanf("%d%c", &Number, &ch); // number and character
        if (check == 2 && ch == '\n') { // 
            if (Number >= Min && Number <= Max) {
                return Number;
            } else {
                printf("Out of range, Enter number in [%d, %d]\n", Min, Max);
            }
        } else {
            printf("Invalid input,try again! Enter number <= %d\n", Max);
        }
    } while (1);
}

int main(int argc, char** argv) {
    
    printf("The Program must have interface as below:");
    do{
        
    int size = getInt("\nPlease enter size of array:",INT_MIN,INT_MAX);
    int *array;
    array = (int*)malloc(size * sizeof(int));
     //Enter  array
    Input(size, array);
    
    //Output array
    printf("\nNew array: ");
    Output(size, array);
    
    // Find letters corresponding 
    printf("\nFind letters corresponding to the integer equivalent of letter\n");
    Find(size,array);
    
    // free memory
    free(array);
    printf("Press Enter to continue\n");
    char c = getchar();
    }while(1);
    return 0;
}

void Input(int size, int array[]){
    for (int i = 1; i <= size; i++) {
       
        array[i] = rand()%256; // random element and limit smaller than 256 
        // max of ASCII is 255
    }
}

void Output(int size, int array[]){
    for (int i = 1; i <= size; i++) {
        printf("\n[%d] =", i);
    	printf("%d\t", array[i]);
	}
	printf("\n");
}

void Find(int size, int array[]){
    for (int i = 1; i <= size; i++) {
        printf("\n[%d] = %c", i,array[i]); ///%d in  ASC II is %c
    	
	}
	printf("\n");
}