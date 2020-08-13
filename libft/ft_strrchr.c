/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:05:53 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/30 13:28:04 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int length;

	length = 0;
	while (str[length])
		length++;
	while (length >= 0)
	{
		if (str[length] == ch)
			return ((char*)str + length);
		length--;
	}
	return (NULL);
}
