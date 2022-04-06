/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:19 by rledoux           #+#    #+#             */
/*   Updated: 2022/03/29 17:39:06 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	index;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (c == NULL)
	{
		while (*s != '\0')
			s++;
		return (s);
	}
	while (s[i] != c && i > 0)
		i--;
	if (s[i] == c)
	{
		while (index < i)
		{
			index++;
			s++;
		}
		return (s);
	}
	return (0);
}
