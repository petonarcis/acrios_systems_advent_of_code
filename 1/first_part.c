/*
 *  Advent of Code, day 1, part 1
 *
 */ 

#include <stdio.h>

int main()
{
    unsigned int number, previous_num = 0, current_num = 0, increase = 0;
    FILE *file;                                                     // file pointer
    file = fopen("puzzle.txt", "r");                                // opening file puzzle.txt

    if(file){                                                       // the file exists
        while((fscanf(file, "%d", &number)) != EOF){                // converting '\n' separated characters to numbers

            if((previous_num == 0) && (current_num == 0))           // first reading
                current_num = number;

            else{                                                   // all the other readings
                previous_num = current_num;                                     
                current_num = number;

                if (previous_num < current_num)                     // checking if there is an increase
                    increase++;
            }
        }
        fclose(file);                                               // closing file
        printf("Increase: %d\n", increase);                           // the result
    }
}