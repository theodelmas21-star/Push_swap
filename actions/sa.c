/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:49:57 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 11:12:03 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa(t_stack **globala)
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
	write(1, "sa\n", 3);
}
