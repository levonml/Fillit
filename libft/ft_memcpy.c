/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:37:21 by dvlassen          #+#    #+#             */
/*   Updated: 2020/07/01 12:44:34 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*ptr_src;
	char		*ptr_dest;

	ptr_src = (const char*)src;
	ptr_dest = (char*)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
		*(ptr_dest + n) = *(ptr_src + n);
	return (ptr_dest);
}
