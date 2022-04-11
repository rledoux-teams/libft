#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c);
int ft_isalnum(int c);

int main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	printf("ft_isalpha = %d isalpha = %d\n", ft_isalpha(*av[1]), isalpha(*av[1]));	
	printf("ft_isalpha = %d isalpha = %d\n", ft_isalnum(*av[1]), isalnum(*av[1]));
	return (0);
}
