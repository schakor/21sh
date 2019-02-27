/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:05:15 by khsadira          #+#    #+#             */
/*   Updated: 2019/02/27 16:02:11 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/*
**	builtin functions header
*/

void	built_history(t_rl *rl);
void	built_exclaim();
void	built_cd();
void	built_echo();
void	built_env();
void	built_setenv();
void	built_unsetenv();

#endif
