/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:50:05 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:54:03 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa_ss(t_stack **globala)
{
	t_stack	*second;
	t_stack	*first;

	if (*globala != NULL || (*globala)->next != NULL)
	{
		second = (*globala)->next;
		first = *globala;
		if (second->next == NULL)
			first->next = NULL;
		else
			first->next = second->next;
		first->previous = second;
		second->previous = NULL;
		second->next = first;
		*globala = second;
	}
}

void	sb_ss(t_stack **globalb)
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
}

void	ss(t_stack **globala, t_stack **globalb)
{
	sa_ss(globala);
	sb_ss(globalb);
	write(1, "ss\n", 3);
}
