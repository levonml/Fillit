/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:28:20 by dvlassen          #+#    #+#             */
/*   Updated: 2020/06/30 11:37:46 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int cpt;
	int nb;
	int neg;

	cpt = 0;
	neg = 0;
	nb = 0;
	while (str[cpt] == ' ' || str[cpt] == '\n' || str[cpt] == '\v' ||
	str[cpt] == '\r' || str[cpt] == '\t' || str[cpt] == '\f')
		cpt++;
	if (str[cpt] == '-')
		neg = 1;
	if (str[cpt] == '+' || str[cpt] == '-')
		cpt++;
	while (str[cpt] >= '0' && str[cpt] <= '9')
	{
		nb *= 10;
		nb += (str[cpt] - 48);
		cpt++;
	}
	return (neg == 1 ? -nb : nb);
}
