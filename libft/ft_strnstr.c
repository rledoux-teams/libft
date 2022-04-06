/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:13:40 by rledoux           #+#    #+#             */
/*   Updated: 2022/03/29 19:15:51 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_little(const char *big, const char *little, int i, int check)
{
	while (little[i] != '\0')
	{
		if (!(little[i] == *(big + i) && check == 1))
			check = 0;
		i++;
	}
	if (check == 1)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	index;
	int		check;

	if (*little == 0)
		return (big);
	if (len == 0)
		return (0);
	index = 0;
	while ((*big != '\0') && (index < (len - ft_strlen(little))))
	{
		if (little[0] == *big)
		{
			if (check_little(big, little, 0, 1) == 1)
				return (big);
		}
		index++;
		big++;
	}
	return (0);
}
