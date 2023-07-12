/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:22:02 by corellan          #+#    #+#             */
/*   Updated: 2023/07/13 01:14:26 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 4

typedef struct	s_rush
{
	char	*name;
	char	*document;
}	t_rush;

char	*ft_strdup(char *src);
int		ft_strlen(char *str);
void	ft_process_document(char *str, int *flag, t_rush *rush);
char	*ft_strjoin_free(char *s1, char *s2);

#endif