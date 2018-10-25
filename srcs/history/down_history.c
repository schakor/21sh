#include "twenty_one_sh.h"

void	down_history_here(t_shell *sh)
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

void	down_history(t_shell *sh)
{
	if (!sh->history)
		return ;
	move_end(sh);
	if (sh->history_save == -1)
		return ;
	else
	{
		sh->history_save--;
		down_history_here(sh);
	}
}
