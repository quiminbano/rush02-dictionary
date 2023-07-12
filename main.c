/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:21:53 by corellan          #+#    #+#             */
/*   Updated: 2023/07/12 20:39:48 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	int		buffer;
	int		flag;
	char	*document;

	if (argc < 1 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc > 0 && argc < 3)
		buffer = ft_countsize("numbers.dict", &flag);
	else
		buffer = ft_countsize(argv[1], &flag);
	if (flag == -1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	document = ft_process_document(buffer, );
	return (0);
}
