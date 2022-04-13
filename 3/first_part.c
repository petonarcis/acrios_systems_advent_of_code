/*
 *  Advent of Code, day 3, part 1
 *
 */ 

#include <stdio.h>
#include <string.h>

int main()
{
    char bin_string[20];
    unsigned int bin_width, ones = 0, zeroes = 0;
    int result = 0, result_inverted = 0;

    FILE *file;                                                     // file pointer
    file = fopen("puzzle.txt", "r");                                // opening file puzzle.txt
                                                                    // Finding out the bin width from the first reading
    fscanf(file, "%s", bin_string);                                 // Reading from the file to string                     
    bin_width = strlen(bin_string);                                 // Length of the string
    rewind(file);                                                   // Reseting the pointer to the beginning of the file

    if(file){                                                       // The file exists
        for(unsigned int pos = 0; pos < bin_width; pos++){          // Number of cycles depending by the bind width
            while((fscanf(file, "%s", bin_string)) != EOF){         // Reading from the .txt file
                if(bin_string[pos] == '0')                          // Finding out, whether 0 or 1 is present on the current poisition
                    zeroes++;
                else
                    ones++;
            }
            if(ones > zeroes)                                       // Creating the binary shifted number from the partial results
                result |= 1 << (bin_width - pos - 1);               // If a majority of 1s is present
            else
                result_inverted |= 1 << (bin_width - pos - 1);      // The binary inverted number, a majority of 0s is present
        
        zeroes = 0;                                                 // Reseting the 1s and 0s, movig to the next bit position
        ones = 0;
        rewind(file);                                               // Reseting the pointer to the beginning of the file
    }
        printf("Result: %d\n", result * result_inverted);           // The result
        fclose(file);                                               // Closing the file
    }
}