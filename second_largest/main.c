#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool second_largest(int size, const int *numbers, int *result)
{
    if (size < 2 || numbers == NULL || result == NULL)
    {
        return false;
    }

    int largest = numbers[0];
    int second_largest_value;
    bool found = false;

    for (int i = 1; i < size; i++)
    {
        if (largest < numbers[i])
        {
            second_largest_value = largest;
            largest = numbers[i];
            found = true;
        }
        else if (largest > numbers[i])
        {
            if (!found)
            {
                second_largest_value = numbers[i];
                found = true;
            }
            else if (second_largest_value < numbers[i])
            {
                second_largest_value = numbers[i];
            }
        }    
    }

    if (!found)
    {
        return false;
    }

    *result = second_largest_value;
    return true;
}

int main(void)
{
    int size;

    printf("Enter the array size: ");
    if (scanf("%d", &size) != 1 || size < 2)
    {
        printf("Error: Enter a positive integer greater than 1!\n");
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
            printf("Error: Invalid number!\n");
            free(numbers);
            return 1;
        }
    }

    int result;
    bool found = second_largest(size, numbers, &result);
    if (!found)
    {
        printf("There is no second largest number!\n");
    }
    else
    {
        printf("Second largest number is %d.\n", result);
    }
    free(numbers);
    return 0;
}
