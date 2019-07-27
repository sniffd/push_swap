#include "push_swap.h"

int	get_median(const int *ar, int end)
{
	int first;
	int last;
	int mid;

	first = ar[0];
	last = ar[end];
	mid = ar[end / 2];
	if ((first >= last && last >= mid) || (first <= last && last <= mid))
		return (end);
	else if ((last >= mid && mid >= first) || (last <= mid && mid <= first))
		return (end / 2);
	else
		return (0);
}

int	partition(int *ar, int end)
{
	int pivot;
	int i;
	int j;

	pivot = get_median(ar, end);
	i = -1;
	j = end + 1;
	while (1)
	{
		i = i + 1;
		while (ar[i] <= pivot && i < end)
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

	if (end > 1)
	{
		p = partition(ar, end);
		ft_qsort(ar, p - 1);
		ft_qsort(ar + p + 1, end - p - 1);
	}
}