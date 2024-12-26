#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define SIZE 5
#define MINES 6

int main(void)
{
    char pg[SIZE][SIZE] = {'0'};
    memset(pg, '0', sizeof pg);

    char coors[2] = {0};

    for (size_t _ = 0; _ < MINES; _++)
    {
        bool flag = true;

        do
        {
            flag = true;

            coors[0] = rand() % SIZE;
            coors[1] = rand() % SIZE;

            for (int i = -1; i != 2; i++)
            {
                if ((-1 < coors[0] + i) && (coors[0] + i < 10))

                    for (int k = -1; k != 2; k++)
                    {
                        if ((-1 < coors[1] + k) && (coors[1] + k < 10))
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