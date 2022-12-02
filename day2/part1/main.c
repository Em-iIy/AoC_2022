/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/02 14:27:16 by gwinnink         ###   ########.fr       */
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

lOSS			= 0
DRAW			= 3
WIN				= 6

X = ROCK
Y = PAPER
Z = SCISSORS
*/
int	get_score(char opp_move, char p_move)
{
	if (opp_move == p_move - 23)
		return (3 + p_move - 87);
	if ((opp_move == 'A' && p_move == 'Y') || (opp_move == 'B' && p_move == 'Z') || (opp_move == 'C' && p_move == 'X'))
		return (6 + p_move - 87);
	if ((opp_move == 'A' && p_move == 'Z') || (opp_move == 'B' && p_move == 'X') || (opp_move == 'C' && p_move == 'Y'))
		return (0 + p_move - 87);
	return (0);
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
		result += get_score(moves[i][0], moves[i][2]);
		i++;
	}
	printf("score: %d\n", result);
	close(fd);
	return (0);
}
