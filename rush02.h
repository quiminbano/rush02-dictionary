/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:48:15 by corellan          #+#    #+#             */
/*   Updated: 2023/07/18 09:48:23 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 4

typedef struct s_rush
{
	char	*name;
	char	*document;
	char	*number;
	char	**parsed;
	char	*temp;
	int		index;
	int		flag;
}	t_rush;

char	*ft_strdup(char *src);
int		ft_strlen(char *str);
void	ft_process_document(char *str, int *flag, t_rush *rush);
char	*ft_strjoin_free(char *s1, char *s2);
char	**ft_split(char *str, char c);
void	ft_parse_document(t_rush *rush);
void	ft_free_split(char **split);
int		ft_strncmp(char *str1, char *str2, unsigned int n);
int		ft_check_arg_number(t_rush *rush, int argc, char **argv);
int		ft_find_string(char **array, char *needle);
int		ft_array_len(char **array);
int		ft_find_and_print(t_rush *rush, char *number);
char	**ft_parse_line(char *str);
void	ft_putstr(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_find_recursibly(t_rush *rush, char *number);
char	*ft_strndup(char *str, unsigned int n);
int		ft_first_entry_validation(t_rush *rush, int reserve);

#endif