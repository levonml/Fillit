/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:08:52 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/30 12:02:33 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i] && i < n)
		i++;
	return ((i != n) ? ((unsigned char)str1[i] - (unsigned char)str2[i]) :
			((unsigned char)str1[i - 1] - (unsigned char)str2[i - 1]));
}
