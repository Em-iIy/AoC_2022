/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_crate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:26:36 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 13:41:27 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_stacks_top(t_list **stacks);

static void	lst_push(t_list **src, t_list **dst)
{
	t_list	*temp;

	if (!*src)
		return ;
	temp = (*src)->next;
	ft_lstadd_front(dst, *src);
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
	int		i = 0, n = ft_atoi(ops[1]), src = ft_atoi(ops[3]), dst = ft_atoi(ops[5]);

	while (i < n)
	{
		lst_push(&stacks[src], &stacks[dst]);
		i++;
	}
	ft_free_all(ops);
}

void	move_crates(char **moves, t_list **stacks)
{
	int	i = 0;

	while (moves[i])
	{
		move_crate(moves[i], stacks);
		i++;
	}
	print_stacks_top(stacks);
}
