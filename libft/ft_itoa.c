/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:19:52 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/26 10:20:44 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*dest;
	int		len;
	int		c;

	c = 0;
	len = ft_len(n);
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
	{
		dest[0] = '-';
		c++;
	}
	dest[len] = '\0';
	while (len-- > c)
	{
		dest[len] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (dest);
}
