#include "push_swap.h"

static int	pres(const char *str, int *f)
{
	long long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (((res * 10 + (*str - '0'))) / 10 != res)
		{
			*f = 1;
			return (-1);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str)
		*f = 1;
	return ((int)res);
}

static int	mres(const char *str, int *f)
{
	long long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (((res * 10 + (*str - '0'))) / 10 != res)
		{
			*f = 1;
			return (0);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str)
		*f = 1;
	return ((int)-res);
}

int			atoi_push_swap(const char *str, int *f)
{
	int			sign;

	sign = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		   || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	if (sign)
		return (mres(str, f));
	else
		return (pres(str, f));
}