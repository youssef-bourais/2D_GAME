/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:50:03 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/11 14:52:16 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# elif (BUFFER_SIZE < 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_len(char *str);
char	*ft_copy(char *s1, char *s2, int n);
char	*ft_str_join(char *s1, char *s2);
int		ft_chrch(char *str, int n);
char	*ft_sub_str(char *str, int start, int len);
char	*get_next_line(int fd);
int		ft_index(char *str, int n);
char	**ft_split(char *s, char c);

#endif
