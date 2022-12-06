/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:26:11 by gwinnink          #+#    #+#             */
/*   Updated: 2022/12/06 11:08:22 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	inter_part2(char *s1, char *s2, char *s3)
{
	int		i = 0, j, k;

	while (s1[i] && &s1[i] != s2)
	{
		j = 0;
		{
			while (s2[j])
			{
				if (s2[j] == s1[i])
				{
					k = 0;
					while (s3[k])
					{
						if (s3[k] == s1[i])
							return (s1[i]);
						k++;
					}
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}
