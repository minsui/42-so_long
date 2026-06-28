/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:41:47 by mkim2             #+#    #+#             */
/*   Updated: 2026/01/05 10:41:50 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**all_free(char **result, int i)
{
	while (i >= 0)
		free(result[i--]);
	free(result);
	return (NULL);
}

static int	fill_words(char **res, char const *s, char c, int words)
{
	int		i;
	size_t	len;

	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		res[i] = ft_substr(s, 0, len);
		if (!res[i])
		{
			all_free(res, i - 1);
			return (0);
		}
		s += len;
		i++;
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (!fill_words(res, s, c, words))
		return (NULL);
	return (res);
}
