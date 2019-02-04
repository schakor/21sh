/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:08:38 by khsadira          #+#    #+#             */
/*   Updated: 2019/02/04 14:19:00 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

typedef struct				s_history
{
	char					*buffer;
	size_t					bufsize;
	size_t					buftmp;
	struct s_history		*next;
	struct s_history		*bfr;
}							t_history;


int			listlen(t_history *list);
void		add_history(t_shell *sh);
void		print_history(t_shell *sh);
void		switch_history(t_shell *sh);
void		down_history_here(t_shell *sh);
void		down_history(t_shell *sh);
void		history_from_file(t_shell *sh, char *path);
void		file_from_history(t_shell *sh, char *path);
void		history_cmd(t_shell *sh);
void		up_history_here(t_shell *sh);
void		up_history(t_shell *sh);
t_history	*new_hist(char *buffer, size_t bufsize, size_t buftmp);
t_history	*add_hist(t_history *list, t_history *new_hist);
#endif
