/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:04:59 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/06 16:34:19 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_index(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == n)
			return (i);
		i++;
	}
	return (-42);
}

char	*ft_read(int fd, char *temp)
{
	char	buff[BUFFER_SIZE + 1];
	int		res;
	int		k;
	int		n;

	res = 0;
	k = 0;
	n = 0;
	while (1)
	{
		res = read(fd, buff, BUFFER_SIZE);
		if (res == -1)
		{
			free(temp);
			temp = NULL;
			return (NULL);
		}
		buff[res] = '\0';
		temp = ft_str_join(temp, buff);
		if (ft_chrch(temp + n, '\n') == 1 || res < BUFFER_SIZE)
			break ;
		n = k * BUFFER_SIZE;
		k++;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*str;
	char		*tofree;
	int			j;

	if (fd < 0)
		return (NULL);
	j = 0;
	temp = ft_read(fd, temp);
	if (temp == NULL)
		return (NULL);
	j = ft_index(temp, '\n');
	if (j == -42)
		j = ft_len(temp) - 1;
	if (temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	str = ft_sub_str(temp, 0, j + 1);
	tofree = temp;
	temp = ft_sub_str(temp, j + 1, ft_len(temp) - j);
	free(tofree);
	return (str);
}
