/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:58:09 by rledoux           #+#    #+#             */
/*   Updated: 2022/03/29 18:05:48 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (c == NULL)
	{
		while (*(char *)(s) != '\0')
			s++;
		return (s);
	}
	i = 0;
	while (*(char *)(s) != '\0' && i < n)
	{
		if (*(char *)(s) == c)
			return (s);
		s++;
		i++;
	}
	return (0);
}
