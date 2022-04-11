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
/*
static size_t	ft_strlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i + 1);
}
*/

static void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while ((i < size - 1) && (*(src + i) != '\0'))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
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
	return (size);
}

void	get_next_word(char **copy_s, size_t *len, char c)
{
	size_t	i;

	i = 0;
	*copy_s = *copy_s + *len;
	*len = 0;
	while(**copy_s && **copy_s == c)
		(*copy_s)++;
	while ((*copy_s)[i])
	{
		if (((*copy_s)[i] == c))
			break ;
		i++;
		(*len)++;
	}
}

char	**ft_split(char const *s, char c)
{
	char 	**res;
	char	*copy_s;
	size_t	len;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	res = (char **)malloc(count * sizeof(char *));
	if (res == NULL)
		return (NULL);
	copy_s = (char *)s;
	len = 0;
	i = 0;
	while (i < count)
	{
		get_next_word(&copy_s, &len, c);
		res[i] = (char *)malloc(sizeof(char) * len + 1);
		if (res[i] == NULL)
			return (NULL);
		ft_strlcpy(res[i], copy_s, len);
		i++;
	}
	res[i] = NULL;
	return (res);
}
