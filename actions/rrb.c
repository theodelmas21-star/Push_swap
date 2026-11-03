/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:49:47 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:53:33 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rrb(t_stack **globalb)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*globalb == NULL || (*globalb)->next == NULL)
		return ;
	temp = *globalb;
	temp2 = *globalb;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp->next = *globalb;
	(*globalb)->previous = temp;
	*globalb = temp;
	temp->previous = NULL;
	temp2->next = NULL;
	write(1, "rrb", 3);
	write(1, "\n", 1);
}
