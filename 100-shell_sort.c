#include <stdio.h>
#include <stdlib.h>

/* 
* shell_sort - Sorts an array of integers using the Shell sort algorithm
*               with the Knuth sequence.
* @array: The array to sort.
* @size: The size of the array.
*/
void shell_sort(int *array, size_t size)
{
	/* Sequence gaps */
	size_t gap = 1;
	size_t i;
	
	/* Figure out ate initial gap */
	while (gap < size)
		gap = gap * 3 + 1;

	/* Start with the largest gap and then go down */
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			int temp = array[i];
			size_t j = i;

			/* Sort with insertion using current gap */
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}

		/* Print the array after each itteration */
		print_array(array, size);
		
		/* Figue out the next gap */
		gap = (gap - 1) / 3;
	}
}
