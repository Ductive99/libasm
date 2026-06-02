/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:31:21 by esouhail          #+#    #+#             */
/*   Updated: 2026/06/02 16:31:32 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strlen(void);

i32	main(void)
{
	test_ft_strlen();
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
