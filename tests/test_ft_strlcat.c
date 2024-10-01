/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:07:25 by hcavet            #+#    #+#             */
/*   Updated: 2024/10/01 17:14:16 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_strlcat(void)
{
    int success = 0;
    char dest1[20];
    char dest2[20];
    size_t len1, len2;

    // Test 1: Simple string concatenation
    strcpy(dest1, "initial");
    strcpy(dest2, "initial");
    len1 = strlcat(dest1, " hello", sizeof(dest1));
    len2 = ft_strlcat(dest2, " hello", sizeof(dest2));
    if (len1 == len2 && strcmp(dest1, dest2) == 0)
        success++;
    else
        printf("%sft_strlcat.c\t:\tTest 1 failed: expected %s and %lu, got %s and %lu.%s\n", RED, dest1, len1, dest2, len2, RESET);

    // Test 2: Destination buffer size smaller than concatenated string
    strcpy(dest1, "init");
    strcpy(dest2, "init");
    len1 = strlcat(dest1, " hello", 7);  // Only part of " hello" should be copied
    len2 = ft_strlcat(dest2, " hello", 7);
    if (len1 == len2 && strcmp(dest1, dest2) == 0)
        success++;
    else
        printf("%sft_strlcat.c\t:\tTest 2 failed: expected %s and %lu, got %s and %lu.%s\n", RED, dest1, len1, dest2, len2, RESET);

    // Test 3: Destination buffer size is 0 (shouldn't copy anything)
    strcpy(dest1, "init");
    strcpy(dest2, "init");
    len1 = strlcat(dest1, " hello", 0);  // No copy should occur
    len2 = ft_strlcat(dest2, " hello", 0);
    if (len1 == len2 && strcmp(dest1, dest2) == 0)
        success++;
    else
        printf("%sft_strlcat.c\t:\tTest 3 failed: expected %s and %lu, got %s and %lu.%s\n", RED, dest1, len1, dest2, len2, RESET);

    // Test 4: Copy entire string with exact buffer size
    strcpy(dest1, "init");
    strcpy(dest2, "init");
    len1 = strlcat(dest1, " hello", 12);  // Should copy the entire " hello"
    len2 = ft_strlcat(dest2, " hello", 12);
    if (len1 == len2 && strcmp(dest1, dest2) == 0)
        success++;
    else
        printf("%sft_strlcat.c\t:\tTest 4 failed: expected %s and %lu, got %s and %lu.%s\n", RED, dest1, len1, dest2, len2, RESET);

    // Test 5: Append empty string
    strcpy(dest1, "initial");
    strcpy(dest2, "initial");
    len1 = strlcat(dest1, "", sizeof(dest1));  // Nothing to append
    len2 = ft_strlcat(dest2, "", sizeof(dest2));
    if (len1 == len2 && strcmp(dest1, dest2) == 0)
        success++;
    else
        printf("%sft_strlcat.c\t:\tTest 5 failed: expected %s and %lu, got %s and %lu.%s\n", RED, dest1, len1, dest2, len2, RESET);

    if (success == 5)
    {
        printf("%sft_strlcat.c\t:\tOK!%s\n", GREEN, RESET);
        return (1);
    }
    else
    {
        printf("%sft_strlcat.c\t:\tfailed (%i/5)%s\n", RED, success, RESET);
        return (0);
    }
}
