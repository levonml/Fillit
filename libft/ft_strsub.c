/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:17:56 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/25 21:14:01 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!(subs = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_strncpy(subs, (char *)s + start, (int)len);
	subs[len] = '\0';
	return (subs);
}
