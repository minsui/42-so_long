/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:42:01 by mkim2             #+#    #+#             */
/*   Updated: 2026/01/05 10:42:02 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	get_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	num;

	num = n;
	len = get_len(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		res[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (res);
}
