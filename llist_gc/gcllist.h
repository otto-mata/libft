/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gcllist.h                                            ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/01 20:19:27 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/03 08:25:07 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCLLIST_H
# define GCLLIST_H
# include "../gc/gc.h"
# include "../stdlib/ft_stdlib.h"

typedef struct s_gclist	t_gclist;

struct					s_gclist
{
	void				*content;
	t_gclist			*next;
};

/**
 * @brief Creates a new list from lst by applying f() to each element.
 * del() is used to delete the newly created list in case of allocation error
 * dureing the process.
 * @param lst Linked list to map.
 * @param f Mapping function to apply.
 * @param del Node deletion function.
 * @return Mapped list as a newly allocated free-able list.
 */
t_gclist				*ftgc_lstmap(t_gclist *lst, void *(*f)(void *),
							void (*del)(void *));

/**
 * @brief Computes the number of elements in a linked list lst.
 * @param lst Linked list
 * @return Number of elements in the linked list.
 */
int						ftgc_lstsize(t_gclist *lst);

/**
 * @brief Creates a new free-able node with content as value.
 * @param content Content for the node.
 * @return Newly allocated free-able node.
 */
t_gclist				*ftgc_lstnew(void *content);

/**
 * @brief Returns a pointer to the last element of a linked list lst
 * @param lst Linked list
 * @return A pointer to the last element of a linked list lst
 */
t_gclist				*ftgc_lstlast(t_gclist *lst);

/**
 * @brief Iterates over a linked list lst, applying f() in place to each
 * node's content.
 * @param lst Linked list to iterate over.
 * @param f Function to apply.
 */
void					ftgc_lstiter(t_gclist *lst, void (*f)(void *));

/**
 * @brief Deletes and frees a node lst using the given del() function.
 * @param lst Node to delete.
 * @param del Delete function to apply on the content of the node.
 */
void					ftgc_lstdelone(t_gclist *lst, void (*del)(void *));

/**
 * @brief Deletes and frees lst and every subsequent node using del().
 * @param lst Node on which to start the clearing.
 * @param del Delete function to apply on the content of a node.
 */
void					ftgc_lstclear(t_gclist **lst, void (*del)(void *));

/**
 * @brief Prepends a node new to a node lst.
 * @param lst Target node.
 * @param new Node to prepend.
 */
void					ftgc_lstadd_front(t_gclist **lst, t_gclist *new);

/**
 * @brief Appends a node new to a node lst.
 * @param lst Target node.
 * @param new Node to append.
 */
void					ftgc_lstadd_back(t_gclist **lst, t_gclist *new);

#endif
