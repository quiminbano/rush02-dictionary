/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:52:21 by corellan          #+#    #+#             */
/*   Updated: 2023/07/18 09:52:22 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_find_and_print(t_rush *rush, char *number)
{
	char	**line;
	int		i;

	i = 1;
	line = NULL;
	rush->index = ft_find_string(rush->parsed, number);
	if (rush->index == ft_array_len(rush->parsed) || rush->index == -1)
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
	ft_free_split(line);
	return (0);
}
