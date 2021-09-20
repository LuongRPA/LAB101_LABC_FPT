/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.c
 * Author: Admin
 *
 * Created on May 27, 2021, 2:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int getInt(char*Msg, int Min, int Max) {
    char ch;
    int Number, check;
    do {
        printf("%s", Msg);
        fflush(stdin);
        check = scanf("%d%c", &Number, &ch);
        if (check == 2 && ch == '\n') {
            if (Number >= Min && Number <= Max) {
                return Number;
            } else {
                printf("Out of range, Enter number [%d, %d]\n", Min, Max);
            }
        } else {
            printf("Invalid input,try again! Enter number [%d, %d]\n", Min, Max);
        }
    } while (1);
}

//out n number prime
int isPrime(int n) {
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

void displayPrime() {
    printf("\n");
    int n;
    n = getInt("Number of primes:", 0, 50); // which is 0 < n <= 50
    int count = 0;
    int i = 1;
    while (count < n) {
        i++;
        if (isPrime(i) == 1) {
            printf("%d  ", i);
            count++;
        }
    }
    printf("\n");
}

//Check Fibonacci number
int isPerfectSquare(int x)
{
    int s = sqrt(x);
    if(s*s == x)
        return 1;
    else
        return 0;
}
 
void isFibonacci()
{
    int n = getInt("Enter number : ",0,1000); // which is 0 < n <= 1000
    if(isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4)) // a Fibonacci has 5n+-4 is square
        printf("%d is Fibonacci", n);
    else
        printf("%d is not Fibonacci", n);
}



//sum of digits
void getSum() {
    printf("\n");
    int n = getInt("Enter an integer:", 0, INT_MAX); // check scanner is natural number 
    
/*
 * //if scanner n < 0 ( integer)
    if (n < 0) {
        n = n*-1;
    }
*/

    int sum = 0;
    while(n > 0){
        int digit = n%10;
        n = n/10;
        sum += digit;
    }
        printf("Sum Digit: %d", sum);
    
    printf("\n");
}

int main(int argc, char** argv) {
    do {
        printf("Basic Computation Practice\n");
        printf("1-The first primes\n");
        printf("2-Fibonacci element\n");
        printf("3-Sum of digits\n");
        printf("Choose an option: ");
        int n = getInt("", 1, 3); 
        switch (n) {
            case 1:
                displayPrime();
                printf("\n");
                break;
            case 2:
                isFibonacci();
                printf("\n");
                break;
            case 3:
                getSum();
                printf("\n");
                break;
        }
    } while (1);
    return (EXIT_SUCCESS);
}