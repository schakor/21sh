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

void	history_from_file(t_shell *sh)
{
	char		**buffer;
	int		i;
	int		fd;
	t_history	*new_ele;

	buffer = NULL;
	fd = open("/Users/khansadirac/.21sh_hist", O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	buffer = file_to_buffer(fd, buffer);
	while (buffer && buffer[i])
		i++;
	i--;
	while (buffer && i >= 0)
	{
		new_ele = new_hist(buffer[i], ft_strlen(buffer[i]), 32);
		sh->history = add_hist(sh->history, new_ele);
		i--;
	}
	//fct free char **;
	i = 0;
	while (buffer[i])
		ft_strdel(&buffer[i++]);
	free(buffer);
}

void	file_from_history(t_shell *sh)
{
	int	fd;
	char	*str;

	str = NULL;
	fd = open("/Users/khansadirac/.21sh_hist", O_WRONLY);
	if (fd < 0)
		fd = open("/Users/khansadirac/.21sh_hist", O_CREAT | O_WRONLY);
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
}
