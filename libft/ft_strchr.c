/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 16:26:42 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/30 11:59:55 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char*)str + i);
		i++;
	}
	if (str[i] == '\0' && ch == '\0')
		return ((char*)str + i);
	return (NULL);
}
