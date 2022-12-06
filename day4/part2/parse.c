/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:20:06 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 11:42:40 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_overlap(char *str)
{
	char	**range = ft_split(str, ',');
	char	**e1 = ft_split(range[0], '-');
	char	**e2 = ft_split(range[1], '-');
	int		ret = 0;

	if (ft_atoi(e1[0]) <= ft_atoi(e2[0]) && ft_atoi(e1[1]) >= ft_atoi(e2[1])) // check if elf 1 fully contains elf 2
		ret++;
	else if (ft_atoi(e2[0]) <= ft_atoi(e1[0]) && ft_atoi(e2[1]) >= ft_atoi(e1[1])) // check if elf 2 fully contains elf 1
		ret++;
	else if (ft_atoi(e1[0]) <= ft_atoi(e2[1]) && ft_atoi(e1[1]) >= ft_atoi(e2[1])) // check if start of elf 1 is before end of elf 2
		ret++;
	else if (ft_atoi(e2[0]) <= ft_atoi(e1[1]) && ft_atoi(e2[1]) >= ft_atoi(e1[1])) // check if start of elf 2 is before end of elf 1
		ret++;
	ft_free_all(e1);
	ft_free_all(e2);
	ft_free_all(range);
	return (ret);
}
