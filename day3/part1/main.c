/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 10:54:45 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

char	*inter(char *s1, char *s2);

int	get_priority(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 38);
	if (c >= 'a' && c <= 'z')
		return (c - 96);
	return (0);
}

int	main(void)
{
	int			fd;
	t_str_list	*lst_sack;
	char		**sack;
	int			i = 0;
	char		*line;
	int			result = 0;

	lst_sack = NULL;
	fd = open("input", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_str_list_add_front(&lst_sack, ft_str_list_new(line));
		free(line);
	}
	sack = ft_str_list_to_arr(lst_sack);
	while (sack[i])
	{
		// printf("c1: %s\tc2: %s\t", sack[i], &sack[i][(ft_strlen(sack[i]) / 2)]);
		// printf("inter: %s\n", inter(sack[i], &sack[i][(ft_strlen(sack[i]) / 2)]));
		line = inter(sack[i], &sack[i][(ft_strlen(sack[i]) / 2)]);
		result += get_priority(*line);
		free(line);
		i++;
	}
	printf("score: %d\n", result);
	close(fd);
	return (0);
}
