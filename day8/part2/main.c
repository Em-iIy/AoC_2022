/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/08 12:51:31 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int	check_visible_part2(char **input, int	i, int j)
{
	char	c = input[i][j];
	int		k = 0;
	int		up, down, left, right;

	// check up
	// printf("check input[%d][%d]: %c\t", i, j, c);
	while (i - k >= 0)
	{
		if (input[i - k][j] >= c && i - k != i)
		{
			k++;
			break ;
		}
		k++;
	}
	up = k - 1;
	k = 0;
	// check down
	while (input[i + k] && input[i + k][j])
	{
		if (input[i + k][j] >= c && i + k != i)
		{
			k++;
			break ;
		}
		k++;
	}
	down = k - 1;
	k = 0;
	// check left
	while (j - k >= 0)
	{
		if (input[i][j - k] >= c && j - k != j)
		{
			k++;
			break ;
		}
		k++;
	}
	left = k - 1;
	k = 0;
	// check right
	while (input[i][j + k] && input[i][j + k] != '\n')
	{
		if (input[i][j + k] >= c && j + k != j)
		{
			k++;
			break ;
		}
		k++;
	}
	right = k - 1;
	// printf("up: %d left: %d right: %d down: %d total: %d\n", up, left, right, down, up * left * right * down);
	return (up * left * right * down);
}

int	main(void)
{
	int			fd;
	t_str_list	*lst_input;
	char		**input;
	int			i = 0, j, k;
	char		*line;
	int			result = 0;

	lst_input = NULL;
	fd = open("input", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_str_list_add_front(&lst_input, ft_str_list_new(line));
		free(line);
	}
	input = ft_str_list_to_arr(lst_input);
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (input[i][j] != '\n')
			{
				k = check_visible_part2(input, i, j);
				if (result < k)
					result = k;
			}
			j++;
		}
		i++;
	}
	printf("score: %d\n", result);
	close(fd);
	return (0);
}
