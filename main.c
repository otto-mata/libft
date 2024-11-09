/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:29:32 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/09 10:39:33 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL


uint64_t hash(void *area, size_t n)
{
	uint64_t hash;
	unsigned char *p;
	size_t i;

	hash = FNV_OFFSET;
	p = area;
	i = 0;
	while (i < n)
	{
		hash ^= (uint64_t)(p[i]);
		hash *= FNV_PRIME;
		i++;
	}
	return (hash);
}

char toupper_wrapper(uint32_t i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

char tolower_wrapper(uint32_t i, char c)
{
	(void)i;
	return (ft_tolower(c));
}
void void_toupper_wrapper(uint32_t i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

void void_tolower_wrapper(uint32_t i, char *c)
{
	(void)i;
	*c = ft_tolower(*c);
}

void	seeding_magic(void)
{
	void 		*urandom = calloc(128, sizeof(uint8_t));
	int const	fd = open("/dev/urandom", O_RDONLY);

	if (!fd)
		return (srand(time(0)));
	if (read(fd, urandom, 128) != 128)
		return (srand(time(0)));
	srand(hash(urandom, 128));
	free(urandom);

}

char	*random_string(size_t sz)
{
	char	*s;
	size_t	i;
	char	c;

	s = calloc(sz + 1, sizeof(char));
	if (!s)
		return (0);
	i = 0;
	c = 0;
	while (i < sz)
	{
		while (!isalnum(c))
			c = rand() % (122 + 1 - 48) + 48;
		s[i] = c;
		c = 0;
		i++;
	}
	return (s);
}

int main(void)
{
	seeding_magic();
	/* printf("TEST WILL COMMENCE. BE PREPARED, OR DIE.\n");
	printf("Part 1 - Libc Functions\n");
	printf("ft_isalpha()");
	assert(!!ft_isalnum(45) == !!isalnum(45));
	assert(!!ft_isalnum(7687) == !!isalnum(7687));
	assert(!!ft_isalnum(0) == !!isalnum(0));
	assert(!!ft_isalnum('0') == !!isalnum('0'));
	assert(!!ft_isalnum(127) == !!isalnum(127));
	assert(!!ft_isalnum('9') == !!isalnum('9'));
	assert(!!ft_isalnum('a') == !!isalnum('a'));
	assert(!!ft_isalnum(' ') == !!isalnum(' '));
	assert(!!ft_isalnum('\t') == !!isalnum('\t'));
	assert(!!ft_isalnum('+') == !!isalnum('+'));
	printf(" - OK\n");
	printf("ft_isdigit()");
	assert(!!ft_isalnum(45) == !!isalnum(45));
	assert(!!ft_isalnum(7687) == !!isalnum(7687));
	assert(!!ft_isalnum(0) == !!isalnum(0));
	assert(!!ft_isalnum('0') == !!isalnum('0'));
	assert(!!ft_isalnum(127) == !!isalnum(127));
	assert(!!ft_isalnum('9') == !!isalnum('9'));
	assert(!!ft_isalnum('a') == !!isalnum('a'));
	assert(!!ft_isalnum(' ') == !!isalnum(' '));
	assert(!!ft_isalnum('\t') == !!isalnum('\t'));
	assert(!!ft_isalnum('+') == !!isalnum('+'));
	printf(" - OK\n");
	printf("ft_isalnum()");
	assert(!!ft_isalnum(45) == !!isalnum(45));
	assert(!!ft_isalnum(7687) == !!isalnum(7687));
	assert(!!ft_isalnum(0) == !!isalnum(0));
	assert(!!ft_isalnum('0') == !!isalnum('0'));
	assert(!!ft_isalnum(127) == !!isalnum(127));
	assert(!!ft_isalnum('9') == !!isalnum('9'));
	assert(!!ft_isalnum('a') == !!isalnum('a'));
	assert(!!ft_isalnum(' ') == !!isalnum(' '));
	assert(!!ft_isalnum('\t') == !!isalnum('\t'));
	assert(!!ft_isalnum('+') == !!isalnum('+'));
	printf(" - OK\n");
	printf("ft_isascii()");
	assert(!!ft_isascii(45) == !!isascii(45));
	assert(!!ft_isascii(7687) == !!isascii(7687));
	assert(!!ft_isascii(0) == !!isascii(0));
	assert(!!ft_isascii('0') == !!isascii('0'));
	assert(!!ft_isascii(127) == !!isascii(127));
	assert(!!ft_isascii('9') == !!isascii('9'));
	assert(!!ft_isascii('a') == !!isascii('a'));
	assert(!!ft_isascii(' ') == !!isascii(' '));
	assert(!!ft_isascii('\t') == !!isascii('\t'));
	assert(!!ft_isascii('+') == !!isascii('+'));
	printf(" - OK\n");
	printf("ft_isprint()");
	assert(!!ft_isprint(45) == !!isprint(45));
	assert(!!ft_isprint(7687) == !!isprint(7687));
	assert(!!ft_isprint(0) == !!isprint(0));
	assert(!!ft_isprint('0') == !!isprint('0'));
	assert(!!ft_isprint(127) == !!isprint(127));
	assert(!!ft_isprint('9') == !!isprint('9'));
	assert(!!ft_isprint('a') == !!isprint('a'));
	assert(!!ft_isprint(' ') == !!isprint(' '));
	assert(!!ft_isprint('\t') == !!isprint('\t'));
	assert(!!ft_isprint('+') == !!isprint('+'));
	printf(" - OK\n");
	printf("ft_strlen()");
	assert(ft_strlen("hello world") == strlen("hello world"));
	assert(ft_strlen("\0") == strlen("\0"));
	assert(ft_strlen("") == strlen(""));
	printf(" - OK\n");
	printf("ft_memset()");
	void *ptr = malloc(64);
	memset(ptr, 42, 64);
	uint64_t chksum = hash(ptr, 64);
	ft_memset(ptr, 42, 64);
	assert(hash(ptr, 64) == chksum);
	memset(ptr, 0, 64);
	chksum = hash(ptr, 64);
	memset(ptr, 1, 64);
	ft_memset(ptr, 0, 64);
	assert(hash(ptr, 64) == chksum);
	memset(ptr, 0, 0);
	chksum = hash(ptr, 0);
	ft_memset(ptr, 0, 0);
	assert(hash(ptr, 0) == chksum);
	memset(ptr, 0, 32);
	chksum = hash(ptr, 32);
	memset(ptr, 1, 32);
	ft_memset(ptr, 0, 32);
	assert(hash(ptr, 32) == chksum);
	printf(" - OK\n");
	printf("ft_bzero()");
	memcpy(ptr, "AGROUGOUGRAGRA RRAAAAAA LE MONSTRE", 64);
	bzero(ptr, 64);
	chksum = hash(ptr, 64);
	memcpy(ptr, "AGROUGOUGRAGRA RRAAAAAA LE MONSTRE", 64);
	ft_bzero(ptr, 64);
	assert(hash(ptr, 64) == chksum);
	printf(" - OK\n");
	printf("ft_memcpy()");
	memcpy(ptr, "OOOOOOOOH HOOOOOOO LE FANTOOOOMMMEEEEE", 64);
	chksum = hash(ptr, 64);
	bzero(ptr, 64);
	ft_memcpy(ptr, "OOOOOOOOH HOOOOOOO LE FANTOOOOMMMEEEEE", 64);
	assert(hash(ptr, 64) == chksum);
	printf(" - OK\n");
	printf("ft_memmove()");
	bzero(ptr, 64);
	memcpy(ptr, "wsh la zone c comment ou koi moi sava trql la sante tu coco hin", 64);
	memmove(ptr, ptr + 12, 52);
	chksum = hash(ptr, 64);
	bzero(ptr, 64);
	memcpy(ptr, "wsh la zone c comment ou koi moi sava trql la sante tu coco hin", 64);
	ft_memmove(ptr, ptr + 12, 52);
	assert(hash(ptr, 64) == chksum);
	bzero(ptr, 64);
	memcpy(ptr, "wsh la zone c comment ou koi moi sava trql la sante tu coco hin", 64);
	memmove(ptr + 12, ptr, 52);
	chksum = hash(ptr, 64);
	bzero(ptr, 64);
	memcpy(ptr, "wsh la zone c comment ou koi moi sava trql la sante tu coco hin", 64);
	ft_memmove(ptr + 12, ptr, 52);
	assert(hash(ptr, 64) == chksum);
	printf(" - OK\n");
	printf("ft_strlcpy()");
	bzero(ptr, 64);
	strlcpy(ptr, "hello world c comment", 13);
	chksum = hash(ptr, 64);
	bzero(ptr, 64);
	ft_strlcpy(ptr, "hello world c comment", 13);
	assert(hash(ptr, 64) == chksum);
	bzero(ptr, 64);
	strlcpy(ptr, "hello world c comment", 32);
	chksum = hash(ptr, 64);
	bzero(ptr, 64);
	ft_strlcpy(ptr, "hello world c comment", 32);
	assert(hash(ptr, 64) == chksum);
	bzero(ptr, 64);
	strlcpy(ptr, "hello world c comment", 0);
	chksum = hash(ptr, 64);
	bzero(ptr, 64);
	ft_strlcpy(ptr, "hello world c comment", 0);
	assert(hash(ptr, 64) == chksum);
	printf(" - OK\n");
	printf("ft_strlcat()");
	bzero(ptr, 64);
	strcpy(ptr, "Ceci est une phrase de test la team.");
	uint64_t ret = strlcat(ptr, " oe oe oe", strlen(ptr));
	chksum = hash(ptr, 64);
	bzero(ptr, 64);
	strcpy(ptr, "Ceci est une phrase de test la team.");
	assert(ft_strlcat(ptr, " oe oe oe", strlen(ptr)) == ret);
	assert(hash(ptr, 64) == chksum);
	printf(" - OK\n");
	printf("ft_toupper()");
	assert(!!ft_toupper(45) == !!toupper(45));
	assert(!!ft_toupper(7687) == !!toupper(7687));
	assert(!!ft_toupper(0) == !!toupper(0));
	assert(!!ft_toupper('0') == !!toupper('0'));
	assert(!!ft_toupper(127) == !!toupper(127));
	assert(!!ft_toupper('9') == !!toupper('9'));
	assert(!!ft_toupper('a') == !!toupper('a'));
	assert(!!ft_toupper('Z') == !!toupper('Z'));
	assert(!!ft_toupper(' ') == !!toupper(' '));
	assert(!!ft_toupper('\t') == !!toupper('\t'));
	assert(!!ft_toupper('+') == !!toupper('+'));
	printf(" - OK\n");
	printf("ft_tolower()");
	assert(!!ft_tolower(45) == !!tolower(45));
	assert(!!ft_tolower(7687) == !!tolower(7687));
	assert(!!ft_tolower(0) == !!tolower(0));
	assert(!!ft_tolower('0') == !!tolower('0'));
	assert(!!ft_tolower(127) == !!tolower(127));
	assert(!!ft_tolower('9') == !!tolower('9'));
	assert(!!ft_tolower('a') == !!tolower('a'));
	assert(!!ft_tolower('Z') == !!tolower('Z'));
	assert(!!ft_tolower(' ') == !!tolower(' '));
	assert(!!ft_tolower('\t') == !!tolower('\t'));
	assert(!!ft_tolower('+') == !!tolower('+'));
	printf(" - OK\n");
	printf("ft_strchr()");
	strcpy(ptr, "STRCHR TESTING oui oui oui *2343567");
	assert(ft_strchr(ptr, '\0') == strchr(ptr, '\0'));
	assert(ft_strchr(ptr, 'R') == strchr(ptr, 'R'));
	assert(ft_strchr(ptr, 'o') == strchr(ptr, 'o'));
	assert(ft_strchr(ptr, '|') == strchr(ptr, '|'));
	printf(" - OK\n");
	printf("ft_strrchr()");
	strcpy(ptr, "STrRCHR TESTING oui oui oui *2343567");
	assert(ft_strrchr(ptr, '\0') == strrchr(ptr, '\0'));
	assert(ft_strrchr(ptr, 'R') == strrchr(ptr, 'R'));
	assert(ft_strrchr(ptr, 'o') == strrchr(ptr, 'o'));
	assert(ft_strrchr(ptr, '|') == strrchr(ptr, '|'));
	printf(" - OK\n");
	printf("ft_strncmp()");
	int64_t sret = strncmp("aifbe", "wpeif", 5);
	if (sret < 0)
		assert(ft_strncmp("aifbe", "wpeif", 5) < 0);
	else if (sret > 0)
	{
		assert(ft_strncmp("aifbe", "wpeif", 5) > 0);
	}
	else
		assert(ft_strncmp("aifbe", "wpeif", 5) == 0);

	sret = strncmp("aifbe", "wpeif", 2);
	if (sret < 0)
		assert(ft_strncmp("aifbe", "wpeif", 2) < 0);
	else if (sret > 0)
		assert(ft_strncmp("aifbe", "wpeif", 2) > 0);
	else
		assert(ft_strncmp("aifbe", "wpeif", 2) == 0);

	sret = strncmp("aifbe", "wpeif", 0);
	if (sret < 0)
		assert(ft_strncmp("aifbe", "wpeif", 0) < 0);
	else if (sret > 0)
		assert(ft_strncmp("aifbe", "wpeif", 0) > 0);
	else
		assert(ft_strncmp("aifbe", "wpeif", 0) == 0);

	sret = strncmp("aifbe", "aifbe", 10);
	if (sret < 0)
		assert(ft_strncmp("aifbe", "aifbe", 10) < 0);
	else if (sret > 0)
		assert(ft_strncmp("aifbe", "aifbe", 10) > 0);
	else
		assert(ft_strncmp("aifbe", "aifbe", 10) == 0);

	printf(" - OK\n");
	printf("ft_memchr()");
	bzero(ptr, 64);
	strcpy(ptr, "memchr TESTING oui oui oui *2343567");
	assert(ft_memchr(ptr, '\0', 64) == memchr(ptr, '\0', 64));
	assert(ft_memchr(ptr, 'R', 64) == memchr(ptr, 'R', 64));
	assert(ft_memchr(ptr, 'o', 64) == memchr(ptr, 'o', 64));
	assert(ft_memchr(ptr, '|', 64) == memchr(ptr, '|', 64));
	printf(" - OK\n");
	printf("ft_memcmp()");
	sret = memcmp(ptr, &main, 10);
	if (sret < 0)
		assert(ft_memcmp(ptr, &main, 10) < 0);
	else if (sret > 0)
		assert(ft_memcmp(ptr, &main, 10) > 0);
	else
		assert(ft_memcmp(ptr, &main, 10) == 0);
	sret = memcmp(ptr, &main, 0);
	if (sret < 0)
		assert(ft_memcmp(ptr, &main, 0) < 0);
	else if (sret > 0)
		assert(ft_memcmp(ptr, &main, 0) > 0);
	else
		assert(ft_memcmp(ptr, &main, 0) == 0);
	sret = memcmp(ptr, &main, 64);
	if (sret < 0)
		assert(ft_memcmp(ptr, &main, 64) < 0);
	else if (sret > 0)
		assert(ft_memcmp(ptr, &main, 64) > 0);
	else
		assert(ft_memcmp(ptr, &main, 64) == 0);
	printf(" - OK\n");
	printf("ft_strnstr()");
	strcpy(ptr, "strnstr TESTING oui oui oui *2343567");
	assert(ft_strnstr(ptr, "TESTING", 64) == strnstr(ptr, "TESTING", 64));
	assert(ft_strnstr(ptr, "oui", 10) == strnstr(ptr, "oui", 10));
	assert(ft_strnstr(ptr, "oui ou", 21) == strnstr(ptr, "oui ou", 21));
	assert(ft_strnstr(ptr, "'|'", 64) == strnstr(ptr, "'|'", 64));
	printf(" - OK\n");
	printf("ft_atoi()");
	assert(ft_atoi("") == atoi(""));
	assert(ft_atoi("-56") == atoi("-56"));
	assert(ft_atoi("56q") == atoi("56q"));
	assert(ft_atoi("q+4") == atoi("q+4"));
	assert(ft_atoi("+4") == atoi("+4"));
	assert(ft_atoi("      ++4") == atoi("      ++4"));
	assert(ft_atoi("  \t\n--4") == atoi("  \t\n--4"));
	printf(" - OK\n");
	printf("ft_calloc()");
	int *int_arr = ft_calloc(2, sizeof(int));
	assert(int_arr);
	free(int_arr);
	int_arr = ft_calloc(0, sizeof(int));
	assert(int_arr);
	free(int_arr);
	int_arr = ft_calloc(2, 0);
	assert(int_arr);
	free(int_arr);
	int_arr = ft_calloc(0, 0);
	assert(int_arr);
	free(int_arr);
	printf(" - OK\n");
	printf("ft_strdup()");
	bzero(ptr, 64);
	strcpy(ptr, "RPIGHAPIHGPIAHG(_#$YT*)@#QIPHTQPIHT");
	char *s = ft_strdup(ptr);
	assert(strcmp(ptr, s) == 0);
	bzero(ptr, 64);
	strcpy(ptr, "");
	s = ft_strdup(ptr);
	assert(strcmp(ptr, s) == 0);
	printf(" - OK\n");
	printf("\n");
	printf("Part 2 - Additional Functions\n");
	printf("ft_substr()");
	free(s);
	s = ft_substr("hello world", 0, 5);
	assert(strlen(s) == 5);
	assert(strcmp(s, "hello") == 0);
	free(s);
	s = ft_substr("hello world", 6, 5);
	assert(strlen(s) == 5);
	assert(strcmp(s, "world") == 0);
	free(s);
	s = ft_substr("hello world", 10, 0);
	assert(strlen(s) == 0);
	assert(strcmp(s, "") == 0);
	free(s);
	s = ft_substr("hello world", 10, 128);
	assert(strlen(s) == strlen("hello world") - 10);
	assert(strcmp(s, &"hello world"[10]) == 0);
	printf(" - OK\n");
	printf("ft_strjoin()");
	free(s);
	s = ft_strjoin("hello", " world");
	assert(strlen(s) == strlen("hello world"));
	assert(strcmp(s, "hello world") == 0);
	free(s);
	s = ft_strjoin("", "");
	assert(strlen(s) == 0);
	assert(strcmp(s, "") == 0);
	free(s);
	s = ft_strjoin("", "thomas");
	assert(strlen(s) == 6);
	assert(strcmp(s, "thomas") == 0);
	free(s);
	s = ft_strjoin("thomas", "");
	assert(strlen(s) == 6);
	assert(strcmp(s, "thomas") == 0);
	free(s);
	s = ft_strjoin(" ", " ");
	assert(strlen(s) == 2);
	assert(strcmp(s, "  ") == 0);
	printf(" - OK\n");
	printf("ft_strtrim()");
	free(s);
	s = ft_strtrim("hello", "");
	assert(strlen(s) == strlen("hello"));
	assert(strcmp(s, "hello") == 0);
	free(s);
	s = ft_strtrim("", "");
	assert(strlen(s) == 0);
	assert(strcmp(s, "") == 0);
	free(s);
	s = ft_strtrim("", "_");
	assert(strlen(s) == 0);
	assert(strcmp(s, "") == 0);
	free(s);
	s = ft_strtrim("__hel_lo__", "_");
	assert(strlen(s) == 6);
	assert(strcmp(s, "hel_lo") == 0);
	free(s);
	s = ft_strtrim("hello___", "_");
	assert(strlen(s) == 5);
	assert(strcmp(s, "hello") == 0);
	free(s);
	s = ft_strtrim("___hello", "_");
	assert(strlen(s) == 5);
	assert(strcmp(s, "hello") == 0);
	free(s);
	s = ft_strtrim(" ", " ");
	assert(strlen(s) == 0);
	assert(strcmp(s, "") == 0);
	printf(" - OK\n");
	printf("ft_split()");
	char **srr = ft_split("Hello World", ' ');
	assert(strlen(srr[0]) == 5);
	assert(strlen(srr[1]) == 5);
	assert(srr[2] == 0);
	assert(strcmp(srr[0], "Hello") == 0);
	assert(strcmp(srr[1], "World") == 0);
	srr = ft_split("Hello World", 0);
	assert(strlen(srr[0]) == strlen("Hello World"));
	assert(srr[1] == 0);
	assert(strcmp(srr[0], "Hello World") == 0);
	srr = ft_split("Hello        World", ' ');
	assert(strlen(srr[0]) == 5);
	assert(strlen(srr[1]) == 5);
	assert(srr[2] == 0);
	assert(strcmp(srr[0], "Hello") == 0);
	assert(strcmp(srr[1], "World") == 0);
	srr = ft_split("        ", ' ');
	assert(srr[0] == 0);
	srr = ft_split("", ' ');
	assert(srr[0] == 0);
	printf(" - OK\n");
	printf("ft_itoa()");
	free(s);
	s = malloc(64);
	assert(strcmp(ft_itoa(0), "0") == 0);
	bzero(s, 64);
	assert(strcmp(ft_itoa(-56), "-56") == 0);
	bzero(s, 64);
	assert(strcmp(ft_itoa(2147483647), "2147483647") == 0);
	bzero(s, 64);
	assert(strcmp(ft_itoa(-2147483648), "-2147483648") == 0);
	bzero(s, 64);
	assert(strcmp(ft_itoa(420), "420") == 0);
	printf(" - OK\n");
	printf("ft_strmapi()");
	bzero(s, 64);
	strcpy(s, "hello world");
	s = ft_strmapi(s, &toupper_wrapper);
	assert(strcmp(s, "HELLO WORLD") == 0);
	s = ft_strmapi(s, &tolower_wrapper);
	assert(strcmp(s, "hello world") == 0);
	printf(" - OK\n");
	printf("ft_striteri()");
	bzero(s, 64);
	strcpy(s, "hello world");
	ft_striteri(s, &void_toupper_wrapper);
	assert(strcmp(s, "HELLO WORLD") == 0);
	ft_striteri(s, &void_tolower_wrapper);
	assert(strcmp(s, "hello world") == 0);
	printf(" - OK\n"); */
	printf("ft_putchar_fd()");
	char *s = malloc(64);
	char *path = malloc(22);
	strcpy(path, "/tmp/");
	char *tmp_filename = random_string(16);
	strcat(path, tmp_filename);
	printf("%s\n", path);
	bzero(s, 64);
	int fd = open(path, O_RDWR | O_CREAT, 0666);
	assert(fd > 0);
	ft_putchar_fd('c', fd);
	printf("%zd\n",read(fd, s, 1));
	printf("%c\n", s[0]);
	assert(s[0] == 'c');
}
