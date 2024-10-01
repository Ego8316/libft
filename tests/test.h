/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:56:00 by ego               #+#    #+#             */
/*   Updated: 2024/10/02 00:18:08 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define BOLD	"\033[1m"
# define ITALIC	"\033[3m"

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include "../libft.h"
# include <bsd/string.h>

int	test_ft_isalpha(void);
int	test_ft_isascii(void);
int	test_ft_isalnum(void);
int	test_ft_isdigit(void);
int	test_ft_isprint(void);
int	test_ft_strlen(void);
int	test_ft_memset(void);
int	test_ft_bzero(void);
int	test_ft_memcpy(void);
int	test_ft_memmove(void);
int test_ft_strlcpy(void);
int test_ft_strlcat(void);
int	test_ft_toupper(void);
int	test_ft_tolower(void);
int	test_ft_strchr(void);
int	test_ft_strrchr(void);
int	test_ft_memchr(void);
int	test_ft_memcmp(void);
int test_ft_strncmp(void);
int	test_ft_strnstr(void);
int	test_ft_atoi(void);
int	test_ft_calloc(void);
int	test_ft_strdup(void);
int	test_ft_substr(void);

#endif