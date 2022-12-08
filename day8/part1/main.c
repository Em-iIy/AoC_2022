/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/08 12:16:12 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int	check_visible(char **input, int	i, int j)
{
	char	c = input[i][j];
	int		k = 0;
	int		ret = 1;

	// check up
	if (i == 0)
		return (1);
	while (i - k >= 0)
	{
		if (input[i - k][j] >= c && i - k != i)
		{
			ret = 0;
			break ;
		}
		k++;
	}
	if (ret)
		return (ret);
	k = 0;
	ret = 1;
	// check down
	if (input[i + 1] == NULL)
		return (1);
	while (input[i + k] && input[i + k][j])
	{
		if (input[i + k][j] >= c && i + k != i)
		{
			ret = 0;
			break ;
		}
		k++;
	}
	if (ret)
		return (ret);
	k = 0;
	ret = 1;
	// check left
	if (j == 0)
		return (1);
	while (j - k >= 0)
	{
		// printf("c: %c checked against %c\n", c, input[i][j - k]);
		if (input[i][j - k] >= c && j - k != j)
		{
			ret = 0;
			break ;
		}
		k++;
	}
	if (ret)
		return (ret);
	k = 0;
	ret = 1;
	// check right
	if (input[i][j + 1] == '\n')
		return (1);
	while (input[i][j + k] && input[i][j + k] != '\n')
	{
		if (input[i][j + k] >= c && j + k != j)
		{
			ret = 0;
			break ;
		}
		k++;
	}
	return (ret);
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
				k = check_visible(input, i, j);
				printf("%d", k);
				result += k;
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("score: %d\n", result);
	close(fd);
	return (0);
}
