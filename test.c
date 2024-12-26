#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10
#define MINES 12



int main(void)
{
    srand(time(NULL));

    char pg[SIZE][SIZE] = {'0'};
    char coors[2] = {0};
  

    for (size_t i = 0; i < MINES; i++)
    {
        bool flag = true;
        
        do
        {
            flag = true;

            coors[0] = rand() % SIZE;
            coors[1] = rand() % SIZE;

            for (size_t i = -1; i < 2; i++)
            {
                if (0 < coors[0] + i && coors[0] + i < 10)
                    
                    for (size_t k = -1; k < 2; k++)
                    {
                        if (0 < coors[1] + k && coors[1] + k < 10)
                            if (pg[coors[0] + i][coors[1] + k] == '*')
                                flag = false;
                    }
                
                if (flag == false)
                    break;
            }

        } while (!flag);

        
        pg[coors[0]][coors[1]] = '*';

    }

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            printf("%c ", pg[i][j]);
        }

        printf("\n");
        
    }
    

    //__assert_verify_pg(pg); // для тестирования (не убирать и должна идти непосредственно перед return 0)
    return 0;
}