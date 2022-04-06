/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:22:14 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/06 18:47:34 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	intlen(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
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
	int	i;

	if (((len + 1) * sizeof(char)) > 2147483647)
		return (NULL);
	res = malloc((len + 1) * sizeof(char));
	i = 0;
	while (i < len + 1)
	{
		*(res + i) = '\0';
		i++;
	}
	if (res == NULL)
		return (NULL);
	return (res);
}

int	is_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			bool_negative;
	int			len;
	long int	n2;

	n2 = n;
	len = intlen(n2) - 1;
	bool_negative = is_negative(n2);
	res = malloc(0);
	res = malloc_res(res, len + 1);
	if (n < 0)
		n2 = n2 * -1;
	while (n2 >= 1 || (len == 0 && !bool_negative))
	{
		res[len] = (n2 % 10) + '0';
		if (n2 == 10)
			n2 = 1;
		else
			n2 = n2 / 10;
		len--;
	}
	if (bool_negative)
		res[len] = '-';
	return (res);
}
