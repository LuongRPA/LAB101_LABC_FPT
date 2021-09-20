/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.c
 * Author: Admin
 *
 * Created on May 20, 2021, 1:03 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

/////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {
    printf("The Program must have interface as below:");
    
     Cal(); 
     
    return 0;
}
///////////////////////////////////////////////////////////////////
void Cal( ){
    // input matrix 1
      int **a,**b,**s,i,j,sum=0;
      int row = getInt("\nPlease enter row of matrix 1: ",INT_MIN,INT_MAX);
      int col = getInt("\nPlease enter col of matrix 1: ",INT_MIN,INT_MAX);
      
      a=(int **)malloc(row*sizeof(int*));
      for(i=0;i<row;i++)
      {
            a[i]=(int *)malloc(col*sizeof(int));
      }
      printf("\nEnter Elements for Matrix A of Size %d*%d:\n\n",row,col);
      for(i=0;i<row;i++)
      {
            for(int j=0;j<col;j++)
            {
                printf("\n Element [%d][%d]:  ", i+1,j+1);
                  scanf("%d",&a[i][j]);
            }
      }
      printf("\n%d*%d Matrix A: \n\n",row,col);
      for(i=0;i<row;i++)
      {
            for(j=0;j<col;j++)
            {
                  printf("%3d ",a[i][j]);
            }
      printf("\n");
      }
    
    //////////////////////////////////////////////////////////////////////
    // input matrix 2
    
     row = getInt("\nPlease enter row of matrix 2: ",INT_MIN,INT_MAX);
     col = getInt("\nPlease enter col of matrix 2: ",INT_MIN,INT_MAX);
      
      b=(int **)malloc(row*sizeof(int*));
      for(i=0;i<row;i++)
      {
            b[i]=(int *)malloc(col*sizeof(int));
      }
      printf("\nEnter Elements for Matrix B of Size %d*%d:\n\n",row,col);
      for(i=0;i<row;i++)
      {
            for(j=0;j<col;j++)
            {
                printf("\n Element [%d][%d]:  ", i+1,j+1);
                  scanf("%d: ",&b[i][j]);
            }
      }
      printf("\n%d*%d Matrix B : \n\n",row,col);
      for(i=0;i<row;i++)
      {
            for(j=0;j<col;j++)
            {
                  printf("%3d ",b[i][j]);
            }
      printf("\n");
      }
    
     ///////////////////////////////////////////////////////////////////////// 
      // matrix sum 
      
    s =(int **)malloc(row*sizeof(int*));
      for(i=0;i<row;i++)
      {
            s[i]=(int *)malloc(col*sizeof(int));
      }
    printf("\nSum of two Matrix A and B %d*%d:\n\n",row,col);
      for(i=0;i<row;i++)
      {
            for(j=0;j<col;j++)
            {
               s[i][j] = a[i][j] + b[i][j];   
            }
      }
    printf("\n%d*%d Matrix sum of two matrix A and B: \n\n",row,col);
      for(i=0;i<row;i++)
      {
            for(j=0;j<col;j++)
            {
                  printf("%3d ",s[i][j]);
            }
      printf("\n");
      }  
    
}
