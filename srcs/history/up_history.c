#include "twenty_one_sh.h"

void	up_history_here(t_shell *sh)
{
	int		i;
	t_history	*head;

	head = sh->history;
	i = 0;
	while (i < sh->history_save && sh->history->bfr)
	{
		sh->history = sh->history->bfr;
		i++;
	}
	print_history(sh);
	sh->history = head;
}

void	up_history(t_shell *sh)
{
	if (!sh->history)
		return ;
	move_end(sh);
	if (sh->history_save == -1)
	{
		print_history(sh);
		sh->history_save = 0;
	}
	else
	{
		sh->history_save++;
		up_history_here(sh);
	}
}