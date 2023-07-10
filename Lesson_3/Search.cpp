#include "lesson_3.h"


int linear_search_recursive(int arr[], int low, int high, int value)
{
	if (low > high)
		return -1;

	if (arr[low] == value)
		return low;
	
	return linear_search_recursive(arr, low + 1, high, value);
}

int binary_search_recursive(int arr[], int low, int high, int value)
{
	if (low > high)
		return low - 1;

	int mid = (low + high) / 2;

	if (arr[mid] == value)
		return mid;

	else if (arr[mid] > value)
		return binary_search_recursive(arr, low, mid - 1, value);

	else
		return binary_search_recursive(arr, mid + 1, high, value);
}
