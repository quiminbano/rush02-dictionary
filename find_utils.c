/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:52:45 by corellan          #+#    #+#             */
/*   Updated: 2023/07/18 09:52:47 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	ft_initialiaze_numbers(char **numb1, char **numb2, char *needle)
{
	(*numb1) = ft_strjoin(needle, ":");
	if (!(*numb1))
		return (1);
	(*numb2) = ft_strjoin(needle, " ");
	if (!(*numb2))
	{
		free((*numb1));
		return (1);
	}
	return (0);
}

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
	int		i;
	char	*number1;
	char	*number2;

	number1 = NULL;
	number2 = NULL;
	if (ft_initialiaze_numbers(&number1, &number2, needle))
		return (-1);
	i = 0;
	if (!array)
		return (-1);
	while (array[i])
	{
		if (!ft_strncmp(array[i], number1, (ft_strlen(number1))))
			break ;
		else if (!ft_strncmp(array[i], number2, (ft_strlen(number2))))
			break ;
		i++;
	}
	free(number1);
	free(number2);
	return (i);
}
