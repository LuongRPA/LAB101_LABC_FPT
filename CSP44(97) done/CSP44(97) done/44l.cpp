#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>

#define INT_MIN 0 

int getInt(int min, int max){
	int value;
	char check;//42a
	do{
		int rc = scanf("%d%c", &value, &check);		
		fflush(stdin);
		if (rc != 2 || check != '\n')
			printf("Invalid value!!!\n");
		else if (value < min || value > max)
			printf("Value out of range !\n");
		else {
			return value; // break out function
		}	
	}while(1);
}




void allocMemory(int **arr, int *size) {
        if (*arr==NULL) {
        *size = 0;
        (*size)++;
        *arr =(int*) malloc(*size * sizeof (int));
        return;
    }
    
      //if not null, them realloc it
     
    *arr =(int*) realloc(*arr, *size * sizeof (int));
}

void addToLast(int *arr, int size) {
	int number;
    printf("Enter a valuea [%d] : ", size-1);
    number = getInt(INT_MIN, INT_MAX);
    
 
    arr[size - 1] = number;
}
 

void addValue(int **arr, int *size) {
    (*size)++;
    allocMemory(arr, size);
    addToLast(*arr, *size);
}









void search(int *arr, int size, int value){
	int index = -1;
	for (int i = 0; i < size; i++){
		if (arr[i] == value){
			printf("Index arr[%d]: %d\n", i, arr[i]);
			index = i;
		}
	}
	if (index == -1){
		printf("Can not find a value %d in the array !", value);
	}
}








void displayArray(int *arr, int size){
	for(int i = 0; i < size; i++){
		printf("a[%d] = %d\n", i, arr[i]);
	}
}





void print_ValueInARange(int *arr, int size){
	int	temp, temp1, i;
	printf("Input Min value & Max Value of Range: \n");
	printf("value of Range: ");
	int minRange = getInt(INT_MIN, INT_MAX);
	printf("value of Range: ");
	int maxRange = getInt(INT_MIN, INT_MAX);
		for(int i = 0; i < size; i++)
		  
		{  	if(arr[i] == minRange )
				temp=i;
			if(arr[i]== maxRange)
				temp1=i;		
			}
		
		
		
		if (minRange<= maxRange){
			for (int i=temp; i<=temp1; i++)
				printf("arr[%d] = %d\n", i, arr[i]);
				 
	}	else if(minRange > maxRange) {
			for (int i=temp1; i<=temp;i++)
				printf("arr[%d] = %d\n", i, arr[i]);
	}					
}








void sortAscending(int *arr, int size){
	int temp;
	for (int i = 0; i < size - 1; i++){
		for (int j = i + 1; j < size; j++){
			if (arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}



int mainMenu(){
	printf("\n===========MENU=============\n");
	printf("1- Add a value\n");
	printf("2- Search a value\n");
	printf("3- Print out the array \n");
	printf("4- Print out values in a range of inputted min and max values, inclusively.\n");
	printf("5- Sort the array in ascending order \n");
	printf("Other- Quit.\n");
	printf("Enter your choice: ");
	int choice = getInt(1, 6);
	return choice;
}





int main(){
	int *arr=NULL;
	int size = 0;
	int value;
	do {
		int choice = mainMenu();
		switch(choice) {
			case 1: printf("\n1- Add a value\n");
					addValue(&arr, &size);
                    break;
					
			case 2: printf("\n2- Search a value\n");
					printf("Enter a value: ");
					value = getInt(INT_MIN, INT_MAX);
					search(arr, size, value);
					break;
			case 3: printf("\n3- Print out the array \n");
					displayArray(arr, size);
					break;	
			case 4: printf("\n4- Print out values in a range of inputted min and max values, inclusively.\n");
					print_ValueInARange(arr, size);
					break;				
			case 5: printf("\n5- Sort the array in ascending order \n");
					sortAscending(arr, size);
					displayArray(arr, size);
					break;
			default : printf("\nOther- Quit.\nGoodbye !!!");
					exit(0);					
		}
	} while (1);
	free(arr);
	return 0;
}




