/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:26:12 by dvlassen          #+#    #+#             */
/*   Updated: 2020/07/01 12:55:31 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*dub;
	int		c;

	c = 0;
	while (str[c] != '\0')
		c++;
	dub = (char *)malloc(sizeof(*dub) * (c + 1));
	if (!dub)
		return (NULL);
	c = 0;
	while (str[c] != '\0')
	{
		dub[c] = str[c];
		c++;
	}
	dub[c] = '\0';
	return (dub);
}
