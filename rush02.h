/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:22:02 by corellan          #+#    #+#             */
/*   Updated: 2023/07/13 23:12:51 by corellan         ###   ########.fr       */
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
	char	*number;
	char	**parsed;
}	t_rush;

char	*ft_strdup(char *src);
int		ft_strlen(char *str);
void	ft_process_document(char *str, int *flag, t_rush *rush);
char	*ft_strjoin_free(char *s1, char *s2);
char	**ft_split(char *str, char c);
void	ft_parse_document(t_rush *rush);
void	ft_free_split(char **split);
int		ft_strncmp(char *str1, char *str2, unsigned int n);

#endif