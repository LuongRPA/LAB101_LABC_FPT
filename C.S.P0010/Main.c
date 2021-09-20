/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.c
 * Author: Admin
 *
 * Created on May 18, 2021, 3:14 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    printf("The Program must have interface as below: \n");
    int size = Validate("Please enter size of array :  ",1,10);
    int *array = (int*)malloc(size * sizeof(int));
  
    Input(size,array);
    Display(size,array);
    printf("\nThe array after removing duplicate elements:   "); 
   // Run(size, array);
    Duplicate(size, array);
    
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
    printf("\nThe original array : ");
    for(int i = 0; i < size ; i++){
        printf("  %d  ",array[i]);
    }
}

void Duplicate( int size, int array[]){
    for(int i = 0; i < size ; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(array[i] == array[j])
            {
                for(int t = j; t < size; t++)
                {
                  array[t] = array[t + 1];
                  
                }
                j = j-1;
                array = (int*) realloc(array, (size - 1) * sizeof (int));
                size = size - 1;
            }
        }
    }
    
    for(int i = 0; i < size ; i++){
        printf("  %d  ",array[i]); // re output
        
    }
}




