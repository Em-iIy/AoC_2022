/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 11:43:05 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int	check_overlap(char *str);

int	main(void)
{
	int			fd;
	t_str_list	*lst_input;
	char		**input;
	int			i = 0;
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
		result += check_overlap(input[i]);
		i++;
	}
	printf("score: %d\n", result);
	close(fd);
	return (0);
}
