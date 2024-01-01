/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:12:26 by tabadawi          #+#    #+#             */
/*   Updated: 2024/01/01 18:18:25 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *save, int c)
{
	int		i;

	i = 0;
	if (!save)
		return (0);
	if ((char)c == '\0')
		return (&save[ft_strlen(save)]);
	while (save[i] != '\0')
	{
		if (save[i] == (char)c)
			return (&save[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *sv, char *buff)
{
	char	*newsave;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!sv && !buff)
		return (NULL);
	newsave = malloc(sizeof(char) * ((ft_strlen(sv) + ft_strlen(buff)) + 1));
	if (!newsave)
		return (NULL);
	while (sv && sv[i] != '\0')
	{
		newsave[i] = sv[i];
		i++;
	}
	while (buff[j] != '\0')
		newsave[i++] = buff[j++];
	newsave[i++] = '\0';
	if (sv)
		free(sv);
	return (newsave);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*print;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	print = malloc((sizeof(char)) * (i + 1 + (save[i] == '\n')));
	if (!print)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
	{
		print[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		print[i] = '\n';
		i++;
	}
	print[i] = '\0';
	return (print);
}

char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	buff = malloc ((sizeof(char)) * ft_strlen(save) - i + 1);
	if (!buff)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		buff[j++] = save[i++];
	buff[j] = '\0';
	free(save);
	return (buff);
}
