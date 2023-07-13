/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:59:49 by corellan          #+#    #+#             */
/*   Updated: 2023/07/13 13:25:46 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	ft_strlen_pos(char *str, int start, char c)
{
	int	i;

	i = 0;
	while (str[i + start] != '\0' && str[i + start] != c)
		i++;
	return (i);
}

static int	ft_index_after_char(char *str, int pos, char c)
{
	int	i;

	i = 0;
	while (str[i + pos] == c)
		i++;
	return (i + pos);
}

static int	ft_words(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && str[i] != 0) && (str[i + 1] == c || \
			str[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

static char	*ft_strdup_pos(char *src, int start, char c)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen_pos(src, start, c);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[start + i] != '\0' && src[start + i] != c)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char c)
{
	int		words;
	char	**split;
	int		index;
	int		i;

	words = ft_words(str, c);
	i = 0;
	index = 0;
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = NULL;
	while (i < words)
	{
		index = ft_index_after_char(str, index, c);
		split[i] = ft_strdup_pos(str, index, c);
		if (!split[i])
			return (ft_free_split(split), NULL);
		index += ft_strlen_pos(str, index, c);
		i++;
	}
	return (split);
}
