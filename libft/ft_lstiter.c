/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlassen <dvlassen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:49:51 by dvlassen          #+#    #+#             */
/*   Updated: 2020/07/08 20:49:53 by dvlassen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*temp;

	temp = lst;
	if (lst != NULL || f != NULL)
	{
		while (temp)
		{
			(*f)(temp);
			temp = temp->next;
		}
	}
}
