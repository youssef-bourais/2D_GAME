/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:44:43 by ybourais          #+#    #+#             */
/*   Updated: 2024/09/12 07:34:55 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

char	**read_map(int fd, int *p)
{
	char	*line;
	char	**tab;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		free(line);
		if (line == NULL)
			break ;
		i++;
	}
	close(fd);
	tab = (char **)malloc(sizeof(char *) * (i));
	if (!tab)
		return (NULL);
	fd = open("maps/map.ber", O_RDONLY);
	*p = i;
	i = 0;
	while (i < *p)
		tab[i++] = get_next_line(fd);
	close(fd);
	return (tab);
}

void	ft_image_condition(t_vars *start, int i, int j)
{
	if (start->map[i][j] == '1')
		mlx_put_image_to_window(start->mlx, start->win, start->img_w, j
			* start->size, i * start->size);
	else if (start->map[i][j] == '0')
		mlx_put_image_to_window(start->mlx, start->win, start->img_g, j
			* start->size, i * start->size);
	else if (start->map[i][j] == 'C')
		mlx_put_image_to_window(start->mlx, start->win, start->img_c, j
			* start->size, i * start->size);
	else if (start->map[i][j] == 'E')
		mlx_put_image_to_window(start->mlx, start->win, start->img_e, j
			* start->size, i * start->size);
	else if (start->map[i][j] == 'P')
		mlx_put_image_to_window(start->mlx, start->win, start->img_p, j
			* start->size, i * start->size);
	else if (start->map[i][j] == 'X')
		mlx_put_image_to_window(start->mlx, start->win, start->img_d, j
			* start->size, i * start->size);
}

void	ft_put_image(t_vars *start)
{
	int	i;
	int	j;

	i = 0;
	while (i < start->p)
	{
		j = 0;
		while (j < ft_len(start->map[0]) - 1)
		{
			ft_image_condition(start, i, j);
			j++;
		}
		i++;
	}
}

void	implement_map(t_vars *start)
{
	static int	b;

	ft_image(start);
	if ((ft_len(start->map[0]) - 1) * (start->size) > SIZEX || ((start->p)
			* (start->size) > SIZEY))
		ft_error(start);
	if (b == 0)
	{
		start->win = mlx_new_window(start->mlx, (ft_len(start->map[0]) - 1)
				* (start->size), (start->p) * (start->size), "HUNTER_X_HUNTER");
		b++;
	}
	ft_put_image(start);
	}

int	main(void)
{
	t_vars	start;
	char	**visited;

	start.mlx = mlx_init();
	start.fd = open("maps/map.ber", O_RDONLY);
	start.map = read_map(start.fd, &start.p);
	visited = (char **)malloc(sizeof(char *) * start.p);
	if (!visited)
		return (0);
	if (start.fd < 0)
		ft_error(&start);
	ft_copie_table(visited, start.map, start.p);
	if (check_valid_map(start.map, start.p, &(start.p1), &(start.p2)) == 1
		&& cheak_other_1(start.map, start.p, &(start.e1), &(start.e2)) == 1
		&& valid_path(visited, start.p, start.p1, start.p2) == 1)
	{
		implement_map(&start);
        mlx_key_hook(start->win, &key_hook, start);
	    mlx_hook(start->win, 17, 0, &ft_close, start);
		write(1, "valid map\n", 9);
		ft_free_table(visited, start.p);
	}
	else
		ft_error(&start);
	mlx_loop(start.mlx);
	return (0);
}
