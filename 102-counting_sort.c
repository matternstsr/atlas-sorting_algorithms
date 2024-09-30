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
	if (size <= 1)
		return;

	/* Find the maximum value in the array */
	int max_value = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* make the array for counting */
	int *counting_array = malloc((max_value + 1) * sizeof(int));
	if (!counting_array)
		return;

	/* Fill array with zeros could have used calloc */
	for (int i = 0; i <= max_value; i++)
		counting_array[i] = 0;

	/* Count each element in the array */
	for (size_t i = 0; i < size; i++)
		counting_array[array[i]]++;

	/* Print the counting array */
	print_array(counting_array, max_value + 1);

	/* Reconstruct the original array */
	size_t index = 0;
	for (int i = 0; i <= max_value; i++)
	{
		while (counting_array[i] > 0)
			array[index++] = i;
	}

	/* Free counting array */
	free(counting_array);
}
