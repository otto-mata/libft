/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:19:27 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 20:23:06 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLIST_H
# define LLIST_H
# include "../stdlib/ft_stdlib.h"

typedef struct s_list	t_list;

struct					s_list
{
	void				*content;
	t_list				*next;
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
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));

/**
 * @brief Computes the number of elements in a linked list lst.
 * @param lst Linked list
 * @return Number of elements in the linked list.
 */
int						ft_lstsize(t_list *lst);

/**
 * @brief Creates a new free-able node with content as value.
 * @param content Content for the node.
 * @return Newly allocated free-able node.
 */
t_list					*ft_lstnew(void *content);

/**
 * @brief Returns a pointer to the last element of a linked list lst
 * @param lst Linked list
 * @return A pointer to the last element of a linked list lst
 */
t_list					*ft_lstlast(t_list *lst);

/**
 * @brief Iterates over a linked list lst, applying f() in place to each
 * node's content.
 * @param lst Linked list to iterate over.
 * @param f Function to apply.
 */
void					ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Deletes and frees a node lst using the given del() function.
 * @param lst Node to delete.
 * @param del Delete function to apply on the content of the node.
 */
void					ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees lst and every subsequent node using del().
 * @param lst Node on which to start the clearing.
 * @param del Delete function to apply on the content of a node.
 */
void					ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Prepends a node new to a node lst.
 * @param lst Target node.
 * @param new Node to prepend.
 */
void					ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Appends a node new to a node lst.
 * @param lst Target node.
 * @param new Node to append.
 */
void					ft_lstadd_back(t_list **lst, t_list *new);

#endif