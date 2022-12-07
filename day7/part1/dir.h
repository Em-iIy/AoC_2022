/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:49:23 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/07 13:13:07 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIR_H
# define DIR_H

typedef struct s_dir
{
	struct s_dir	**next;
	struct s_dir	*prev;
	char			*name;
	int				size;
	int				is_dir;
}	t_dir;

t_dir	*dir_new(t_dir *prev, char *name, int size);
void	dir_print_path(t_dir *dir);

#endif