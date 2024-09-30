#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* 
 * counting_sort - Sorts an array of integers using the Counting sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    size_t max_value, *counting_array;
    size_t i, index;

    if (size <= 1)
        return;

    /* Find the maximum value in the array */
    max_value = (size_t)array[0];
    for (i = 1; i < size; i++)
    {
        if ((size_t)array[i] > max_value)
            max_value = (size_t)array[i];
    }

    /* Make the array for counting */
    counting_array = malloc((max_value + 1) * sizeof(size_t));
    if (!counting_array)
        return;

    /* Fill array with zeros */
    for (i = 0; i <= max_value; i++)
        counting_array[i] = 0;

    /* Count each element in the array */
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    print_array(counting_array, max_value + 1);

    /* Reconstruct the original array */
    index = 0;
    for (i = 0; i <= max_value; i++)
    {
        while (counting_array[i] > 0)
        {
            array[index++] = i;
            counting_array[i]--;
        }
    }

    /* Free counting array */
    free(counting_array);
}
