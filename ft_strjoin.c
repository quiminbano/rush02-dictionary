/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:51:53 by corellan          #+#    #+#             */
/*   Updated: 2023/07/15 20:52:53 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strjoin(char *s1, char *s2)
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
		return (NULL);
	dest[l1 + l2] = '\0';
	while (i < (l1 + l2))
	{
		if (i < l1)
			dest[i] = s1[i];
		else
			dest[i] = s2[i - l1];
		i++;
	}
	return (dest);
}
