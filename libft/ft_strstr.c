/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:26:05 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/30 13:25:00 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str2, const char *str1)
{
	size_t	i;
	size_t	j;

	if (str1[0] == '\0')
		return ((char *)str2);
	i = 0;
	while (str2[i] != '\0')
	{
		j = 0;
		while (str1[j] != '\0')
		{
			if (str2[i + j] != str1[j])
				break ;
			j++;
		}
		if (str1[j] == '\0')
			return ((char *)(str2 + i));
		i++;
	}
	return (0);
}
