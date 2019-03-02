/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:30:03 by khsadira          #+#    #+#             */
/*   Updated: 2019/03/02 20:16:47 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static t_envl	*setenv_nullarg(uint8_t *arg, int size, t_envl *head)
{
	t_envl	*tmp;

	tmp = head;
	while (tmp)
	{
		if (!ft_memcmp(tmp->name, arg, size))
		{
			//free(tmp->value);
			//tmp->value = "" malloc;
			return (head);
		}
		tmp = tmp->next;
	}
	//tmp = newenv(arg, "");
	//head = add_env(head, tmp);
	return (head);

}

static int ft_dstrlen(uint8_t **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

t_envl	*built_sentenv(uint8_t **arg, int *arg_size, t_envl *head)
{
	t_envl	*tmp;
	int		len;

	tmp = head;
	if ((len = ft_dstrlen(arg)) == 1)
	{
		//printenv
		return (head);
	}
	else if (built_env_check_error(arg, arg_size))
		return (head);
	else if (len == 2)
		return (setenv_nullarg(arg[1], arg_size[1], tmp));
	while (tmp)
	{
		if (!ft_memcmp(tmp->name, arg[1], arg_size[1]))
		{
			//free(tmp->value);
			tmp->value = (char *)arg[2];
			return (head);
		}
		tmp = tmp->next;
	}
	//tmp = new_env(arg[1], arg[2]);
	//head = add_env(head, tmp);
	return (head);
}
