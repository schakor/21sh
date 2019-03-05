/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_envl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <schakor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:27:07 by schakor           #+#    #+#             */
/*   Updated: 2019/03/05 16:36:48 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static uint8_t	search_env_var(t_envl *envl, const char *search)
{
	t_envl		*tmp;

	tmp = envl;
	while (tmp)
	{
		if (ft_strequ(tmp->name, search))
			return (FOUND);
		tmp = tmp->next;
	}
	return (NOTFOUND);
}

static void		set_env_var(t_envl **envl, const char *name, char *value)
{
	t_envl		*new;

	if (search_env_var(*envl, name) == NOTFOUND)
	{
		if (!(new = (t_envl *)malloc(sizeof(*new))))
			fatal_exit(SH_ENOMEM);
		new->name = ft_strdup(name);
		new->value = value;
		new->next = NULL;
		*envl = addlast_envl(*envl, new);
	}
}

static void		set_envl_default_value(t_envl **envl)
{
	t_passwd	*pwuid;
	char		*cwd;

	if ((pwuid = getpwuid(getuid())) == NULL)
		fatal_exit(SH_ENOMEM);
	if ((cwd = getcwd(NULL, 0)) == NULL)
		fatal_exit(SH_ENOMEM);
	set_env_var(envl, "HOME", ft_strjoin("/Users/", pwuid->pw_name));
	set_env_var(envl, "LOGNAME", ft_strdup(pwuid->pw_name));
	set_env_var(envl, "SHLVL", ft_strdup("1"));
	set_env_var(envl, "PWD", ft_strdup(cwd));
	set_env_var(envl, "OLDPWD", ft_strdup(cwd));
}

static t_envl	*envarr_to_envl(char **env)
{
	t_envl		*ret;
	t_envl		*new;
	char		*ptr;

	ret = NULL;
	if (!env)
		return (ret);
	while (*env != NULL)
	{
		if (!(new = (t_envl *)malloc(sizeof(*new))))
			return (NULL);
		ptr = ft_strchr(*env, '=');
		new->name = ft_strsub(*env, 0, ptr - *env);
		new->value = ft_strsub(*env, ptr - *env + 1, ft_strlen(ptr));
		new->exp = 1;
		new->next = NULL;
		if (ft_strequ(new->name, "SHLVL"))
		{
			ptr = ft_itoa(ft_atoi(new->value) + 1);
			ft_strdel(&new->value);
			new->value = ptr;
		}
		ret = addlast_envl(ret, new);
		env++;
	}
	return (ret);
}

t_envl			*init_shell_envl(char **env)
{
	t_envl		*ret;

	ret = envarr_to_envl(env);
	set_envl_default_value(&ret);
	return (ret);
}
