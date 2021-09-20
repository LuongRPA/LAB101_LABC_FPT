/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on May 18, 2021, 10:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 
 */

int main(int argc, char** argv) {
    printf("The Program must have interface as below:\n");
    do{
        
    int number = Validate("Please enter a number you want to check: ",INT_MIN,INT_MAX);
    Runn(number);
    printf("Press Enter to continue\n");
    char c = getchar();
    }while(1);
    return 0;
    
}

///////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////

int Run(int number){
    int istrue = 0;
for(int i = 0; i <= number/2; i++){ // 

    if (CheckPrime(i) == 1)
    {
        if (CheckPrime(number-i) == 1)
        {   
            istrue = 1;
            printf("\n%d = %d + %d\n\n", number, i, number - i);
            
        }
        
    }
    
}

if (istrue == 0)
printf("%d cannot be expressed as the sum of two prime numbers\n", number);

return 0;
}

int Runn(int number){
  
for(int i = 0; i <= number/2; i++){ // 

    if (CheckPrime(i) == 1 && CheckPrime(number-i) == 1)
    {
        
            printf("\n%d = %d + %d\n\n", number, i, number - i);
            
        }
    else{
    printf("%d cannot be expressed as the sum of two prime numbers\n", number);
    }
    }
    

return 0;
}

/////////////////////////////////////////////////////////////////////////////
//check prime number
int CheckPrime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

