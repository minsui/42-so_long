/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:00:29 by mkim2             #+#    #+#             */
/*   Updated: 2026/01/08 19:19:52 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)

{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	if (len == 0 && !big)
		return (0);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (!little[j + 1])
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}
