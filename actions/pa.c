/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:49:31 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:52:44 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pa(t_stack **globala, t_stack **globalb)
{
	t_stack	*temp;

	if (!*globalb)
		return ;
	temp = *globalb;
	*globalb = (*globalb)->next;
	if (*globalb != NULL)
	{
		(*globalb)->previous = NULL;
	}
	temp->next = *globala;
	temp->previous = NULL;
	if (*globala != NULL)
		(*globala)->previous = temp;
	*globala = temp;
	write(1, "pa\n", 3);
}
