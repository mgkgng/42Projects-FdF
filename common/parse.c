/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:02:10 by min-kang          #+#    #+#             */
/*   Updated: 2022/05/22 13:49:28 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_size(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

t_3d	*get_3d(char ***col, int len_x, int len_y)
{
	t_3d	*res;
	int		i;
	int		j;
	int		x;

	res = ft_calloc(len_x * len_y, sizeof(t_3d));
	i = -1;
	a = 0;
	while (++i < len_y)
	{
		j = -1;
		while (++j < len_x)
		{
			res[x].x = (float) j;
			res[x].y = (float) i;
			res[x].z = (float) col[i][j];
			//res[x++].h = data.mat_2d[(int) i][(int) j];
		}
	}
	return (res);
}

char	*get_txt(int fd)
{
	char	*line;
	char	*res;

	res = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_strcat(res, line);
		free(line);
		line = get_next_line(fd);
	}
	return (res);
}

t_map	parse(int fd)
{
	char	*r;
	t_map	res;
	int		i;
	int		j;
	char	**line;
	char	***col;

	r = get_txt(fd);
	line = ft_split(r, '\n');
	col = malloc(sizeof(char **) * (size_count(line) + 1));
	i = -1;
	while (line[++i])
		col[i] = ft_split(line[i], ' ');
	col[i] = NULL;
	res.n_line = size_count(line);
	res.len_line = size_count(col[0]);
	res.size = res.n_line * res.len_line;
	res.mat_3d = get_3d(col);
	res.max = max_find(res);
	res.min = min_find(res);
	free(line);
	free(col);
	return (res);
}
