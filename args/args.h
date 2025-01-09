/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   args.h                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/09 05:53:29 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:57:48 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H
# include "../gc/gc.h"
# include "../str/str.h"

typedef struct s_args	t_args;
typedef					void(t_handler_fn)(void);

struct					s_args
{
	int					count;
	int					error;
	void				**clean;
	int					must_clean_args;
	char				**args;
	t_handler_fn		**validators;
};

t_args					*args_instance(void);
int						args_prepare(char const *arg);
int						args_register_handler(t_handler_fn *fn);
int						args_validate(void);
void					args_use_argv(char const **argv);
void					args_destroy(void);

#endif
