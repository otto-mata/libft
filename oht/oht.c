/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   oht.c                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/29 06:43:05 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/02/15 12:59:44 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "oht.h"

t_oht	*oht_create(__attribute__((unused)) int capacity)
{
	t_oht	*table;

	table = malloc(sizeof(t_oht));
	if (!table)
		return (0);
	table->size = 0;
	table->capacity = OHT_CAPACITY;
	table->entries = ft_calloc(table->capacity, sizeof(t_oht_entry *));
	if (!table->entries)
	{
		free(table);
		return (0);
	}
	return (table);
}

void	*oht_insert(t_oht *table, char const *key, void *value)
{
	uint32_t	index;
	t_oht_entry	*entry;
	void		*past_value;

	index = hash_key(key, table->capacity);
	entry = table->entries[index];
	while (entry)
	{
		if (ft_strcmp(key, entry->key) == 0)
		{
			past_value = entry->value;
			entry->value = value;
			return (past_value);
		}
		entry = entry->next;
	}
	entry = ft_calloc(1, sizeof(t_oht_entry));
	if (!entry)
		return (0);
	ft_strcpy(entry->key, key);
	entry->value = value;
	entry->next = table->entries[index];
	table->entries[index] = entry;
	table->size++;
	return (0);
}

void	*oht_lookup(t_oht *table, char const *key)
{
	uint32_t	index;
	t_oht_entry	*entry;

	index = hash_key(key, table->capacity);
	entry = table->entries[index];
	while (entry)
	{
		if (ft_strcmp(key, entry->key) == 0)
			return (entry->value);
		entry = entry->next;
	}
	return (0);
}

int	oht_delete(t_oht *table, char const *key, void (*fn_free)(void *))
{
	uint32_t	index;
	t_oht_entry	*entry;
	t_oht_entry	*prev;

	index = hash_key(key, table->capacity);
	entry = table->entries[index];
	prev = 0;
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
		{
			if (prev)
				prev->next = entry->next;
			else
				table->entries[index] = entry->next;
			fn_free(entry->value);
			table->size--;
			return (1);
		}
		prev = entry;
		entry = entry->next;
	}
	return (0);
}

void	oht_free(t_oht *table, void (*fn_free)(void *))
{
	t_oht_entry	*entry;
	t_oht_entry	*temp;
	uint32_t	index;

	index = 0;
	while (index < table->capacity)
	{
		entry = table->entries[index];
		while (entry)
		{
			temp = entry;
			entry = entry->next;
			fn_free(temp->value);
			free(temp);
		}
		index++;
	}
	free(table->entries);
	free(table);
}
