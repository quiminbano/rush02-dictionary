/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_document.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:07:17 by corellan          #+#    #+#             */
/*   Updated: 2023/07/13 15:22:28 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	ft_allocate_document(int *fl, char *buff, t_rush *rush, int ret)
{
	if ((*fl) == 0)
	{
		(*fl) = 1;
		rush->document = ft_strdup(buff);
	}
	else if ((*fl) == 1 && ret > 0)
		rush->document = ft_strjoin_free(rush->document, buff);
	return ;
}

static void	ft_iterate_document(int fd, int *flag, t_rush *rush, int ret)
{
	char	buff[BUFFER_SIZE + 1];
	int		fl;

	fl = 0;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
		{
			(*flag) = -1;
			close(fd);
			return ;
		}
		buff[ret] = '\0';
		ft_allocate_document(&fl, buff, rush, ret);
		if (!(rush->document))
		{
			(*flag) = -1;
			close(fd);
			return ;
		}
	}
	close(fd);
}

void	ft_process_document(char *str, int *flag, t_rush *rush)
{
	int	fd;
	int	ret;

	fd = 0;
	ret = 1;
	rush->document = NULL;
	if (str != NULL)
		fd = open(str, O_RDONLY);
	if (fd == -1 || str == NULL)
	{
		(*flag) = -1;
		return ;
	}
	(*flag) = 0;
	ft_iterate_document(fd, flag, rush, ret);
	return ;
}
