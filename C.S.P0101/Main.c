/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.c
 * Author: Admin
 *
 * Created on May 18, 2021, 1:13 PM
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
void Input(int size, int array[]){
    for (int i = 1; i <= size; i++) {
       // printf("Element[%d] =", i);
       // array[i] = getInt("", INT_MIN, INT_MAX);
        //array[i] = rand()%100; random limit value is 100
        array[i] = rand(); // random  values element of R (real array)
    }
}

void Output(int size, int array[]){
    for (int i = 1; i <= size; i++) {
    	printf("%d\t", array[i]);
	}
	printf("\n");
}

void Swap(int size, int array[]){
     //enter index  want to swap
    int a;
    int b;
    printf("Swap two elements: \n");
    a = getInt("", 1, size); // index1
    b = getInt("", 1, size); // index2
   
    printf("\n");
    // swap 2 elements X & Y by sum(+) and sub(-)
    // array[a] is X, array[y] is Y
    array[a] = array[a] + array[b];  //x= sum (x+y)    
    array[b] = array[a] - array[b];  //y= sub (x-y) = x <-> (x+y) - y = x 
    array[a] = array[a] - array[b];  //x= sum - sub = y <-> (x+y)-(x-y) = y
       
    //re - output
    printf("Array after swapping:\n");
    for (int i = 1; i <= size; i++) { //re out
    	printf("%d\t", array[i]);
	}
}
int main(int argc, char** argv) {
    int size = getInt("Please enter size of array: ",INT_MIN,INT_MAX);
    int *array = (int*)malloc(size * sizeof(int));
    //Enter  array
    Input(size, array);
    
    //Output array
    Output(size, array);
	
   // Swap
    Swap(size,array);
    free(array);
    return 0;
}