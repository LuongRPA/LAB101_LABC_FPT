/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:    Main.c
 * Author: Admin
 *
 * Created on June 15, 2021, 1:10 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include<string.h>
/*
 * 
 */
int main(int argc, char** argv) {

 char strSource [200],strReverse[200], strClone [200], sTemple[10]; 
 int i, posCurrent;
printf("\nEnter a string you want: ");
gets(strSource);
//clone original string 
strcpy(strClone, strSource);
strcpy(strReverse, "");// reset strReverse 
for (i=strlen(strClone)-1;i>0; i--) { 
    
if(strClone[i]==32) {
    // space
posCurrent=i+1; 
strcpy(sTemple, &strClone[posCurrent]); // get one word 
strcat(strReverse, sTemple); 
strcat(strReverse," "); // add one space 
strClone[i]=0;// end of string at i
   }
}
// one word at last (beginning)
strcat(strReverse, strClone); //print result
printf("\nThe string after reversing is: \n%s", strReverse);
return 0 ;

}
