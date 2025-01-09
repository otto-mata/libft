/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc.h                                                 ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/18 15:01:07 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 06:01:19 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_block	t_block;
typedef struct s_gc		t_gc;

struct					s_block
{
	void				*mem;
	t_block				*next;
};

struct					s_gc
{
	t_block				*blocks;
};

t_gc					*gc_instance(void);
t_block					*gc_addback(t_block *new);
t_block					*gc_addfront(t_block *new);
t_block					*gc_newblock(void *mem);
t_block					*gc_last(void);
t_block					*gc_addr_find(void *addr);
t_block					*gc_addr_find_prev(void *addr);
void					*gc_delblock(t_block *block);
void					gc_free(void *mem);
int						gc_nblocks(void);
void					*gc_clear(void);
void					*gc_malloc(size_t sz);
void					*gc_calloc(size_t nmemb, size_t sz);
void					*gc_realloc(void *mem, size_t old_sz, size_t new_sz);
void					otto_bzero(void *mem, size_t sz);
void					*otto_memcpy(void *d, void const *s, size_t sz);
size_t					otto_min(size_t a, size_t b);
#endif
