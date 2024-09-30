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
	int max_value, *counting_array, end_array;
	size_t i, index;

	if (size <= 1)
		return;

	/* Find the maximum value in the array */
	max_value = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Make the array for counting */
	counting_array = malloc((max_value + 1) * sizeof(int));
	if (!counting_array)
		return;

	/* Fill array with zeros */
	for (i = 0; i <= (size_t)max_value; i++)
		counting_array[i] = 0;

	/* Count each element in the array */
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	for (i = 1; i < (size_t)max_value + 1; i++)
		counting_array[i] += counting_array[i - 1];

	/* Print the counting array */
	print_array(counting_array, (size_t)max_value + 1);

	/* Reconstruct the original array */
	index = 0;

	end_array = malloc((max_value + 1) * sizeof(int));
	if (!end_array)
		return;

	for (i = 0; i <= (size_t)max_value; i++)
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
