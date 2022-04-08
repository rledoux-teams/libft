/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:02:13 by rledoux           #+#    #+#             */
/*   Updated: 2022/04/08 13:17:09 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i + 1);
}

size_t	word_count(const char *s, char c)
{
	size_t	size;
	int		index;
	
	size = 0;
	index = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c && s[index] != '\0')
			index++;
		while (s[index] != c && s[index] != '\0')
			index++;
		size++;
	}
	printf("Word count = %ld\n", size);
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char 	**res;

	j = 0;
	res = malloc(word_count(s, c) * sizeof(char *));
	//printf("Malloc réussi, taille de %ld\n", word_count(s, c));
	res[j] = malloc(ft_strlen(s, c));
	printf("Malloc réussi, taille de %ld char '%c'\n", ft_strlen(s, c), *s);
	if (res[j] == NULL)
		return (NULL);
	i = 0;
	while (*s == c && *s != '\0')
		s++;
	while (*s != '\0')
	{
		if (*s == c)
		{
			res[j][i] = '\0';
			i = 0;
			s++;
			printf("res = '%s'\n", res[j]);
			j++;
			while (*s == c && *s != '\0')
				s++;
			if (*s == '\0')
			{
				//printf("Fin split 2\n");
				return (res);
			}
			res[j] = malloc(ft_strlen(s, c));
			if (res == NULL)
				return (NULL);
			printf("Malloc réussi, taille de %ld char '%c'\n", ft_strlen(s, c), *s);
		}
		res[j][i] = *s;
		i++;
		s++;
	}
	res[j][i] = '\0';
	//res[j + 1] = 0;
	return (res);
}
