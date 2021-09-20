/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.c
 * Author: Admin
 *
 * Created on May 17, 2021, 8:58 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
printf("Program\n");
    printf("Enter size of array : ");
    int size = Validate(" ",1,10);
    int *array;
    array = (int*)malloc(size * sizeof(int));
    Input(size,array);
    Display(size,array);
    Sum(size, array);
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

void Display(int size, int array[]){
    printf("Array elements : ");
    for(int i = 0; i < size ; i++){
        printf("\n%d ",array[i]);
    }
}

void Sum(int size, int array[]){
    int sumodd = 0;
    int sumeven = 0;
    for(int i = 0; i< size; i++){
        if(array[i]%2 == 1){
            sumodd +=array[i]; 
        }
        else{
            sumeven +=array[i];
        }
                
    }
    printf("\nSum of even = %d\n", sumeven);
    printf("\nSum of odd = %d\n", sumodd);
    
}