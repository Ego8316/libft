/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:46:25 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 18:03:47 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_strlcpy(void)
{
    int success = 0;
    char dest1[20];
    char dest2[20];
    size_t len1, len2;

    // Test 1: Simple string copy
    strcpy(dest1, "initial");
    strcpy(dest2, "initial");
    len1 = strlcpy(dest1, "hello", sizeof(dest1));
    len2 = ft_strlcpy(dest2, "hello", sizeof(dest2));
    if (len1 == len2 && strcmp(dest1, dest2) == 0)
        success++;
	else
		printf("%sft_strlcpy.c\t:\tTest 1 failed: expected %s and %lu, got %s and %lu.%s\n", RED, dest1, len1, dest2, len2, RESET);

    // Test 2: Destination buffer size is smaller than source string
    strcpy(dest1, "initial");
    strcpy(dest2, "initial");
    len1 = strlcpy(dest1, "hello", 3);  // Only copy "he"
    len2 = ft_strlcpy(dest2, "hello", 3);
    if (len1 == len2 && strcmp(dest1, dest2) == 0)
        success++;
	else
		printf("%sft_strlcpy.c\t:\tTest 2 failed: expected %s and %lu, got %s and %lu.%s\n", RED, dest1, len1, dest2, len2, RESET);

    // Test 3: Destination buffer size is 0 (shouldn't copy anything)
    strcpy(dest1, "initial");
    strcpy(dest2, "initial");
    len1 = strlcpy(dest1, "hello", 0);  // No copy should occur
    len2 = ft_strlcpy(dest2, "hello", 0);
    if (len1 == len2 && strcmp(dest1, dest2) == 0)
        success++;
	else
		printf("%sft_strlcpy.c\t:\tTest 3 failed: expected %s and %lu, got %s and %lu.%s\n", RED, dest1, len1, dest2, len2, RESET);

    // Test 4: Copy entire string with exact size
    strcpy(dest1, "initial");
    strcpy(dest2, "initial");
    len1 = strlcpy(dest1, "hello", 6);  // Exact size, should copy all "hello"
    len2 = ft_strlcpy(dest2, "hello", 6);
    if (len1 == len2 && strcmp(dest1, dest2) == 0)
        success++;
	else
		printf("%sft_strlcpy.c\t:\tTest 4 failed: expected %s and %lu, got %s and %lu.%s\n", RED, dest1, len1, dest2, len2, RESET);

    // Test 5: Copy an empty string
    strcpy(dest1, "initial");
    strcpy(dest2, "initial");
    len1 = strlcpy(dest1, "", sizeof(dest1));  // Empty string should result in null terminator
    len2 = ft_strlcpy(dest2, "", sizeof(dest2));
    if (len1 == len2 && strcmp(dest1, dest2) == 0)
        success++;
	else
		printf("%sft_strlcpy.c\t:\tTest 5 failed: expected %s and %lu, got %s and %lu.%s\n", RED, dest1, len1, dest2, len2, RESET);

    if (success == 5)
	{
		printf("%sft_strlcpy.c\t:\tOK!%s\n", GREEN, RESET);
		return (1);
	}
	else
	{
		printf("%sft_strlcpy.c\t:\tfailed (%i/5)%s\n", RED, success, RESET);
		return (0);
	}
}
