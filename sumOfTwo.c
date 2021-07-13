#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void GenerateArray(int* userArray, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        userArray[i] = rand() % 100;
    }
}

void PrintArray(int* userArray, int arraySize)
{
    fprintf(stdout, "{ ");
        for (int i = 0; i < arraySize; i++)
        {
            if (i == arraySize - 1)
            {
                fprintf(stdout, "%d", userArray[i]);
            }
            else
            {
                fprintf(stdout, "%d, ", userArray[i]);
            }
        }
    fprintf(stdout, "}\n");
}

int main (void)
{
    srand(time(NULL));

    int numArraySize = rand() % 16;
    int* numArray = (int*)malloc(numArraySize * sizeof(int));
       GenerateArray(numArray, numArraySize); 
       PrintArray(numArray, numArraySize);

    //My job is to return the two indexe's that return a target
    //int target = numArray[3] + numArray[4];       Test Case
    int target = rand() % 100;
    bool targetFound = false;
        for (int i = 0; i < numArraySize; i++)
        {
            for (int j = 0; j < numArraySize; j++)
            {
                if (numArray[i] + numArray[j] == target)
                {
                    fprintf(stdout, "Indexes {%d, %d}\n", i, j);
                    targetFound = true;
                }
            }
        }

    if (targetFound == false)
    {
        fprintf(stdout, "No indexes add up to the target: %d", target);
    }

    return 0;
}