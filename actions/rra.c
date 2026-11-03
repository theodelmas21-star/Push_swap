/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:49:44 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:53:27 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rra(t_stack **globala)
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
	write(1, "rra\n", 4);
}
