/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.c
 * Author: Admin
 *
 * Created on May 18, 2021, 11:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 
 */
int main(int argc, char** argv) {
printf("The Program must have interface as below:\n");
    int *array;
    int size = Validate("Please enter number of terms: ",0,100); ///n < 100
    array = (int*)malloc(size * sizeof(int));
    
    Input(size,array);
    
    Run(size,array);
    
    
    return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////

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



/////////////////////////////////////////////////////////////////////////////
//input 
void Input(int size, int array[]){
    for(int i = 0; i<size ; i++){
         printf("\n Element [%d]:  ", i+1);
       array[i]= CheckSquare();  
    }
}


///////////////////////////////////////////////////////////////////////////
//Sum 
void Run(int size, int array[]){
    int sum = 0;
    for(int i = 0; i< size; i++){
      sum += array[i];  
}
    printf("Total : %d", sum);
}

 
///////////////////////////////////////////////////////////////////////////
// square number
int isPerfectSquare(int x)
{
    int s = sqrt(x);
    if(s*s == x)
        return 1;
    else
        return 0;
}
 
/////////////////////////////////////////////////////////////////////////////
// check input is square 
int CheckSquare(){
  int num;
    do{
        num = Validate(" ",0,100);///n < 100
        if(isPerfectSquare(num))
        return num;
    else
    printf("Please enter spare number: ");
    }while(1);
    
  return num;  

}
