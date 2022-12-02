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

        sum = sum + t_num;
        if(sum > hSum){
            hSum = sum;
        }

        if(strlen(str) < 3 || c == EOF){
            //Compare sum to hSum then reset sum back to 0
            sum = 0;
        }
        ungetc(c,f);
    }

    printf("\n");
    fclose(f);
    printf("The elf that is carrying the highest amount of calories is carrying %d calories! Wow!\n",hSum);

	return 0;
}
