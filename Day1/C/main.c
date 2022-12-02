#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Holds the highest sum
int hSum = 0;
int sum = 0;
//Holds the temporary sum for the current set of calories

int main(int argc, char* argv []){

    //Open file via passed argument
    FILE *f = fopen(argv[1], "r");
    char str[100];

    //Loop to read through whole file
    while(fgets(str, sizeof(str), f) != NULL){

        //Holds current number to add to sum
        int t_num = atoi(str);
        char c = getc(f);

        //Adds current line's value to 'sum'
        sum = sum + t_num;

        //Checks if the new sum is higher than hsum, if so, then it changes hsum to the new highest value
        if(sum > hSum){
            hSum = sum;
        }

        //Checks if the line is a blank/empty line OR if EOF has been achieved - if so, resets sum to zero.
        if(strlen(str) < 3 || c == EOF){
            sum = 0;
        }
        ungetc(c,f);
    }

    printf("\n");
    fclose(f);
    //Prints the total calories the elf with the highest amount of calories is carrying
    printf("The elf that is carrying the highest amount of calories is carrying %d calories! Wow!\n",hSum);

	return 0;
}
