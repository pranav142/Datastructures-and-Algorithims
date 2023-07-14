#include "lesson_3.h"

void selection_sort(int arr[], size_t arr_size)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		int min_index = i;

		for (int j = i + 1; j < arr_size; j++)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}

		std::swap(arr[i], arr[min_index]);
	}
}