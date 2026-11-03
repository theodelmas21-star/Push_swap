/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:49:42 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:53:21 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ra_rr(t_stack **globala)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*globala == NULL || (*globala)->next == NULL)
		return ;
	temp = *globala;
	temp2 = *globala;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = temp2;
	*globala = (*globala)->next;
	(*globala)->previous = NULL;
	temp2->previous = temp;
	temp2->next = NULL;
}

void	rb_rr(t_stack **globalb)
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
}

void	rr(t_stack **globala, t_stack **globalb)
{
	ra_rr(globala);
	rb_rr(globalb);
	write(1, "rr\n", 3);
}
