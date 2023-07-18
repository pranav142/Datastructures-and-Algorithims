#pragma once

#include <iostream>
#include <vector>

int linear_search_recursive(int arr[], int low, int high, int value);
int binary_search_recursive(int arr[], int low, int high, int value);
void selection_sort(int arr[], size_t arr_size);
void merge_sort(std::vector<int>&, int left, int right);