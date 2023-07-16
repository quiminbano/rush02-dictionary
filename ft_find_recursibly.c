/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_recursibly.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 07:02:17 by corellan          #+#    #+#             */
/*   Updated: 2023/07/16 14:12:46 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	ft_add_zeros_print(t_rush *rush, char *number, int len, int zero)
{
	int	i;

	i = 1;
	while (i < len)
	{
		rush->temp = ft_strjoin_free(rush->temp, "0");
		if (!rush->temp)
			return (1);
		i++;
	}
	if (ft_find_and_print(rush, rush->temp))
	{
		free(rush->temp);
		return (1);
	}
	if (ft_strlen(number + zero + 1))
		ft_putstr(" ");
	free(rush->temp);
	return (ft_find_recursibly(rush, (number + zero + 1)));
}

static int	ft_under_thousand(t_rush *rush, char *number, int len)
{
	int	zero;

	zero = 0;
	rush->temp = ft_strndup(number, 1);
	if (!rush->temp)
		return (1);
	if (len == 3)
	{
		if (ft_find_and_print(rush, rush->temp))
			return (free(rush->temp), 1);
		free(rush->temp);
		ft_putstr(" ");
		rush->temp = ft_strndup("1", 1);
		if (!rush->temp)
			return (1);
	}
	while (number[1 + zero] == '0')
		zero++;
	return (ft_add_zeros_print(rush, number, len, zero));
}

static int	over_thousand_aux(t_rush *rush, char *temp, int zero)
{
	rush->temp = ft_strdup("1");
	if (!rush->temp)
	{
		free(temp);
		return (1);
	}
	if (ft_add_zeros_print(rush, temp, ft_strlen(temp), zero))
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}

static int	ft_over_thousand(t_rush *rush, char *number, int len, int reserve)
{
	char	*temp;
	int		zero;

	zero = 0;
	if (ft_first_entry_validation(rush, reserve))
		return (1);
	temp = ft_strndup(number, (len - reserve));
	if (!temp)
		return (1);
	if (ft_find_recursibly(rush, temp))
		return (free(temp), 1);
	ft_putstr(" ");
	free(temp);
	temp = ft_strndup("1", 1);
	if (!temp)
		return (1);
	temp = ft_strjoin_free(temp, (number + (len - reserve)));
	if (!temp)
		return (1);
	while (temp[1 + zero] == '0')
		zero++;
	return (over_thousand_aux(rush, temp, zero));
}

int	ft_find_recursibly(t_rush *rush, char *number)
{
	int	len;
	int	counter;
	int	zero;

	zero = 0;
	counter = 0;
	while (number[0 + zero] == '0' && rush->flag == 1)
		zero++;
	len = ft_strlen(number + zero);
	while ((len - 3) > 0)
	{
		len -= 3;
		counter++;
	}
	len = ft_strlen(number + zero);
	if (len == 0)
		return (0);
	if ((len == 1) || ((number + zero)[0] == '1' && len == 2))
		return (ft_find_and_print(rush, (number + zero)));
	rush->flag = 1;
	if (len > 1 && len < 4)
		return (ft_under_thousand(rush, (number + zero), len));
	else if (len >= 4)
		return (ft_over_thousand(rush, (number + zero), len, (counter * 3)));
	return (1);
}
