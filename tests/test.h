/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:56:00 by ego               #+#    #+#             */
/*   Updated: 2024/10/01 14:43:07 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include "../libft.h"

int	test_ft_isalpha(void);
int	test_ft_isascii(void);
int	test_ft_isalnum(void);
int	test_ft_isdigit(void);
int	test_ft_isprint(void);
int	test_ft_strlen(void);
int	test_ft_memset(void);
int	test_ft_bzero(void);

#endif