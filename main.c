#include <stdio.h>
#include <stdlib.h>

void repeats(int size, const int *numbers, int *repeating, int *max, int *position)
{
    *max = 0;
    *position = 0;
    for (int i = 0; i < size; i++)
    {
        repeating[i] = 1;

        for(int j = i + 1; j < size; j++)
        {
            if (numbers[i] == numbers[j])
            {
                repeating[i]++;
            }
        }

        if (*max < repeating[i])
        {
            *max = repeating[i];
            *position = i;
        }
    }    
}

int main(void)
{
    int size;

    printf("Enter the array size: ");
    if (scanf("%d", &size) != 1 || size <= 0 || size > 100)
    {
        printf("Error: Enter an integer from 1 to 100!\n");
        return 1;
    }

    int *numbers = malloc(size * sizeof *numbers);
    if (numbers == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }
    printf("Memory allocated.\n");

    printf("Enter the numbers: \n");
    for (int i = 0; i < size; i++)
    {
        if (scanf("%d", &numbers[i]) != 1)
        {
            printf("Error: Invalid number!\n");
            free(numbers);
            return 1;
        }
    }

    printf("Array: ");
    for (int i = 0; i < size; i++)
    {  
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    int max;
    int position;

    int *repeating = malloc(size * sizeof *repeating);
    if (repeating == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        free(numbers);
        return 1;
    }

    repeats(size, numbers, repeating, &max, &position);

    int num_pos = numbers[position];

    printf("Result: Number %d repeats %d time.\n", num_pos, max);

    free(repeating);
    free(numbers);
    return 0;
}