/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:26:10 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 13:25:21 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("-%s", stack->content);
		stack = stack->next;
	}
	printf("-\n");
}

void	print_stacks(t_list **stacks)
{
	int	i = 0;

	while (i < 10)
	{
		if (stacks[i])
			print_stack(stacks[i]);
		i++;
	}
	printf("\n");
}

void	print_stacks_top(t_list **stacks)
{
	int	i = 0;

	while (i < 10)
	{
		if (stacks[i])
			printf("%s", (char *)(stacks[i]->content));
		i++;
	}
	printf("\n");
}
