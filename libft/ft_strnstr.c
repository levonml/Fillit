/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 10:59:50 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/30 12:06:44 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	if (str2[0] == '\0')
		return ((char *)str1);
	i = 0;
	while (i < len && str1[i] != '\0')
	{
		j = 0;
		while (str2[j] != '\0')
		{
			if (i + j >= len || str1[i + j] != str2[j])
				break ;
			j++;
		}
		if (str2[j] == '\0')
			return ((char *)(str1 + i));
		i++;
	}
	return (0);
}
