/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_document.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:29:04 by corellan          #+#    #+#             */
/*   Updated: 2023/07/13 13:36:22 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_parce_document(t_rush *rush)
{
	rush->parsed = ft_split(rush->document, '\n');
	if (!(rush->parsed))
		return ;
	return ;
}
