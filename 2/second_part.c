/*
 *  Advent of Code, day 2, part 2
 *
 */ 

#include <stdio.h>
#include <string.h>

int main()
{
    char direction[8];
    unsigned int qty, horizontal = 0;
    int vertical = 0, aim = 0;

    FILE *file;                                                         // file pointer                              
    file = fopen("puzzle.txt", "r");                                    // opening file puzzle.txt

    if(file){                                                           // the file exists
        while((fscanf(file, "%s %d", direction, &qty)) != EOF)          // Reading the direction and the number at once, till the end of hte file EOF
        {
            if(!strcmp(direction, "forward"))                           // Comparing strings
            {
                horizontal += qty;                                      // Horzontal/vertical movement
                vertical += (qty * aim);
            }
            else{
                if(!strcmp(direction, "down"))                          // Comparing strings
                    aim += qty;                                         // Calculating aim
                else
                    aim -= qty;
            }
        }

        fclose(file);                                                   // Closing the file
    }

    printf("Result %d\n", horizontal*vertical);                         // The result
}