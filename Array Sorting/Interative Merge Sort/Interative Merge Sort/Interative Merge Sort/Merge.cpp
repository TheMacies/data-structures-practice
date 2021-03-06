#pragma once
#include "Merge.h"
#include <iostream>
using namespace std;

void merge(int arr[], int offset, int middle, int right)
{
	int i, j, k;
	int n1 = middle - offset + 1;
	int n2 = right - middle;

	int* L = new int[n1];
	int* R = new int[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[offset + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	i = 0;
	j = 0;
	k = offset;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}



int min(int a, int b) {
	return a < b ? a : b;
}


void MergeSort(int arr[], int n)
{
	int curr_size; 
	int left_start; 
	for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
	{
		for (left_start = 0; left_start<n - 1; left_start += 2 * curr_size)
		{
			int mid = left_start + curr_size - 1;
			int right_end = min(left_start + 2 * curr_size - 1, n - 1);
			merge(arr, left_start, mid, right_end);
		}
	}
}