/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_crate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:26:36 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 14:38:57 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	print_stacks_top(t_list **stacks);
void	print_stacks(t_list **stacks);

static void	lst_crates_to_front(t_list **dst, t_list *start, t_list *end)
{
	end->next = *dst;
	*dst = start;
}

static void	lst_push(t_list **src, t_list **dst, int n)
{
	t_list	*temp, *temp2, *temp3;
	int		i = 0;

	if (!*src)
		return ;
	temp = *src;
	temp2 = *src;
	temp3 = *src;
	while (i < n)
	{
		temp = temp->next;
		i++;
	}
	while (temp2->next != temp)
		temp2 = temp2->next;
	lst_crates_to_front(dst, temp3, temp2);
	*src = temp;
}

/*
ops[1] = amount of crates moved
ops[3] = src stack
ops[5] = dst stack
*/
static void	move_crate(char *move, t_list **stacks)
{
	char	**ops = ft_split(move, ' ');
	int		n = ft_atoi(ops[1]), src = ft_atoi(ops[3]), dst = ft_atoi(ops[5]);

	lst_push(&stacks[src], &stacks[dst], n);
	ft_free_all(ops);
}

void	move_crates_part2(char **moves, t_list **stacks)
{
	int	i = 0;

	while (moves[i])
	{
		move_crate(moves[i], stacks);
		i++;
	}
	print_stacks_top(stacks);
}
