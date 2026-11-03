/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:40:08 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:55:19 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	while (*lst)
	{
		temp = (*lst);
		*lst = temp->next;
		free(temp);
	}
	*lst = NULL;
}
