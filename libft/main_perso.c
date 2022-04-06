/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:32:25 by rledoux           #+#    #+#             */
/*   Updated: 2022/03/29 16:38:44 by rledoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	printf("ft_isalpha : %d isalpha : %d\n", ft_isalpha('g'), isalpha('g'));
	printf("ft_isdigit : %d isdigit : %d\n", ft_isdigit('0'), isdigit('2'));
	printf("ft_isalnum : %d isalnum : %d\n", ft_isalnum('a'), isalnum('a'));
	printf("ft_isascii : %d isascii : %d\n", ft_isascii('\n'), isascii('\n'));
	printf("ft_isprint : %d isprint : %d\n", ft_isprint('\n'), isprint('\n'));
	printf("ft_strlen : %lu strlen : %lu\n", ft_strlen("123456"), strlen("123456"));
	//ft_memset
	char	s[100] = "Test memset123456";

	printf("ft_memset : %s memset : %s\n", ft_memset(s, 'a', 3), memset(s, 'a', 3));
	//ft_bzero && memcpy
	char	*dest;
	char	src[100] = "test the ft_memcpy 125645";
	int		i;

	i = 0;
	dest = malloc(100);
	dest = ft_memcpy(dest, src, 20);
	while (i < 20)
	{
		printf("%c", dest[i]);
		i++;
	}
	printf("\n^ft_memcpy^\n");
	free(dest);
	
	char    src2[100] = "test the memcpy 125645";
	dest = malloc(100);
    dest = memcpy(dest, src2, 20);
    i = 0;
	while (i < 20)
    {
        printf("%c", dest[i]);
        i++;
    }
    printf("\n^memcpy^");
    free(dest);

	return (0);
}*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include <stdio.h>

static void		check_strlcat(char *dest, char *src, int size, int dest_len)
{
	printf("Resultat : %lu\n", ft_strlcat(dest, src, size));
	write(1, "\n", 1);
	write(1, dest, dest_len);
	free(dest);
}

int				main(int argc, const char *argv[])
{
	char	*dest;
	int		arg;
	int		dest_len;

	alarm(5);
	dest_len = 15;
	if (!(dest = (char *)malloc(sizeof(*dest) * dest_len)) || argc == 1)
		return (0);
	memset(dest, 0, dest_len);
	memset(dest, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
	{
		dest[11] = 'a';
		check_strlcat(dest, "lorem", 15, dest_len);
	}
	else if (arg == 2)
		check_strlcat(dest, "", 15, dest_len);
	else if (arg == 3)
	{
		dest[0] = '\0';
		dest[11] = 'a';
		check_strlcat(dest, "lorem ipsum", 15, dest_len);
	}
	else if (arg == 4)
	{
		dest[14] = 'a';
		check_strlcat(dest, "lorem ipsum dolor sit amet", 15, dest_len);
	}
	else if (arg == 5)
	{
		dest[10] = 'a';
		check_strlcat(dest, "lorem ipsum dolor sit amet", 0, dest_len);
	}
	else if (arg == 6)
	{
		dest[10] = 'a';
		check_strlcat(dest, "lorem ipsum dolor sit amet", 1, dest_len);
	}
	else if (arg == 7)
	{
		memset(dest, 'r', 15);
		check_strlcat(dest, "lorem ipsum dolor sit amet", 5, dest_len);
	}
	else if (arg == 8)
	{
		dest[10] = 'a';
		check_strlcat(dest, "lorem ipsum dolor sit amet", 6, dest_len);
	}
	else if (arg == 9)
	{
		memset(dest, 'r', 14);
		check_strlcat(dest, "lorem ipsum dolor sit amet", 15, dest_len);
	}
	return (0);
}
