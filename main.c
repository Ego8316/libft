/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:17:58 by ego               #+#    #+#             */
/*   Updated: 2024/10/04 16:07:29 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_power(int a, int n)
{
	if (n < 0)
		return (0);
	if (n > 0)
		return (a * ft_power(a, n - 1));
	return (1);
}

static int	ft_itoa_count_digits(int n)
{
	int	digits;

	if (!n)
		return (1);
	digits = 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*nptr;
	int		digits;
	int		i;

	digits = ft_itoa_count_digits(n);
	nptr = (char *)malloc((digits + (n < 0) + 1) * sizeof(char));
	if (!nptr)
		return (NULL);
	if (n < 0)
		nptr[0] = '-';
	i = n < 0;
	while (digits > 0)
	{
		nptr[i] = '0' + n / ((1 - 2 * (n < 0)) * ft_power(10, digits - 1));
		n %= (1 - 2 * (n < 0)) * ft_power(10, digits - 1);
		i++;
		digits--;
	}
	nptr[i] = '\0';
	return (nptr);
}

int	main(int argc, char **argv)
{
	char	*nptr;

	(void)argc;
	printf(">>>%i\n", ft_itoa_count_digits(atoi(argv[1])));
	nptr = ft_itoa(atoi(argv[1]));
	printf(">\"%s\"\n", nptr);
	free(nptr);
	return (0);
}
