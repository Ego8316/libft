/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:55:37 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 17:13:44 by hcavet           ###   ########.fr       */
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
	success += test_ft_memcpy();
	success += test_ft_memmove();
	success += test_ft_strlcpy();
	success += test_ft_strlcat();
	printf("===========================\n");
	if (success == 12)
		printf("%s%slibft: OK!%s\n", GREEN, BOLD, RESET);
	else
		printf("%s%slibft: failed%s\n", RED, BOLD, RESET);
}
