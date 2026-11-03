/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:50:01 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:53:56 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sb(t_stack **globalb)
{
	t_stack	*second;
	t_stack	*first;

	if (*globalb != NULL || (*globalb)->next != NULL)
	{
		second = (*globalb)->next;
		first = *globalb;
		first->next = second->next;
		second->next = first;
		*globalb = second;
	}
	write(1, "sb\n", 3);
}
