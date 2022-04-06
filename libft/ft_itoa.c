/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:22:14 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/04 16:42:42 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = s;
	while (i < n)
	{
		*(res + i) = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if ((nmemb * size) > 2147483647)
		return (NULL);
	ptr = malloc(nmemb * size);
	ft_memset(ptr, 0, size);
	return (ptr);
}

int	intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (2);
	if (n > 0)
	{
		while (n >= 1)
		{
			if (n == 10)
				n = 1;
			else
				n = n / 10;
			len++;
		}
		return (len);
	}
	else if (n < 0 && n != -2147483648)
	{
		n = n * -1;
		return (intlen(n) + 1);
	}
	else
		return (11);
}

char	*malloc_res(char *res, int len)
{
	res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	return (res);
}

int	is_negative(int n)
{
	if (n < 0 || n == -2147483648)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		bool_negative;
	int		len;

	len = intlen(n) - 1;
	bool_negative = is_negative(n);
	res = malloc(0);
	res = malloc_res(res, len + 1);
	if (n < 0 && n != -2147483648)
        n = n * -1;
    else if (n == -2147483648)
	{
		res[len] = '8';
		n = 214748364;
		len--;
	}
	while (len >= 0)
	{
		res[len] = (n % 10) + '0';
		if (n == 10)
			n = 1;
		else
			n = n / 10;
		len--;
	}
	if (bool_negative)
		res[len] = '-';
	return (res);
}
