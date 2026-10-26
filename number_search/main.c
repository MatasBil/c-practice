#include <stdio.h>
#include <stdlib.h>

int count_occurrences(int size, const int *numbers, int target)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] == target)
        {
            count++;
        }
    }

    return count;
}

int main(void)
{
    int size;

    printf("Enter the array size: ");
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("Error: Enter a positive integer!\n");
        return 1;
    }

    int *numbers = malloc(size * sizeof *numbers);
    if (numbers == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }

    printf("Memory allocated!\n");
    
    printf("Enter the numbers: ");
    for (int i = 0; i < size; i++)
    {
        if (scanf("%d", &numbers[i]) != 1)
        {
            printf("Error: Type a number!\n");
            free(numbers);
            return 1;
        }
    }

    int target;

    printf("Which number should we count? ");
    if (scanf("%d", &target) != 1)
    {
        printf("Error: Type a number!\n");
        free(numbers);
        return 1;
    }

    int count = count_occurrences(size, numbers, target);

    printf("Number %d appears %d times.\n", target, count);

    free(numbers);
    return 0;
}
