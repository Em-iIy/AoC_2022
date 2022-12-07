/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/07 13:46:20 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "dir.h"

#define FREE_SPACE 24650017

int	result = 2147483647;

t_dir	*dir_cd(t_dir *cwd, char *dst)
{
	int	i = 0;

	if (!ft_strncmp(dst, "..", 2))
		return (cwd->prev);
	while (cwd->next[i] && ft_strncmp(dst, cwd->next[i]->name, ft_strlen(dst) - 1))
		i++;
	return (cwd->next[i]);
}

void	dir_ls(t_dir *cwd, char **input)
{
	int	i = 0;
	char	**temp;

	while (input[i] && input[i][0] != '$')
		i++;
	cwd->next = (t_dir **)calloc(i + 1, sizeof(t_dir *));
	if (!cwd->next)
		exit (EXIT_FAILURE);
	i = 0;
	while (input[i] && input[i][0] != '$')
	{
		temp = ft_split(input[i], ' ');
		cwd->next[i] = dir_new(cwd, temp[1], ft_atoi(temp[0]));
		ft_free_all(temp);
		i++;
	}
}

t_dir	*parse_input(char **input)
{
	int	i = 0;
	t_dir	*ret = dir_new(NULL, "/", 0);
	t_dir	*cwd = ret;

	while (input[i])
	{
		if (input[i][0] != '$')
		{
			i++;
			continue ;
		}
		if (!ft_strncmp(&input[i][2], "ls", 2))
			dir_ls(cwd, &input[i + 1]);
		else
			cwd = dir_cd(cwd, &input[i][5]);
		i++;
	}
	return (ret);
}

void	get_dir_size(t_dir *dir)
{
	int	i = 0;

	if (!dir)
		return ;
	while (dir->next[i])
	{
		if (dir->next[i]->is_dir)
			get_dir_size(dir->next[i]);
		dir->size += dir->next[i]->size;
		i++;
	}
	if (FREE_SPACE + dir->size >= 30000000 && dir->size < result)
		result = dir->size;
}

int	main(void)
{
	int			fd;
	t_dir		*dir;
	t_str_list	*lst_input;
	char		**input;
	int			i = 0;
	char		*line;

	lst_input = NULL;
	fd = open("input", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_str_list_add_front(&lst_input, ft_str_list_new(line));
		free(line);
	}
	input = ft_str_list_to_arr(lst_input);
	dir = parse_input(input + 1);
	get_dir_size(dir);
	printf("size: %d\n", result);
	close(fd);
	return (0);
}
