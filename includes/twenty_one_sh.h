/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twenty_one_sh.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:06:41 by schakor           #+#    #+#             */
/*   Updated: 2019/03/04 12:20:29 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWENTY_ONE_SH_H
# define TWENTY_ONE_SH_H


# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/includes/libft.h"
# include <signal.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <stdint.h>
# include <pwd.h>

# include "sh_typedefs.h"
# include "sh_defines.h"
# include "shell.h"
# include "env.h"
# include "readline.h"
# include "history.h"
# include "lexer.h"
# include "builtin.h"
# include "builtin_defines.h"

void						ft_sig_handler(int signo);
void						ft_signal(int signo);

#endif
