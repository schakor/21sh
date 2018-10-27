#include "twenty_one_sh.h"

static void	ft_strddel(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&(str[i]));
		i++;
	}
}

static void	free_envlst(t_env_lst *list)
{
	t_env_lst	*tmp;

	while (list)
	{
		ft_strdel(&(list->name));
		ft_strdel(&(list->value));
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

static void	free_input(t_input *list)
{
	ft_strdel(&(list->buffer));
	free(list);
}

static void	free_history(t_history *list)
{
	t_history	*tmp;

	while (list)
	{
		ft_strdel(&(list->buffer));
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	free_term(t_shell *sh)
{
	ft_strddel(sh->env);
	ft_strddel(sh->paths);
	free_envlst(sh->env_lst);
	free_input(sh->in);
	//		free_termios(sh->cooked_tio);
	//		free_termios(sh->raw_tio);
	free_history(sh->history);
	free(sh);
}
