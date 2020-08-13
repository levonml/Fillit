/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:08:03 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/30 11:55:36 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;
	size_t		i;

	ptr_dest = (char*)dest;
	ptr_src = (const char*)source;
	i = -1;
	while (++i < n)
	{
		*(ptr_dest + i) = *(ptr_src + i);
		if (ptr_src[i] == (char)c)
			return (ptr_dest + i + 1);
	}
	return (NULL);
}
