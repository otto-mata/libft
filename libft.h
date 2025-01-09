/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libft.h                                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 06:04:31 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_list	t_list;
typedef struct s_string	t_string;
typedef struct s_args	t_args;
typedef					void(t_handler_fn)(void);
typedef struct s_block	t_block;
typedef struct s_gc		t_gc;
typedef struct s_btree	t_btree;
typedef struct s_vec3	t_vec3;
typedef t_vec3			t_point3;

struct					s_vec3
{
	double				x;
	double				y;
	double				z;
};
struct					s_btree
{
	t_btree				*left;
	t_btree				*right;
	void				*item;
};
struct					s_block
{
	void				*mem;
	t_block				*next;
};

struct					s_gc
{
	t_block				*blocks;
};
struct					s_args
{
	int					count;
	int					error;
	void				**clean;
	int					must_clean_args;
	char				**args;
	t_handler_fn		**validators;
};
struct					s_list
{
	void				*content;
	t_list				*next;
};

struct					s_string
{
	unsigned long		len;
	unsigned long		sz;
	char				*content;
};

int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_iscntrl(int c);
int						ft_isdigit(int c);
int						ft_isgraph(int c);
int						ft_islower(int c);
int						ft_isprint(int c);
int						ft_ispunct(int c);
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_isxdigit(int c);
int						ft_isascii(int c);
int						ft_isblank(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);

ssize_t					ft_putchar_fd(char c, int fd);
ssize_t					ft_putstr_fd(char const *s, int fd);
ssize_t					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*get_next_line(int fd);
char					*ft_ltoh(unsigned long n, int upper);
char					*ft_itoa_unsigned(uint32_t n);
int						ft_printf(char const *fmt, ...);
int						ft_dprintf(int fd, char const *fmt, ...);
int						ft_sprintf(char *s, char const *fmt, ...);

void					free2d(void **ptr, int n);
int						ft_abs(int n);
int						ft_atoi(const char *s);
void					*ft_calloc(size_t nmemb, size_t sz);
div_t					ft_div(int a, int b);
void					*ft_realloc(void *mem, size_t old_sz, size_t new_sz);
char					*ft_itoa(int n);

char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
uint64_t				ft_hashstr(void *area, size_t n);
t_string				*expstr_new(unsigned long start_sz);
int						expstr_append(t_string *str, char val);
void					expstr_destroy(t_string **str);
char					*replace(char *in, char *sub, char *by);

void					*ft_memccpy(void *dest, const void *src, int c,
							size_t sz);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_stpcpy(char *dest, const char *s);
char					*ft_stpncpy(char *dest, const char *src, size_t n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strcoll(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
size_t					ft_strcspn(const char *str, const char *reject);
char					*ft_strdup(const char *str);
size_t					ft_strlen(const char *str);
char					*ft_strncat(char *dest, const char *src, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strndup(const char *str, size_t n);
size_t					ft_strnlen(const char *str, size_t maxlen);
char					*ft_strpbrk(const char *str, const char *accept);
char					*ft_strrchr(const char *str, int c);
size_t					ft_strspn(const char *str, const char *spn);
char					*ft_strstr(const char *str, const char *substr);
char					*ft_strtok(char *str, const char *delim);
char					*ft_strtok_r(char *str, const char *delim,
							char **saveptr);
void					ft_strrev(char *str);
void					ft_bzero(void *mem, size_t sz);

t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
int						ft_lstsize(t_list *lst);
t_list					*ft_lstnew(void *content);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstiter(t_list *lst, void (*f)(void *));
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstadd_front(t_list **lst, t_list *new);
void					ft_lstadd_back(t_list **lst, t_list *new);

t_block					*gc_addback(t_block *new);
t_block					*gc_addfront(t_block *new);
int						gc_nblocks(void);
void					*gc_calloc(size_t nmemb, size_t sz);
void					*gc_clear(void);
void					*gc_delblock(t_block *block);
t_block					*gc_addr_find(void *addr);
t_block					*gc_addr_find_prev(void *addr);
void					gc_free(void *mem);
t_gc					*gc_instance(void);
t_block					*gc_last(void);
void					*gc_malloc(size_t sz);
t_block					*gc_newblock(void *mem);
void					*gc_realloc(void *mem, size_t old_sz, size_t new_sz);

void					args_use_argv(char const **argv);
int						args_validate(void);
void					args_destroy(void);
t_args					*args_instance(void);
int						args_prepare(char const *arg);
int						args_register_handler(t_handler_fn *fn);

void					btree_apply_prefix(t_btree *root,
							void (*apply)(void *));
void					btree_apply_infix(t_btree *root, void (*apply)(void *));
void					btree_apply_suffix(t_btree *root,
							void (*apply)(void *));
t_btree					*btree_create_node(void *item);
int						btree_level_count(t_btree *root);
t_btree					*btree_search_node(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *));
void					btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *));
void					btree_apply_by_level(t_btree *root,
							void (*applyf)(void *item, int current_level,
								int is_first_elem));

t_vec3					*vec3_add(t_vec3 *u, t_vec3 *v);
t_vec3					*vec3_copy(t_vec3 *v);
t_vec3					*vec3_cross(t_vec3 *u, t_vec3 *v);
t_vec3					*vec3_div_scalar(t_vec3 *u, double t);
double					vec3_dot(t_vec3 *u, t_vec3 *v);
void					vec3_ip_add(t_vec3 *to, t_vec3 *v);
void					vec3_ip_div(t_vec3 *v, double t);
void					vec3_ip_mult(t_vec3 *v, double t);
void					vec3_ip_sub(t_vec3 *to, t_vec3 *v);
double					vec3_len(t_vec3 *v);
t_vec3					*vec3_mult(t_vec3 *u, t_vec3 *v);
t_vec3					*vec3_mult_scalar(t_vec3 *u, double t);
t_vec3					*vec3_new(double x, double y, double z);
double					vec3_sqrd_len(t_vec3 *v);
t_vec3					*vec3_sub(t_vec3 *u, t_vec3 *v);
t_vec3					*vec3_unit(t_vec3 *v);
#endif
