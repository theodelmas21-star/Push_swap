/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:49:53 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:53:40 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rra_rrr(t_stack **globala)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*globala == NULL || (*globala)->next == NULL)
		return ;
	temp = *globala;
	temp2 = *globala;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp->next = *globala;
	(*globala)->previous = temp;
	*globala = temp;
	temp->previous = NULL;
	temp2->next = NULL;
}

void	rrb_rrr(t_stack **globalb)
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
}

void	rrr(t_stack **globala, t_stack **globalb)
{
	rra_rrr(globala);
	rrb_rrr(globalb);
	write(1, "rrr\n", 4);
}
