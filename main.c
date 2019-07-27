#include <stdio.h>
#include "push_swap.h"

int main()
{
	int	ar[] = {54, 4, 7, 78, 65, 1, 0, 64, 1, 20};
	int n = 10;
	int i = 0;
	while (i < n)
	{
		ft_printf("%i ", ar[i]);
		i++;
	}
	ft_printf("\n");
	ft_qsort(ar, n - 1);
	i = 0;
	while (i < n)
	{
		ft_printf("%i ", ar[i]);
		i++;
	}
	return 0;
}