
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#include <conio.h>
#include <dirent.h>
#include<stdlib.h>

#define MIN_VALUE 1
#define MAX_VALUE 4
#define MONEY_START 10.00





void remove(){
	fflush(stdin);
	FILE *fptr;
	fptr=fopen("C:\\Users\\ADMIN\\Desktop\\LAB101\\AAA\\total\\C.L.P0003done\\money.txt", "r");
	if (fptr == NULL){
		printf("khong co file");
	}
	else{
		printf("co file");
	}
	fclose(fptr);
	
	
	char save[]="money.txt";
		
            if (remove(save) == 0)
                printf("Deleted!");
            else
                printf("This file is not exist!\n");
}




int getInt(int minValue, int maxValue) {
    int value;
    char check; //42a
    do {
        int rc = scanf("%d%c", &value, &check);
        fflush(stdin);
        if (rc != 2 || check != '\n') {
            printf("Invalid value!\n");
        } else if (value < minValue || value > maxValue) {
            printf("Value out of range!\n");
        } else { // rc == 2 && check == '\n'
            return value;
            //break out of function
        }
    } while (1);
}















float readValueFormFile(float money) {
	

	
    FILE *fptr;
	char no[100];
	int ok;
	
    fptr = fopen("C:\\Users\\ADMIN\\Desktop\\LAB101\\AAA\\total\\C.L.P0003done\\money.txt", "r+");
    
    //check the existence of the file
    if (fptr == NULL) {
        //file not yet made --> make new file money.txt
        fptr = fopen("C:\\Users\\ADMIN\\Desktop\\LAB101\\AAA\\total\\C.L.P0003done\\money.txt", "w+");
        fprintf(fptr, "%f", MONEY_START);
		money = MONEY_START;
		fclose(fptr);
    }
    fclose(fptr);
    
    
    
	fptr = fopen("C:\\Users\\ADMIN\\Desktop\\LAB101\\AAA\\total\\C.L.P0003done\\money.txt", "r+");
	fgets(no,100,fptr);

	for(int i=0; i<strlen(no); i++) 
	
				
            if (no[i] >= 46 && no[i] <= 57) {
            	
				if(no[i]!=47){
					ok = 0;
                
             }else {
             	 ok = 1;
               break;
					}
	}else{
	ok=1;
	break;
	}
	printf("ok = %d ",ok);
	
	if(ok == 0){
				fptr = fopen("C:\\Users\\ADMIN\\Desktop\\LAB101\\AAA\\total\\C.L.P0003done\\money.txt", "r+");
				fscanf(fptr,"%f",&money);
				fclose(fptr);
				if(money<=0){
					fptr = fopen("C:\\Users\\ADMIN\\Desktop\\LAB101\\AAA\\total\\C.L.P0003done\\money.txt", "w+");
					fprintf(fptr, "%f", MONEY_START);
					money = MONEY_START;
					printf("Money is 0 or null in file save data, we will reset money\n");
					fclose(fptr);
				}fclose(fptr);
   				} else {
				fptr = fopen("C:\\Users\\ADMIN\\Desktop\\LAB101\\AAA\\total\\C.L.P0003done\\money.txt", "w+");
            	fprintf(fptr, "%f", MONEY_START);
				money = MONEY_START;
				printf("money reset because data have character\n");
				fclose(fptr);
                        

}

    //close file fptr
    fclose(fptr);
    return money;
    fclose(fptr);
    fclose(fptr);
    fclose(fptr);
    fclose(fptr);
    fclose(fptr);
    

}













void saveMoney(float money) {
    //open file money.txt to write value of money to this file
    FILE *fptr;
    fptr = fopen("C:\\Users\\ADMIN\\Desktop\\LAB101\\AAA\\total\\C.L.P0003done\\money.txt", "w");
    fprintf(fptr, "%f", money);
    printf("Your money have saved.\n");
    fclose(fptr);
}













int randomThree_digitNumber(int minRand, int maxRand) {
    int three_digitNumber[3];
   	time_t t;
	srand((unsigned) time(NULL));
    
    
    printf("The slot machine shows ");
    for (int i = 0; i < 3; i++) {
    	three_digitNumber[i]=rand()%10;
        printf("%d", three_digitNumber[i]);
    }
    printf("\n");
    //Count Combination--> 0, 1, 2
    int countCombination;
    if (three_digitNumber[0] == three_digitNumber[1] && three_digitNumber[0] == three_digitNumber[2]) {
        countCombination = 2;
    } else if (three_digitNumber[0] == three_digitNumber[1] || three_digitNumber[0] == three_digitNumber[2] || three_digitNumber[1] == three_digitNumber[2]) {
        countCombination = 1;
    } else
        countCombination = 0;
    return countCombination;
    
}

float playTheSlotMachine(float money) {
    //start play game -- > money - $0.25
    money -= 0.25;
    //assign countCombination = a number form 0--> 999 by function radomThree_digitNumber();
    int countCombination = randomThree_digitNumber(0, 999);
    if (countCombination == 2) {
        printf("You win the big prize, $10.00!\n");
        money += 10;
    } else if (countCombination == 1) {
        printf("You win 50 cents!\n");
        money += 0.5;
    } else {
        printf("Sorry you don't win anything.\n");
    }
    printf("You have $%.2f\n", money);
    printf("---------------------------------------\n");
    //return money for next time
    
    return money;
}








int main() {
    int choose;
    //declare pointer of file
    FILE *fptr;
    fptr=fopen("C:\\Users\\ADMIN\\Desktop\\LAB101\\AAA\\total\\C.L.P0003done\\money.txt", "r");
    fclose(fptr);
    
    //read value of money form file
    float money = readValueFormFile(money);
    printf("You have $%.2f.\n", money);
    fclose(fptr);
    do {
        //call function menu, input choice
        printf("-Chose one of the following menu options: \n");
        printf("1) Play the slot machine.\n");
        printf("2) Save game.\n");
        printf("3) Cash out and out.\n");
        printf("4) save game and out.\n");
        choose = getInt(MIN_VALUE, MAX_VALUE);
         fclose(fptr);
        switch (choose) {
            case 1:
                //play game the slot machine
                money = playTheSlotMachine(money);
                 fclose(fptr);
                break;
            case 2:
                //Save money to file
                saveMoney(money);
                 fclose(fptr);
                break;
            case 3:
                remove();
                printf("Thank you for playing! You end with $%.2f!", money);
                exit(0);
            case 4:
				saveMoney(money);
				exit(0);
				
				
        }
        // number of time add 1
fclose(fptr);
    } while (1);
}
