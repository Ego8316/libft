/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:17:58 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 22:39:41 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>


char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little == "")
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		printf("pe");
		j = 0;
		while (big[i] == little[j] && big[i] && i < len)
		{
			i++;
			j++;
		}
		if (!little[j])
			return ((char *)(big + i - j));
		i += 1 - j;
	}
	return (NULL);
}
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i	= 0;
	sign = 1;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = -(nptr[i] - 44);
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}


int	main(int argc, char **argv)
{
	(void)argc;
	printf(">%i\n>%i\n", atoi(argv[1]), ft_atoi(argv[1]));
	return (0);
}
