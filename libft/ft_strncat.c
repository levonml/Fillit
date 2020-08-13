/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 14:59:56 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/23 13:05:36 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int	c;
	int	x;

	c = 0;
	x = 0;
	while (dest[c] != '\0')
		c++;
	while (n-- > 0 && src[x] != '\0')
	{
		dest[c] = src[x];
		c++;
		x++;
	}
	dest[c] = '\0';
	return (dest);
}
