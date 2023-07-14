/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:52:24 by corellan          #+#    #+#             */
/*   Updated: 2023/07/14 18:09:42 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (0);
	while (array[i])
		i++;
	return (i);
}

int	ft_find_string(char **array, char *needle)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		if (!ft_strncmp(array[i], needle, ft_strlen(needle)))
			break ;
		i++;
	}
	return (i);
}
