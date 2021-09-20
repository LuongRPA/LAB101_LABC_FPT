/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.c
 * Author: Admin
 *
 * Created on May 11, 2021, 1:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 
 */

int main(int argc, char** argv) {
    printf("Program\n");
    int size = Validate(" Enter size of array : ",1,10);
    int *array;
    array = (int*)malloc(size * sizeof(int));
    Input(size,array);
    Display(size,array);
    Max(size,array);
    Even(size,array);
    free(array);
    return (EXIT_SUCCESS);
}

int Validate(char *msg, int min , int max){
    int num;
    char c;
    printf("%s",msg);
    do{
       __fpurge(stdin);
        int  check = scanf("%d%c",&num,&c);
        if( check == 2&& c =='\n'){
            if(check > min && check <= max )
                return num ;
            else 
                printf("Please enter number from %d to %d", min , max);
            
        }
        else {
            printf("Enter error , please  input a number :");
        }
    }while(1);
      return num;      
    
}

void Input(int size, int array[]){
    printf("Input element: ");
    for(int i = 0; i<size ; i++){
        printf("\n Element [%d]:  ", i+1);
        scanf("%d",&array[i]);
    }
}

/*

*/
void Display(int size, int array[]){
    printf("\n Array elements : ");
    for(int i = 0; i < size ; i++){
        printf("\n%d ",array[i]);
    }
}

void Max(int size , int array[]){
    int max = array[0];
   
    for( int i = 0; i< size ; i++){
        if(array[i] > max){
             max = array[i];
             
            
        }
        
    }
    printf("\n Max of array is : %d", max); 
}
 
void Even(int size, int array[]){
    for( int i = 0; i< size; i++){
        if(array[i] % 2 == 1){
         printf("\n Even element : \n %d ", array[i]);   
        }
    }
}