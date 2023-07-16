/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:04:12 by corellan          #+#    #+#             */
/*   Updated: 2023/07/16 12:30:57 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	ft_analize_string(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (!str[i])
		return (1);
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i < ft_strlen(str))
		return (1);
	return (0);
}

static char	*ft_copynumber(char *str)
{
	int	i;

	i = 0;
	if (ft_analize_string(str))
		return (NULL);
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		i--;
	return (ft_strdup(str + i));
}

static void	ft_allocate_number(int *fl, char *buff, char **number, int ret)
{
	if ((*fl) == 0 && buff[0] != '\n')
	{
		(*fl) = 1;
		(*number) = ft_strdup(buff);
	}
	else if ((*fl) == 1 && ret > 0 && buff[0] != '\n')
		(*number) = ft_strjoin_free((*number), buff);
	return ;
}

static void	ft_from_stdin(char **number)
{
	char	buff[2];
	int		ret;
	int		fl;

	ret = 1;
	fl = 0;
	while (ret > 0)
	{
		ret = read(STDIN_FILENO, buff, 1);
		if (ret < 0)
		{
			if ((*number) != NULL)
			{
				free(*number);
				(*number) = NULL;
				return ;
			}
		}
		buff[ret] = '\0';
		ft_allocate_number(&fl, buff, number, ret);
		if (buff[0] == '\n')
			break ;
	}
	return ;
}

int	ft_check_arg_number(t_rush *rush, int argc, char **argv)
{
	char	*temp;

	rush->number = NULL;
	temp = NULL;
	if (argc == 2)
		rush->number = ft_copynumber(argv[1]);
	else if (argc == 3)
		rush->number = ft_copynumber(argv[2]);
	else
	{
		ft_from_stdin(&temp);
		if (!temp)
			return (1);
		rush->number = ft_copynumber(temp);
	}
	if (!rush->number)
		return (1);
	return (0);
}
