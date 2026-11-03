/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:49:39 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:53:09 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rb(t_stack **globalb)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*globalb == NULL || (*globalb)->next == NULL)
		return ;
	temp = *globalb;
	temp2 = *globalb;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = temp2;
	*globalb = (*globalb)->next;
	(*globalb)->previous = NULL;
	temp2->previous = temp;
	temp2->next = NULL;
	write(1, "rb\n", 3);
}
