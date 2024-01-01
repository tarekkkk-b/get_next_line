/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 19:31:28 by tabadawi          #+#    #+#             */
/*   Updated: 2024/01/01 19:38:09 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readfile(char *save, int fd)
{
	int		rd;
	char	*buffer;

	buffer = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd != 0 && ft_strchr(save, '\n') == 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(save);
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*print;
	static char	*save[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	save[fd] = ft_readfile(save[fd], fd);
	if (!save[fd])
		return (NULL);
	print = ft_get_line(save[fd]);
	save[fd] = ft_save(save[fd]);
	return (print);
}
