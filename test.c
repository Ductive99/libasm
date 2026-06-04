/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:31:21 by esouhail          #+#    #+#             */
/*   Updated: 2026/06/04 15:30:46 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strlen(void);
void	test_ft_strcmp(void);
void	test_ft_strcpy(void);
void	test_ft_write(void);
void	test_ft_read(void);
void	test_ft_strdup(void);

i32	main(void)
{
	test_ft_strlen();
	test_ft_strcmp();
	test_ft_strcpy();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
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

void	test_ft_strcpy(void)
{
	char	ft[256];
	char	std[256];
	char	*r;

	printf("\n==========     FT_STRCPY TESTS     ==========\n");

	// --- basic string ---
	r = ft_strcpy(ft, "hello"); strcpy(std, "hello");
	assert(strcmp(ft, std) == 0 && r == ft);
	printf(">%s<:\n\tft_strcpy: \"%s\", strcpy: \"%s\"\n\n", "hello", ft, std);

	// --- empty string ---
	r = ft_strcpy(ft, ""); strcpy(std, "");
	assert(strcmp(ft, std) == 0 && r == ft);
	printf(">%s<:\n\tft_strcpy: \"%s\", strcpy: \"%s\"\n\n", "(empty)", ft, std);

	// --- single char ---
	r = ft_strcpy(ft, "A"); strcpy(std, "A");
	assert(strcmp(ft, std) == 0 && r == ft);
	printf(">%s<:\n\tft_strcpy: \"%s\", strcpy: \"%s\"\n\n", "A", ft, std);

	// --- spaces ---
	r = ft_strcpy(ft, "hello world  !"); strcpy(std, "hello world  !");
	assert(strcmp(ft, std) == 0 && r == ft);
	printf(">%s<:\n\tft_strcpy: \"%s\", strcpy: \"%s\"\n\n", "hello world  !", ft, std);

	// --- overwrite existing content ---
	memcpy(ft, "old_content\0", 12); memcpy(std, "old_content\0", 12);
	r = ft_strcpy(ft, "new"); strcpy(std, "new");
	assert(strcmp(ft, std) == 0 && r == ft);
	printf(">%s< over \"old_content\":\n\tft_strcpy: \"%s\", strcpy: \"%s\"\n\n", "new", ft, std);

	// --- long string ---
	const char	*lng = "abcdefghijklmnopqrstuvwxyz0123456789";
	r = ft_strcpy(ft, lng); strcpy(std, lng);
	assert(strcmp(ft, std) == 0 && r == ft);
	printf(">%s<:\n\tft_strcpy: \"%s\", strcpy: \"%s\"\n\n", lng, ft, std);

	// --- high ASCII (unsigned byte behavior) ---
	r = ft_strcpy(ft, "\x7f\xc8\xff"); strcpy(std, "\x7f\xc8\xff");
	assert(strcmp(ft, std) == 0 && r == ft);
	printf(">\\x7f\\xc8\\xff<:\n\tft_strcpy: match: %s\n\n", strcmp(ft, std) == 0 ? "yes" : "no");

	// --- return value points to dst ---
	char	buf[64];
	r = ft_strcpy(buf, "retval check");
	assert(r == buf);
	printf(">retval check<:\n\treturn == dst: %s\n\n", r == buf ? "yes" : "no");
}

void	test_ft_write(void)
{
	const char *s = "Hello World!";
	int	len = strlen(s);

	printf("\n==========     FT_WRITE  TESTS     ==========\n");

	for (int i = 0; i <= len; i += 3)
	{
		write(1, &"ft_write >", 10);
		int	m = ft_write(1, s, i);
		write(1, &"<\n", 2);

		write(1, &"   write >", 10);
		int	n = write(1, s, i);
		write(1, &"<\n\n", 3);

		assert(m == n);
	}
}

void	test_ft_read(void)
{
	int		ft_pfd[2];
	int		std_pfd[2];
	char	ft_buf[256];
	char	std_buf[256];
	ssize_t	ft_ret;
	ssize_t	std_ret;

	printf("\n==========     FT_READ TESTS     ==========\n");

	// --- basic read ---
	memset(ft_buf, 0, 256); memset(std_buf, 0, 256);
	pipe(ft_pfd); pipe(std_pfd);
	write(ft_pfd[1], "hello", 5); close(ft_pfd[1]);
	write(std_pfd[1], "hello", 5); close(std_pfd[1]);
	ft_ret = ft_read(ft_pfd[0], ft_buf, 5);
	std_ret = read(std_pfd[0], std_buf, 5);
	close(ft_pfd[0]); close(std_pfd[0]);
	assert(ft_ret == std_ret && memcmp(ft_buf, std_buf, ft_ret) == 0);
	printf(">(basic) \"hello\" (5 bytes)<:\n\tft_read: \"%.*s\" ret=%zd, read: \"%.*s\" ret=%zd\n\n",
			(int)ft_ret, ft_buf, ft_ret, (int)std_ret, std_buf, std_ret);

	// --- partial read (request less than available) ---
	memset(ft_buf, 0, 256); memset(std_buf, 0, 256);
	pipe(ft_pfd); pipe(std_pfd);
	write(ft_pfd[1], "hello world", 11); close(ft_pfd[1]);
	write(std_pfd[1], "hello world", 11); close(std_pfd[1]);
	ft_ret = ft_read(ft_pfd[0], ft_buf, 5);
	std_ret = read(std_pfd[0], std_buf, 5);
	close(ft_pfd[0]); close(std_pfd[0]);
	assert(ft_ret == std_ret && memcmp(ft_buf, std_buf, ft_ret) == 0);
	printf(">(partial) \"hello world\", read 5<:\n\tft_read: \"%.*s\" ret=%zd, read: \"%.*s\" ret=%zd\n\n",
			(int)ft_ret, ft_buf, ft_ret, (int)std_ret, std_buf, std_ret);

	// --- count = 0 ---
	memset(ft_buf, 0, 256); memset(std_buf, 0, 256);
	pipe(ft_pfd); pipe(std_pfd);
	write(ft_pfd[1], "hello", 5); close(ft_pfd[1]);
	write(std_pfd[1], "hello", 5); close(std_pfd[1]);
	ft_ret = ft_read(ft_pfd[0], ft_buf, 0);
	std_ret = read(std_pfd[0], std_buf, 0);
	close(ft_pfd[0]); close(std_pfd[0]);
	assert(ft_ret == std_ret && ft_ret == 0);
	printf(">(count=0) \"hello\", read 0<:\n\tft_read: ret=%zd, read: ret=%zd\n\n",
			ft_ret, std_ret);

	// --- over-read (request more than available, write end closed) ---
	memset(ft_buf, 0, 256); memset(std_buf, 0, 256);
	pipe(ft_pfd); pipe(std_pfd);
	write(ft_pfd[1], "hi", 2); close(ft_pfd[1]);
	write(std_pfd[1], "hi", 2); close(std_pfd[1]);
	ft_ret = ft_read(ft_pfd[0], ft_buf, 128);
	std_ret = read(std_pfd[0], std_buf, 128);
	close(ft_pfd[0]); close(std_pfd[0]);
	assert(ft_ret == std_ret && memcmp(ft_buf, std_buf, ft_ret) == 0);
	printf(">(over-read) \"hi\", read 128<:\n\tft_read: \"%.*s\" ret=%zd, read: \"%.*s\" ret=%zd\n\n",
			(int)ft_ret, ft_buf, ft_ret, (int)std_ret, std_buf, std_ret);

	// --- EOF (read after all data already consumed) ---
	memset(ft_buf, 0, 256); memset(std_buf, 0, 256);
	pipe(ft_pfd); pipe(std_pfd);
	write(ft_pfd[1], "hi", 2); close(ft_pfd[1]);
	write(std_pfd[1], "hi", 2); close(std_pfd[1]);
	read(ft_pfd[0], ft_buf, 2);
	read(std_pfd[0], std_buf, 2);
	memset(ft_buf, 0, 256); memset(std_buf, 0, 256);
	ft_ret = ft_read(ft_pfd[0], ft_buf, 5);
	std_ret = read(std_pfd[0], std_buf, 5);
	close(ft_pfd[0]); close(std_pfd[0]);
	assert(ft_ret == 0 && ft_ret == std_ret);
	printf(">(EOF) after consuming all data<:\n\tft_read: ret=%zd, read: ret=%zd\n\n",
			ft_ret, std_ret);

	// --- binary data ---
	memset(ft_buf, 0, 256); memset(std_buf, 0, 256);
	pipe(ft_pfd); pipe(std_pfd);
	write(ft_pfd[1], "\x01\x7f\xff\x00\xab", 5); close(ft_pfd[1]);
	write(std_pfd[1], "\x01\x7f\xff\x00\xab", 5); close(std_pfd[1]);
	ft_ret = ft_read(ft_pfd[0], ft_buf, 5);
	std_ret = read(std_pfd[0], std_buf, 5);
	close(ft_pfd[0]); close(std_pfd[0]);
	assert(ft_ret == std_ret && memcmp(ft_buf, std_buf, ft_ret) == 0);
	printf(">(binary) \\x01\\x7f\\xff\\x00\\xab<:\n\tft_read: ret=%zd, read: ret=%zd, match: %s\n\n",
			ft_ret, std_ret, memcmp(ft_buf, std_buf, ft_ret) == 0 ? "yes" : "no");

	// --- invalid fd: errno must be set to EBADF ---
	errno = 0;
	ft_ret = ft_read(-1, ft_buf, 5);
	int	ft_errno = errno;
	errno = 0;
	std_ret = read(-1, std_buf, 5);
	int	std_errno = errno;
	assert(ft_ret == -1 && ft_ret == std_ret && ft_errno == std_errno);
	printf(">(invalid fd=-1)<:\n\tft_read: ret=%zd errno=%d (%s)\n\tread:    ret=%zd errno=%d (%s)\n\n",
			ft_ret, ft_errno, strerror(ft_errno),
			std_ret, std_errno, strerror(std_errno));

	// --- closed fd: errno must be set to EBADF ---
	{
		int	fd = open("/dev/null", O_RDONLY);
		close(fd);
		errno = 0;
		ft_ret = ft_read(fd, ft_buf, 5);
		ft_errno = errno;
		errno = 0;
		std_ret = read(fd, std_buf, 5);
		std_errno = errno;
		assert(ft_ret == -1 && ft_ret == std_ret && ft_errno == std_errno);
		printf(">(closed fd)<:\n\tft_read: ret=%zd errno=%d (%s)\n\tread:    ret=%zd errno=%d (%s)\n\n",
				ft_ret, ft_errno, strerror(ft_errno),
				std_ret, std_errno, strerror(std_errno));
	}

	// --- long string ---
	{
		const char	*lng = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		size_t		lng_len = strlen(lng);
		memset(ft_buf, 0, 256); memset(std_buf, 0, 256);
		pipe(ft_pfd); pipe(std_pfd);
		write(ft_pfd[1], lng, lng_len); close(ft_pfd[1]);
		write(std_pfd[1], lng, lng_len); close(std_pfd[1]);
		ft_ret = ft_read(ft_pfd[0], ft_buf, lng_len);
		std_ret = read(std_pfd[0], std_buf, lng_len);
		close(ft_pfd[0]); close(std_pfd[0]);
		assert(ft_ret == (ssize_t)lng_len && ft_ret == std_ret
				&& memcmp(ft_buf, std_buf, ft_ret) == 0);
		printf(">(long string) %zu bytes<:\n\tft_read: \"%.*s\" ret=%zd\n\tread:    \"%.*s\" ret=%zd\n\n",
				lng_len, (int)ft_ret, ft_buf, ft_ret, (int)std_ret, std_buf, std_ret);
	}
}
void	test_ft_strdup(void)
{
	char	*my_dup, *std_dup;

	printf("\n==========      FT_STRDUP TESTS      ==========\n");

	const char	*s1 = "Hello World!!!";
	my_dup = ft_strdup(s1); std_dup = strdup(s1); assert(strcmp(my_dup, std_dup) == 0);
	printf(">%s<:\n\tft_strdup: %s, strdup: %s\n\n", s1, my_dup, std_dup);
	free(my_dup); free(std_dup);

	const char	*s2 = "1234567890 1234567890 1234567890";
	my_dup = ft_strdup(s2); std_dup = strdup(s2); assert(strcmp(my_dup, std_dup) == 0);
	printf(">%s<:\n\tft_strdup: %s, strdup: %s\n\n", s2, my_dup, std_dup);
	free(my_dup); free(std_dup);

	const char	*s3 = "";
	my_dup = ft_strdup(s3); std_dup = strdup(s3); assert(strcmp(my_dup, std_dup) == 0);
	printf(">%s<:\n\tft_strdup: %s, strdup: %s\n\n", s3, my_dup, std_dup);
	free(my_dup); free(std_dup);
}
