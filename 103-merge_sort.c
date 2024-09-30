#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[].
 * @array: The array to merge into.
 * @left: The left index of the subarray.
 * @middle: The middle index of the subarray.
 * @right: The right index of the subarray.
 */
void merge(int *array, int left, int middle, int right)
{
    int left_index, right_index, start;
    int size_left = middle - left + 1;
    int size_right = right - middle;
    int *left_array = malloc(size_left * sizeof(int));
    int *right_array = malloc(size_right * sizeof(int));

    if (!left_array || !right_array)
        return;

    for (left_index = 0; left_index < size_left; left_index++)
        left_array[left_index] = array[left + left_index];
    for (right_index = 0; right_index < size_right; right_index++)
        right_array[right_index] = array[middle + 1 + right_index];

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left_array, size_left);
    printf("[right]: ");
    print_array(right_array, size_right);
    printf("[Done]: ");
    left_index = 0; 
    right_index = 0; 
    start = left;

    while (left_index < size_left && right_index < size_right)
    {
        if (left_array[left_index] <= right_array[right_index])
            array[start++] = left_array[left_index++];
        else
            array[start++] = right_array[right_index++];
    }

    while (left_index < size_left)
        array[start++] = left_array[left_index++];

    while (right_index < size_right)
        array[start++] = right_array[right_index++];

    print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursive helper function for merge_sort.
 * @array: The array to sort.
 * @left: The left index of the subarray.
 * @right: The right index of the subarray.
 */
void merge_sort_recursive(int *array, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        merge_sort_recursive(array, left, middle);
        merge_sort_recursive(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, 0, size - 1);
}
