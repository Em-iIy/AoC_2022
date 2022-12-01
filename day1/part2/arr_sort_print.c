/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:26:41 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/01 12:48:42 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	arr_swap(int *s1, int *s2)
{
	int	temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	print_answer(int *arr)
{
	int	i;
	int	ans;

	i = 0;
	while (arr[i])
		i++;
	ans = arr[i - 1] + arr[i - 2] + arr[i - 3];
	printf("top 3 elves: %d\n", ans);
}

void	arr_sort_print(int *arr)
{
	int	i;
	int	j;


	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[j] && arr[j + 1])
		{
			if (arr[j] > arr[j + 1])
				arr_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (arr[i])
		i++;
	print_answer(arr);
}
