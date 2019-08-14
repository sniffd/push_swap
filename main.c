#include <stdio.h>
#include "push_swap.h"
//
//int main() {
//	int ar[] = {54, 4, 7, 78, 65, 1, 0, 64, 1, 20};
//	int n = 11;
//	int i = 0;
//	int arr_size = 30000;
//	int *arr;
//
//	arr = (int *) malloc(arr_size * sizeof(int));
//	for (int k = 0; k < arr_size; k++)
//	{
//		arr[k] = rand();
//		if (k % 2)
//			arr[k] = -arr[k];
//	}
//	while (i < arr_size)
//	{
//		ft_printf("%i ", arr[i]);
//		i++;
//	}
//	ft_printf("\n");
//	ft_qsort(arr, arr_size - 1);
//	i = 0;
//	while (i < arr_size)
//	{
//		ft_printf("%i ", arr[i]);
//		i++;
//	}
//	i = 0;
//	while (i < arr_size - 1)
//	{
//		if (arr[i] > arr[i + 1])
//			ft_printf("KO\n");
//		i++;
//	}
//	return 0;
//}