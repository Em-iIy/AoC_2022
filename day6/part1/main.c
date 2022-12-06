/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 15:12:36 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"


int	check_marker(char *str)
{
	int	i = 0, j;

	while (str[i] && i < 4)
	{
		j = i + 1;
		while (str[j] && j < 4)
		{
			if (str[i] == str[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(void)
{
	int			fd;
	int			i = 0;
	char		*line;
	int			result = 0;

	fd = open("input", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	while (line[i])
	{
		if ((result = check_marker(&line[i])) == 1)
			return (printf("score: %d\n", i + 4) * 0);
		i++;
	}
	close(fd);
	return (0);
}
