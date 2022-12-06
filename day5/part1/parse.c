/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:01:42 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 13:22:03 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	print_stacks_top(t_list **stacks);
void	print_stacks(t_list **stacks);

static void	fill_stacks(t_list **stacks, char **input, int line)
{
	int		i = 0;
	char	**temp;

	temp = &input[line - 1];
	while (input[line][i])
	{
		if (ft_isdigit(input[line][i]))
		{
			temp = &input[line - 1];
			while (temp >= input)
			{
				if (ft_isalpha((*temp)[i]))
					ft_lstadd_front(&stacks[ft_atoi(&input[line][i])], ft_lstnew(ft_substr(&((*temp)[i]), 0 ,1)));
				temp--;
			}
		}
		i++;
	}
}

t_list	**init_stacks(char **input)
{
	int		i = 0;
	t_list	**ret = calloc(10, sizeof(t_list *));

	if (!ret)
		exit(EXIT_FAILURE);
	while (input[i + 1])
		i++;
	fill_stacks(ret, input, i);
	print_stacks_top(ret);
	return (ret);
}
