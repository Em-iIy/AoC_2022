/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/02 15:16:24 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

/*
A = ROCK		= 1
B = PAPER		= 2
C = SCISSORS	= 3

X = LOSS		= 0
Y = DRAW		= 3
Z = WIN			= 6
*/
int	get_score_part_2(char opp_move, char p_move)
{
	int	ret = 0;

	if (p_move == 'X')
	{
		ret = 0;
		if (opp_move == 'A')
			ret += 3;
		else if (opp_move == 'B')
			ret += 1;
		else
			ret += 2;
	}
	else if (p_move == 'Y')
	{
		ret = 3;
		if (opp_move == 'A')
			ret += 1;
		else if (opp_move == 'B')
			ret += 2;
		else
			ret += 3;
	}
	else if (p_move == 'Z')
	{
		ret = 6;
		if (opp_move == 'A')
			ret += 2;
		else if (opp_move == 'B')
			ret += 3;
		else
			ret += 1;
	}
	return (ret);
}

int	main(void)
{
	int			fd;
	t_str_list	*lst_moves;
	char		**moves;
	int			i;
	char		*line;
	int			result;

	i = 0;
	result = 0;
	lst_moves = NULL;
	fd = open("input", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
		ft_str_list_add_front(&lst_moves, ft_str_list_new(line));
	moves = ft_str_list_to_arr(lst_moves);
	while (moves[i])
	{
		result += get_score_part_2(moves[i][0], moves[i][2]);
		i++;
	}
	printf("score: %d\n", result);
	close(fd);
	return (0);
}
