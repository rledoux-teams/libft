/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:50:00 by rledoux           #+#    #+#             */
/*   Updated: 2022/03/30 17:30:58 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t		i;
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;

	while (*s1 != '\0')
	{
		if (*set == 0)
			return (0);
		if (*s1 == set[0] && *(s1 + ft_strlen(set) - 1) == set[ft_strlen(set) - 1])
		{
			printf("Conditions rempli\n");
			res = ft_strjoin(s1, s1 + ft_strlen(set));
		}
		s1++;
	}
	return (res);
}
