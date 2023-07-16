/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_recursibly2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:55:08 by corellan          #+#    #+#             */
/*   Updated: 2023/07/16 12:55:25 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_first_entry_validation(t_rush *rush, int reserve)
{
	int	i;

	i = 0;
	rush->temp = ft_strdup("1");
	if (!rush->temp)
		return (1);
	while (i < reserve)
	{
		rush->temp = ft_strjoin_free(rush->temp, "0");
		if (!rush->temp)
			return (1);
		i++;
	}
	if (ft_find_string(rush->parsed, rush->temp) == ft_array_len(rush->parsed))
	{
		free(rush->temp);
		return (1);
	}
	free(rush->temp);
	return (0);
}
