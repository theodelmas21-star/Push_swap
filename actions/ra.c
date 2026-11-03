/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:49:37 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:53:03 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ra(t_stack **globala)
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
	write(1, "ra\n", 3);
}
