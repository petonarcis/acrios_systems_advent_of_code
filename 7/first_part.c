/*
 *  Advent of Code, day 7, part 1
 *  I couldnt fin the answer. The task is a good example of the standard deviation.
 */ 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    FILE *file;                                                     // file pointer
    file = fopen("puzzle.txt", "r");                                // opening file puzzle.txt

    unsigned int sum_of_numbers = 0, count_of_numbers = 0, number;
    unsigned int char_counter = 0, run, integer_deviation = 0, fuel = 0;
    double average, deviation = 0, mean = 0, distance_to_mean = 0;
    char input, char_number[5];

    if(file){                                                       // If the file exists
        for(run = 0; run < 3; run++){                               // 3-times reading the txt file
            do{                  
                input = fgetc(file);                                // Reading one-by-one character
                    
                if((input == ',') || (input == EOF))                // Coma-separated values
                {
                    char_number[char_counter++] = '\0';             // If coma(EOF) is found, an aux string is completed by '\0' for safety
                    number = atoi(number);                          // string to integer conversion
                    char_counter=0;                                 // reset char_counter

                    if(run == 0)                                    // 1-st run
                    {
                        sum_of_numbers += number;                   // Sum of the numbers needed for the average value
                        count_of_numbers++;
                    }

                    else if(run == 1)                               // 2-nd run
                        distance_to_mean += pow(((double)(number) - mean), 2.0);    // Distance to mean value - from the standard deviation formula

                    else                                            // 3-rd run
                        fuel += abs(integer_deviation - number);    // Calculatin of the fuel consumption
                }

                else                                                // If other chat than ',' or EOF is found
                {
                    char_number[char_counter] = input;              // Filling the aux. char number array
                    char_counter++;
                }

            }while(input != EOF);                                   // End of the cycle when the EOF is found
                                                                    // Do-While used, so the last number from the txt. file is acquised

            if(run == 0)                                            // After the 1-st run, the mean value is calculated
                mean = (double)(sum_of_numbers) / (double)(count_of_numbers);

            else if(run == 1)                                       // After the 2-nd run, deviation is calclated
            {
                deviation = sqrt((double)(distance_to_mean)/(double)(count_of_numbers-1));
                integer_deviation = (unsigned int)(deviation);      // Integer value of the deviation, so the fule is interer
            }

            rewind(file);                       // Reset the pointer to the beggining of the txt file                      
        }

        fclose(file);                                               // closing file
        printf("Fuel: %d\n", fuel);                                   // The result
    }
}