/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:06:20 by rledoux           #+#    #+#             */
/*   Updated: 2022/03/29 18:11:57 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(char *)(s1 + i) == *(char *)(s2 + i) && i < n)
		i++;
	if (i == n || *(char *)(s1 + i) == *(char *)(s2 + i))
		return (0);
	if (*(char *)(s1 + i) > *(char *)(s2 + i) || *(char *)(s1 + i) == '\200')
		return (1);
	return (-1);
}
