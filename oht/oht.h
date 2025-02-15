/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   oht.h                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/29 06:26:58 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/02/15 14:15:09 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef OHT_H
# define OHT_H
# define OHT_CAPACITY 256
# define OHT_KEY_LENGTH 97
# define FNV_OFFSET 14695981039346656037UL
# define FNV_PRIME 1099511628211UL
# include "../stdlib/ft_stdlib.h"
# include "../string/ft_string.h"
# include <stdint.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_oht_entry	t_oht_entry;
typedef struct s_oht		t_oht;

struct						s_oht_entry
{
	char					key[OHT_KEY_LENGTH];
	void					*value;
	t_oht_entry				*next;
};

struct						s_oht
{
	t_oht_entry				**entries;
	uint32_t				size;
	uint32_t				capacity;
};

void						oht_free(t_oht *table, void (*fn_free)(void *));
int							oht_delete(t_oht *table, char const *key,
								void (*fn_free)(void *));
void						*oht_lookup(t_oht *table, char const *key);
void						*oht_insert(t_oht *table, char const *key,
								void *value);
t_oht						*oht_create(__attribute__((unused)) int capacity);
uint32_t					hash_key(char const *key, int capacity);

#endif
