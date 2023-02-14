/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:49:15 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/11 17:51:38 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_copy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

char	*ft_str_join(char *s1, char *s2)
{
	char	*str;
	int		a;
	int		b;

	a = ft_len(s1);
	b = ft_len(s2);
	str = (char *)malloc((a + b) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_copy(str, s1, a);
	ft_copy(str + a, s2, b);
	str[a + b] = '\0';
	free(s1);
	return (str);
}

int	ft_chrch(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == n)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_sub_str(char *str, int start, int len)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	ft_copy(s, str + start, len);
	s[len] = '\0';
	return (s);
}
