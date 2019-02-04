/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:55:00 by schakor           #+#    #+#             */
/*   Updated: 2018/12/17 18:20:26 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

struct						s_input
{
	char					*buffer;
	size_t					buf_i;
	size_t					bufsize;
	size_t					buftmp;
	t_uint8					bufkey[8];
};

void						read_raw_mode(t_shell *sh);
void						insert_buffer(t_shell *sh, char c);
void						increase_buffer(t_shell *sh);
void						delete_buffer(t_shell *sh);
void						clean_input(t_input *list);
void						move_start(t_shell *sh);
void						move_left_cursor(t_shell *sh, size_t *index);
void						move_right_cursor(t_shell *sh, size_t *index);
void						delete_until_cursor(t_shell *sh, size_t index);
void						move_end(t_shell *sh);
void						display_prompt(t_shell *sh);

#endif
