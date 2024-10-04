/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:55:37 by ego               #+#    #+#             */
/*   Updated: 2024/10/04 16:11:32 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	int	success = 0;

	printf("===========================\n");
	printf("%s     Beginning testing     %s\n", ITALIC, RESET);
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
	success += test_ft_toupper();
	success += test_ft_tolower();
	success += test_ft_strchr();
	success += test_ft_strrchr();
	success += test_ft_memchr();
	success += test_ft_memcmp();
	success += test_ft_strncmp();
	success += test_ft_strnstr();
	success += test_ft_atoi();
	success += test_ft_calloc();
	success += test_ft_strdup();
	success += test_ft_substr();
	success += test_ft_strjoin();
	success += test_ft_strtrim();
	success += test_ft_split();
	success += test_ft_itoa();
	printf("===========================\n");
	if (success == 28)
		printf("%s%slibft: OK!%s\n", GREEN, BOLD, RESET);
	else
		printf("%s%slibft: failed%s\n", RED, BOLD, RESET);
}
