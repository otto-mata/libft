/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mem_manager.h                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 23:57:40 by ottomata             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 11:40:34 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_MANAGER_H
# define MEM_MANAGER_H
# define PAGES_PER_NODE 64
# define PAGE_ALIGN 3
# define PAGE_POW_2 12
# include <errno.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_mem_manager	t_mem_manager;
typedef t_mem_manager			t_mm;

typedef struct s_mem_page		t_mem_page;
typedef t_mem_page				t_mp;

typedef struct s_mem_page_node	t_mem_page_node;
typedef t_mem_page_node			t_mpn;

typedef struct s_mem_page_chunk	t_mem_page_chunk;
typedef t_mem_page_chunk		t_mpc;

typedef void					*(*t_fn_malloc)(size_t sz);
typedef void					*(*t_fn_realloc)(void *p, size_t sz);
typedef void					(*t_fn_free)(void *p);

struct							s_mem_page_chunk
{
	char						x : 1;
	size_t						sz : 63;
};

struct							s_mem_page
{
	size_t						sz;
	void						*mem;
};

struct							s_mem_page_node
{
	size_t						len;
	t_mp						pages[PAGES_PER_NODE];
	t_mpn						*fwd;
};

struct							s_mem_manager
{
	t_fn_free					free;
	t_fn_malloc					malloc;
	t_fn_realloc				realloc;
	t_mpn						*pnodes;
};

t_mm							*memory_manager(void);
void							mm_destroy(void);
void							mm_free(void *p);
void							*mm_realloc(void *p, size_t sz);
void							*mm_malloc(size_t sz);
size_t							align_to_2exp(size_t n, size_t exponent);
void							ft_bzero(void *mem, size_t sz);
void							*ft_memcpy(void *d, void const *s, size_t sz);
void							*ft_memmove(void *d, void const *s, size_t sz);
t_mpc							*find_chunk_of_size(t_mm *mm, size_t sz);
t_mpc							*fragment_block(t_mpc *chunk, size_t sz);
t_mpc							*get_next_block_in_page(t_mpc *chunk,
									int find_zero);
t_mpc							*get_first_block_in_page(t_mp *mem_page);
int								new_memory_page(t_mm *alloc, size_t page_size);
#endif
