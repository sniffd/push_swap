#include "push_swap.h"

void get_median(int *ar, int end)
{
	int first;
	int last;
	int mid;

	first = ar[0];
	last = ar[end];
	mid = ar[end / 2];
	if (ar[mid] < ar[first])
		ft_swap(ar, ar + end / 2);
	if (ar[last] < ar[first])
		ft_swap(ar, ar + end);
	if (ar[mid] > ar[last])
		ft_swap(ar + end, ar + end / 2);
}

int	partition(int *ar, int end)
{
	int pivot;
	int i;
	int j;

	get_median(ar, end);
	pivot = ar[end / 2];
	i = -1;
	j = end + 1;
	while (1)
	{
		i = i + 1;
		while (ar[i] < pivot && i < end)
			i = i + 1;
		j = j - 1;
		while (ar[j] > pivot && j > 0)
			j = j - 1;
		if (i >= j)
			return (j);
		ft_swap(ar + i, ar + j);
	}
}

void	ft_qsort(int *ar, int end)
{
	int p;

	if (end > 0)
	{
		p = partition(ar, end);
		ft_qsort(ar, p - 1);
		ft_qsort(ar + p + 1, end - p - 1);
	}
}