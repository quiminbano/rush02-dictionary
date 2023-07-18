/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:49:59 by corellan          #+#    #+#             */
/*   Updated: 2023/07/18 09:50:01 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		l1;
	int		l2;
	char	*dest;

	dest = NULL;
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!dest)
		return (free(s1), NULL);
	dest[l1 + l2] = '\0';
	while (i < (l1 + l2))
	{
		if (i < l1)
			dest[i] = s1[i];
		else
			dest[i] = s2[i - l1];
		i++;
	}
	free(s1);
	return (dest);
}
