/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 14:04:07 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

t_list	**init_stacks(char **input);
void	move_crates_part2(char **moves, t_list **stacks);

int	main(void)
{
	int			fd;
	t_str_list	*lst_input;
	char		**input;
	t_str_list	*lst_moves;
	char		**moves;
	int			i = 0;
	char		*line;
	int			result = 0;

	lst_input = NULL;
	lst_moves = NULL;
	fd = open("input.txt", O_RDONLY);
	while (ft_strncmp((line = get_next_line(fd)), "\n", 2))
	{
		ft_str_list_add_front(&lst_input, ft_str_list_new(line));
		free(line);
	}
	free(line);
	input = ft_str_list_to_arr(lst_input);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_str_list_add_front(&lst_moves, ft_str_list_new(line));
		free(line);
	}
	moves = ft_str_list_to_arr(lst_moves);
	close(fd);
	move_crates_part2(moves, init_stacks(input));
	return (0);
}
