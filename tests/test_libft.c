/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:55:37 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 14:47:38 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	int	success = 0;

	success += test_ft_isalpha();
	success += test_ft_isdigit();
	success += test_ft_isalnum();
	success += test_ft_isascii();
	success += test_ft_isprint();
	success += test_ft_strlen();
	success += test_ft_memset();
	success += test_ft_bzero();

	if (success == 8)
		printf("================\n%slibft: OK!%s\n", GREEN, RESET);
	else
		printf("================\n%slibft: failed%s\n", RED, RESET);
}
