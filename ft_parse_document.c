/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_document.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:51:20 by corellan          #+#    #+#             */
/*   Updated: 2023/07/18 09:51:21 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	ft_is_invalid_aux(char *str, int i)
{
	if (!str[i])
		return (1);
	while (str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	while (str[i] > 31 && str[i] < 127)
		i++;
	if (i < ft_strlen(str))
		return (1);
	return (0);
}

static int	ft_is_invalid(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 48 && str[i] <= 57) || str[i] == 43)
	{
		if (i != 0 && str[i] == 43)
			return (1);
		else if (i == 0 && str[i] == 43 && (str[i + 1] < 48 || \
			str[i + 1] > 57))
			return (1);
		i++;
	}
	while (str[i] == ' ')
	{
		if (i == 0)
			return (1);
		i++;
	}
	if (str[i] != ':')
		return (1);
	i++;
	return (ft_is_invalid_aux(str, i));
}

void	ft_parse_document(t_rush *rush)
{
	int	i;

	i = 0;
	rush->parsed = ft_split(rush->document, '\n');
	if (!(rush->parsed))
		return ;
	while (rush->parsed[i])
	{
		if (ft_is_invalid(rush->parsed[i]))
		{
			ft_free_split(rush->parsed);
			rush->parsed = NULL;
			return ;
		}
		i++;
	}
	return ;
}
