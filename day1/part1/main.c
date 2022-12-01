/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/01 12:11:06 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

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

static void	find_max_kcal(int *max, int kcal)
{
	if (kcal > *max)
		*max = kcal;
}

int	main(void)
{
	int		fd;
	int		max_kcal;
	char	**elf;

	fd = open("input", O_RDONLY);
	max_kcal = 0;
	elf = make_elf(fd);
	while (elf)
	{
		find_max_kcal(&max_kcal, elf_kcal_add(elf));
		ft_free_all(elf);
		elf = make_elf(fd);
	}
	printf("max elf kcal = %d\n", max_kcal);
	close(fd);
	return (0);
}
