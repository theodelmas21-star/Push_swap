/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:49:34 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:52:55 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pb(t_stack **globala, t_stack **globalb)
{
	t_stack	*temp;

	if (!*globala)
		return ;
	temp = *globala;
	*globala = temp->next;
	if (*globala != NULL)
	{
		(*globala)->previous = NULL;
	}
	temp->next = *globalb;
	temp->previous = NULL;
	if (*globalb != NULL)
		(*globalb)->previous = temp;
	*globalb = temp;
	write(1, "pb\n", 3);
}
