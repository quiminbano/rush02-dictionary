/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:16:58 by corellan          #+#    #+#             */
/*   Updated: 2023/07/14 18:42:10 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_find_and_print(t_rush *rush)
{
	char	**line;
	int		i;

	i = 1;
	line = NULL;
	rush->index = ft_find_string(rush->parsed, rush->number);
	if (rush->index == ft_array_len(rush->parsed))
		return (1);
	line = ft_parse_line(rush->parsed[rush->index]);
	if (!line)
		return (1);
	while (line[i])
	{
		ft_putstr(line[i]);
		if (line[i + 1])
			ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
	ft_free_split(line);
	return (0);
}
