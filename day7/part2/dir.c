/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:52:00 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/07 13:31:06 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "dir.h"

void	dir_print_path(t_dir *dir)
{
	if (dir->prev)
		dir_print_path(dir->prev);
	if (dir->size)
		printf("%s", dir->name);
	else if (dir->prev)
		printf("%s/", dir->name);
}

t_dir	*dir_new(t_dir *prev, char *name, int size)
{
	t_dir	*ret = malloc(sizeof(t_dir));
	if (!ret)
		exit(EXIT_FAILURE);
	ret->name = ft_strtrim(name, "\n");
	ret->size = size;
	ret->is_dir = 0;
	if (!size)
		ret->is_dir++;
	ret->prev = prev;
	ret->next = NULL;
	printf("size: %10d\tcreated: ", size);
	dir_print_path(ret);
	printf("\n");
	return (ret);
}

