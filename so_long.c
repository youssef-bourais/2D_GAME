/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:44:43 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/17 17:48:34 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

char **read_map(int fd ,int *p)
{
	char *line;
	char **tab;
	int i = 0;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		i ++;
	}
	close(fd);
	tab = (char **)malloc(sizeof(char *)*(i));
	fd = open("maps/map.ber", O_RDONLY);
	*p = i;
	int j;
	j = i;
	i = 0;
	while (i < j)
	{
		tab[i] = get_next_line(fd);
		i ++;
	}
	close(fd);
	return tab;
}

void implement_map(t_vars *start)
{
	int i;
	int j;

	ft_image(start);
	static int b;
	if (b == 0)
	{
    	start->win = mlx_new_window(start->mlx, (ft_len(start->map[0]) - 1)*(start->size), (start->p)*(start->size), "HUNTER_X_HUNTER");
		b ++;
	}
	ft_put_image(start);
    mlx_key_hook(start->win, &key_hook, start);
	mlx_hook(start->win, 17, 0, &ft_close, 0);
}

int	main(void)
{
	t_vars start;
	start.mlx = mlx_init();
	start.fd = open("maps/map.ber", O_RDONLY);
	start.map = read_map(start.fd, &start.p);

	char **visited;
	visited = (char **)malloc(sizeof(char *)*start.p);
	ft_copie_table(visited, start.map, start.p);
	if (check_valid_map(start.map, visited, start.p, &(start.e1), &(start.e2), &(start.p1), &(start.p2)) == 1)
	{
		printf("valid map\n");
		implement_map(&start);
		ft_free_table(visited, start.p);
	}
	else
		ft_error();
	mlx_loop(start.mlx);
}
