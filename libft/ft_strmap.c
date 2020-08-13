/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 15:48:13 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/28 14:14:30 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	i = 0;
	if (!s || !f)
		return (0);
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
		return (0);
	while (s[i])
	{
		new[i] = (*f)((char)s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
