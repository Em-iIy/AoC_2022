/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/01 12:44:17 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void	arr_sort_print(int *arr);

static int	elf_kcal_add(char **elf)
{
	int	i;
	int	kcal;

	i = 0;
	kcal = 0;
	while (elf[i])
	{
		kcal += ft_atoi(elf[i]);
		i++;
	}
	return (kcal);
}

static char	**make_elf(int fd)
{
	t_str_list	*elf_list;
	char		*line;

	elf_list = NULL;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line && ft_strncmp(line, "\n", 2))
	{
		ft_str_list_add_front(&elf_list, ft_str_list_new(line));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (ft_str_list_to_arr(elf_list));
}

int	main(void)
{
	int		fd;
	char	**elf;
	int		i;
	int		arr[267];

	fd = open("input", O_RDONLY);
	i = 0;
	elf = make_elf(fd);
	arr[266] = 0;
	while (elf)
	{
		arr[i] = elf_kcal_add(elf);
		i++;
		ft_free_all(elf);
		elf = make_elf(fd);
	}
	arr_sort_print(arr);
	close(fd);
	return (0);
}
