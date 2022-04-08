/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:41:52 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/08 13:16:27 by rledoux          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	index;

	res = malloc(ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	index = 0;
	while (index < ft_strlen(s1))
	{
		res[index] = s1[index];
		index++;
	}
	while (i < ft_strlen(s2))
	{
		res[index] = s2[i];
		i++;
		index++;
	}
	return (res);
}
