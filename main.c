/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:21:53 by corellan          #+#    #+#             */
/*   Updated: 2023/07/13 23:37:45 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	main_cont(t_rush *rush, int argc, char **argv)
{
	rush->parsed = NULL;
	if (ft_check_arg_number(rush, argc, argv))
	{
		write(2, "Error\n", 11);
		free(rush->name);
		free(rush->document);
		if (rush->number)
			free(rush->number);
		return (1);
	}
	ft_parse_document(rush);
	if (!rush->parsed)
	{
		write(2, "Dict Error\n", 11);
		free(rush->name);
		free(rush->document);
		return (1);
	}
	free(rush->name);
	free(rush->document);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rush	rush;
	int		flag;

	rush.name = NULL;
	rush.document = NULL;
	if (argc > 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc > 0 && argc < 3)
		rush.name = ft_strdup("numbers.dict");
	else
		rush.name = ft_strdup(argv[1]);
	ft_process_document(rush.name, &flag, &rush);
	if (flag == -1)
	{
		if (rush.name != NULL)
			free(rush.name);
		if (rush.document != NULL)
			free(rush.document);
		write(STDERR_FILENO, "Dict Error\n", 11);
		return (1);
	}
	return (main_cont(&rush, argc, argv));
}
