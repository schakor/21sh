#include "twenty_one_sh.h"

static char	**file_to_buffer(int fd, char **buffer)
{
	int	ret;
	char	buff[2];
	char	*str;

	ret = 0;
	buff[0] = 0;
	buff[1] = 0;
	str = NULL;
	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strfreejoin(&str, buff);
	}
	close(fd);
	if (str)
		buffer = ft_strsplit(str, '\n');
	ft_strdel(&str);
	return (buffer);
}

void	history_from_file(t_shell *sh, char *path)
{
	char		**buffer;
	int		i;
	int		fd;
	t_history	*new_ele;

	path = ft_strfreejoin(&path, "/.21sh_hist");
	buffer = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	buffer = file_to_buffer(fd, buffer);
	close(fd);
	while (buffer && buffer[i])
	{
		new_ele = new_hist(buffer[i], ft_strlen(buffer[i]), ft_strlen(buffer[i]));
		sh->history = add_hist(sh->history, new_ele);
		i++;
	}
	//fct free char **;
	i = 0;
	while (buffer[i])
		ft_strdel(&buffer[i++]);
	free(buffer);
	ft_strdel(&path);
}

void	file_from_history(t_shell *sh, char *path)
{
	int	fd;
	char	*str;

	path = ft_strfreejoin(&path, "/.21sh_hist");
	str = NULL;
	fd = open(path, O_WRONLY);
	if (fd < 0)
		fd = open(path, O_CREAT | O_WRONLY);
	if (fd > 0)
	{
		while (sh->history && sh->history->bfr)
			sh->history = sh->history->bfr;
		while (sh->history && sh->history->next)
		{
			str = ft_strfreejoin(&str, sh->history->buffer);
			str = ft_strfreejoin(&str, "\n");
			sh->history = sh->history->next;
		}
		write(fd, str, ft_strlen(str));
		ft_strdel(&str);
		ft_strdel(&path);
		close (fd);
	}
}
