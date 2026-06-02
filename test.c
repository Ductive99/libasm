/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:31:21 by esouhail          #+#    #+#             */
/*   Updated: 2026/06/02 18:42:32 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strlen(void);
void	test_ft_strcmp(void);

i32	main(void)
{
	test_ft_strlen();
	test_ft_strcmp();
}

void	test_ft_strlen(void)
{
	size_t	mylen, len;

	printf("\n==========     FT_STRLEN TESTS     ==========\n");

	const char	*s1 = "Hello World!!!";
	mylen = ft_strlen(s1); len = strlen(s1); assert(mylen == len);
	printf(">%s<:\n\tft_strlen: %ld, strlen: %ld\n\n", s1, mylen, len); 

	const char	*s2 = "1234567890 1234567890 1234567890";
	mylen = ft_strlen(s2); len = strlen(s2); assert(mylen == len);
	printf(">%s<:\n\tft_strlen: %ld, strlen: %ld\n\n", s2, mylen, len);

	const char	*s3 = "";
	mylen = ft_strlen(s3); len = strlen(s3); assert(mylen == len);
	printf(">%s<:\n\tft_strlen: %ld, strlen: %ld\n\n", s3, mylen, len);
}

void	test_ft_strcmp(void)
{
	int	mylen, len;

	printf("\n==========     FT_STRCMP TESTS     ==========\n");

	const char	*s1 = "Hello World!!!";
	mylen = ft_strcmp(s1, s1); len = strcmp(s1, s1); assert(mylen == len);
	printf(">%s<\t>%s<:\n\tft_strcmp: %d, strcmp: %d\n\n", s1, s1, mylen, len);

	const char	*s3 = "abc";
	const char	*s4 = "aba";
	mylen = ft_strcmp(s3, s4); len = strcmp(s3, s4); assert(mylen > 0 && len > 0);
	printf(">%s<\t>%s<:\n\tft_strcmp: %d, strcmp: %d\n\n", s3, s4, mylen, len); 

	const char	*s5 = "aba";
	const char	*s6 = "abc";
	mylen = ft_strcmp(s5, s6); len = strcmp(s5, s6); assert(mylen < 0 && len < 0);
	printf(">%s<\t>%s<:\n\tft_strcmp: %d, strcmp: %d\n\n", s5, s6, mylen, len);
	
	// --- empty strings ---
	mylen = ft_strcmp("", ""); len = strcmp("", "");
	assert(mylen == len);
	printf(">%s<\t>%s<:\n\tft_strcmp: %d, strcmp: %d\n\n", "", "", mylen, len);

	// --- one empty, one not ---
	mylen = ft_strcmp("", "abc"); len = strcmp("", "abc");
	assert(mylen < 0 && len < 0);
	printf(">%s<\t>%s<:\n\tft_strcmp: %d, strcmp: %d\n\n", "", "abc", mylen, len);

	// --- differ only at first char ---
	mylen = ft_strcmp("bbc", "abc"); len = strcmp("bbc", "abc");
	assert(mylen > 0 && len > 0);
	printf(">%s<\t>%s<:\n\tft_strcmp: %d, strcmp: %d\n\n", "bbc", "abc", mylen, len);

	// --- prefix: s1 is shorter ---
	mylen = ft_strcmp("ab", "abc"); len = strcmp("ab", "abc");
	assert(mylen < 0 && len < 0);
	printf(">%s<\t>%s<:\n\tft_strcmp: %d, strcmp: %d\n\n", "ab", "abc", mylen, len);

	// --- prefix: s1 is longer ---
	mylen = ft_strcmp("abc", "ab"); len = strcmp("abc", "ab");
	assert(mylen > 0 && len > 0);
	printf(">%s<\t>%s<:\n\tft_strcmp: %d, strcmp: %d\n\n", "abc", "ab", mylen, len);

	// --- high ASCII (unsigned byte behavior) ---
	mylen = ft_strcmp("\x80", "\x01"); len = strcmp("\x80", "\x01");
	assert(mylen > 0 && len > 0);
	printf(">\\x80<\t>\\x01<:\n\tft_strcmp: %d, strcmp: %d\n\n", mylen, len);
}
