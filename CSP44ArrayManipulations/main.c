/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on July 13, 2021, 3:18 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
#include<stdio.h>
#include<stdlib.h>
// function 1

int* add_a_value(int *arr, int n) {
    int value = 0;
    printf("Enter a value: ");
    scanf("%d", &value);
    arr = (int*) realloc(arr, (n + 1) * sizeof (int));
    arr[n] = value;
    n++;
    return arr;
}

// function 2 

int findIndex(int a[], int n, int value) {
    int check = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == value) {
            return i;
        }
    }
}

// function 3

void display_array(int a[], int n) {
    printf("\nThe array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d  ", a[i]);
    }
    printf("\n\n");
}

//function 4 

int* getValueInRange(int a[], int n, int minValue, int maxValue, int pCount) {
    int *b = (int*) malloc(100 * sizeof (int));
    int j = 0;
    pCount = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= maxValue && a[i] >= minValue) {
            b[j] = a[i];
            j++;
            pCount++;
        }
    }
    return b;
}

// function 5

int* array_sorted_in_ascending(int arr[], int n) {
    int tg;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                tg = arr[i];
                arr[i] = arr[j];
                arr[j] = tg;
            }
        }
    }
    return arr;
}

int main() {
    int value, value1, key, minValue, maxValue;
    int n = 0, pos = 0, x;
    int count = 0;
    int *a = (int*) malloc(n * sizeof (int));
    int *p;
    while (1) {
        int key, check = 0;
        char character;
        printf("\n1- Add a value\n");
        printf("2- Search a value\n");
        printf("3- Print out the array\n");
        printf("4- Print out values in a range of inputted min and max values, inclusively.\n");
        printf("5- Sort the array in ascending order\n");
        printf("6- Quit\n");
        printf("Choose the menu: ");
        fflush(stdin);
        //fpurge(stdin);
        check = scanf("%d%c", &key, &character);
        if (check == 2 && character == '\n') {

            switch (key) {
                case 1:

                    if (n > 100) {
                        printf("Full,Array only allow 100 element ! ");
                        break;
                    }
                    a = add_a_value(a, n);
                    break;
                case 2:
                    printf("	Enter a value you want to search: ");
                    scanf("%d", &value1);
                    x = findIndex(a, n, value1);
                    if (x == -1) {
                        printf("	==>The value not exist in the array\n");
                    } else {
                        printf("	==> The value exist in the array\n");
                        printf("	The Index is: %d\n", x);
                    }
                    break;
                case 3:
                    display_array(a, n);
                    break;
                case 4:
                    printf("Enter min value: ");
                    scanf("%d", &minValue);
                    printf("Enter max value: ");
                    scanf("%d", &maxValue);
                    p = getValueInRange(a, n, minValue, maxValue, count);
                    display_array(p, count);
                    break;
                case 5:
                    a = array_sorted_in_ascending(a, n);
                    break;
                default:
                    exit(0);
            }
        }
        else {
            printf("Please choose number of menu!\n");
        }
    }
    free(a);
    free(p);
    return 0;
}

