/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:24:54 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:55:24 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack	*ft_lstnew(int content, int i)
{
	t_stack	*new_list;

	new_list = malloc(sizeof(t_stack));
	if (!new_list)
		return (0);
	new_list->content = content;
	new_list->rank = i;
	new_list->next = NULL;
	new_list->previous = NULL;
	return (new_list);
}
