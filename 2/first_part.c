/*
 *  Advent of Code, day 2, part 1
 *
 */ 

#include <stdio.h>
#include <string.h>

int main()
{
    char direction[8];
    unsigned int qty, horizontal = 0;
    int vertical = 0;

    FILE *file;                                                             // file pointer                                              
    file = fopen("puzzle.txt", "r");                                        // opening file puzzle.txt

    if(file){                                                               // the file exists
        while((fscanf(file, "%s %d", direction, &qty)) != EOF)              // Reading the direction and the number at once, till the end of hte file EOF
        {
            if(!strcmp(direction, "forward"))                               // Comparing the string from .txt file
                horizontal += qty;                                          // Forward
            else{
                if(!strcmp(direction, "down"))                              // Comparing the string from .txt file
                    vertical += qty;                                        // Down
                else
                    vertical -= qty;                                        // Up
            }   
        }

        fclose(file);                                                       // Closing the file
    }

    printf("Result %d", horizontal*vertical);
}