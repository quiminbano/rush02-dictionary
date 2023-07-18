/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:48:38 by corellan          #+#    #+#             */
/*   Updated: 2023/07/18 09:48:51 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strncmp(char *str1, char *str2, unsigned int n)
{
	unsigned int	i;
	int				s1;
	int				s2;

	i = 0;
	while ((str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0') && \
			(i < (n - 1)))
		i++;
	s1 = (unsigned const char)str1[i];
	s2 = (unsigned const char)str2[i];
	if (n == 0)
		return (0);
	if (s1 == s2)
		return (0);
	else
		return (s1 - s2);
}
