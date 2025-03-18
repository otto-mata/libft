/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   osgc.h                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/18 15:01:07 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/14 03:38:35 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSGC_H
# define OSGC_H
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_gcblock	t_block;
typedef struct s_otto_gc	t_gc;

struct						s_gcblock
{
	void					*mem;
	t_block					*next;
};

struct						s_otto_gc
{
	t_block					*blocks;
};

t_gc						*osgc_instance(void);
t_block						*osgc_addblock_back(t_block *new);
t_block						*osgc_addblock_front(t_block *new);
t_block						*osgc_newblock(void *mem);
t_block						*osgc_lastblock(void);
t_block						*osgc_find_by_address(void *addr);
t_block						*osgc_find_prev_by_address(void *addr);
void						*osgc_delblock(t_block *block);
void						osgc_free(void *mem);
int							osgc_blocksz(void);
void						*osgc_clear(void);
void						*osgc_malloc(size_t sz);
void						*osgc_calloc(size_t nmemb, size_t sz);
void						*osgc_realloc(void *mem, size_t old_sz,
								size_t new_sz);
void						otto_bzero(void *mem, size_t sz);
void						*otto_memcpy(void *d, void const *s, size_t sz);
size_t						otto_min(size_t a, size_t b);
#endif
