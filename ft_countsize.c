/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:07:17 by corellan          #+#    #+#             */
/*   Updated: 2023/07/12 20:32:33 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_countsize(char *str, int *flag)
{
	int		fd;
	int		ret;
	int		counter;
	char	buff[BUFFER_SIZE + 1];

	fd = open(str, O_RDONLY);
	ret = 0;
	counter = 0;
	if (fd == -1)
	{
		(*flag) = 1;
		return (0);
	}
	(*flag) = 0;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		counter += ret;
	}
	close(fd);
	return (counter);
}
