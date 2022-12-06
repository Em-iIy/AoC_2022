/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:26:11 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 10:46:55 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*inter(char *s1, char *s2)
{
	char	*ret, *temp;
	int		i = 0, j;

	ret = calloc(53, 1);
	if (!ret)
		exit(EXIT_FAILURE);
	temp = ret;
	while (s1[i] && &s1[i] != s2)
	{
		j = 0;
		if (!ft_strchr(ret, s1[i]))
		{
			while (s2[j])
			{
				if (s2[j] == s1[i])
				{
					*temp = s1[i];
					temp++;
					break ;
				}
				j++;
			}
		}
		i++;
	}
	return (ret);
}
