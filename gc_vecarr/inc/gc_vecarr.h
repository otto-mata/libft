/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_vecarr.h                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 15:23:05 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 10:53:32 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_VECARR_H
# define GC_VECARR_H
# define GC_VECARR_INIT 1
# include <stdlib.h>
#include "../../gc/gc.h"

typedef struct s_vecarr	t_vecarr;

struct					s_vecarr
{
	long				len;
	long				allocd;
	size_t				step;
	void				**data;
	char				*(*join)(t_vecarr *, const char *);
	int					(*all)(t_vecarr *, int (*)(void *));
	int					(*delete)(t_vecarr *, long);
	void				(*pop)(t_vecarr *);
	int					(*push)(t_vecarr *, void *);
	int					(*some)(t_vecarr *, int (*)(void *));
	long				(*find_index)(t_vecarr *, int (*)(void *));
	long				(*find_last_index)(t_vecarr *, int (*)(void *));
	long				(*sum)(t_vecarr *);
	t_vecarr			*(*filter)(t_vecarr *, int (*)(void *));
	t_vecarr			*(*map)(t_vecarr *, void *(*)(void *));
	t_vecarr			*(*new)(void);
	t_vecarr			*(*reverse)(t_vecarr *);
	t_vecarr			*(*slice)(t_vecarr *, long, long);
	void				*(*find_last)(t_vecarr *, int (*)(void *));
	void				*(*find)(t_vecarr *, int (*)(void *));
	void				(*clear)(t_vecarr **);
	void				(*destroy)(t_vecarr **);
};

/**
 * @brief Treats the items of V as null-terminated strings.
 * Joins the items into one null terminated string separated by SEP.
 * @param v Target vecarr
 * @param sep Separator to use
 * @return Malloc's null-terminated string of the joint items of V
 */
char					*va_join(t_vecarr *v, const char *sep);

/**
 * @brief Tests all items of V with the TEST function
 * @param v Target vecarr
 * @param test Function to apply on each item
 * @return 1 if all items TEST's calls are true, 0 otherwise
 */
int						va_all(t_vecarr *v, int (*test)(void *));
/**
 * @brief Deletes a specific item of INDEX index from V 
 * @param v Target vecarr
 * @param index Item's index in V
 * @return A negative number if INDEX is larger than the length of V,
 * 0 otherwise
 */
int						va_delete(t_vecarr *v, long index);
/**
 * @brief Deletes the last item of V
 * @param v Target vecarr
 * @return
 */
void					va_pop(t_vecarr *v);
/**
 * @brief Appends ITEM to V
 * @param v Target vecarr
 * @param item Item to append to V
 * @return 
 */
int						va_push(t_vecarr *v, void *item);
/**
 * @brief Tests all items of V with the TEST function
 * @param v Target vecarr
 * @param test Function to test each item with
 * @return 1 if at least one item is true with TEST, 0 otherwise
 */
int						va_some(t_vecarr *v, int (*test)(void *));

long					va_find_index(t_vecarr *v, int (*test)(void *));
long					va_find_last_index(t_vecarr *v, int (*test)(void *));
long					va_sum(t_vecarr *v);

t_vecarr				*va_filter(t_vecarr *v, int (*test)(void *));
t_vecarr				*va_map(t_vecarr *orig, void *(*map_fn)(void *));
t_vecarr				*va_new(void);
t_vecarr				*va_reverse(t_vecarr *v);
t_vecarr				*va_slice(t_vecarr *v, long begin, long end);

void					*va_find_last(t_vecarr *v, int (*test)(void *));
void					*va_find(t_vecarr *v, int (*test)(void *));
void					va_destroy(t_vecarr **v);
void					va_clear(t_vecarr **v);
#endif
