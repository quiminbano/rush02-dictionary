/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:48:01 by corellan          #+#    #+#             */
/*   Updated: 2023/07/18 09:48:03 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strndup(char *str, unsigned int n)
{
	char			*dest;
	unsigned int	i;

	dest = NULL;
	i = 0;
	if (n == 0)
		return (dest);
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	dest[n] = '\0';
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
