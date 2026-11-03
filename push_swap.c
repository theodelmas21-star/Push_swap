/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:22:46 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:57:47 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "struct.h"

int	main(int argc, char **argv)
{
	t_stack		*b;
	t_stack		*a;
	int			i;
	t_chunks	**buckets;

	b = NULL;
	if (argc <= 1)
		return (0);
	a = trieur(argv);
	if (a == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = ranking(&a);
	if (i == 0)
		return (ft_lstclear(&a), 0);
	buckets = createchunks(i);
	if (!buckets)
		return (ft_lstclear(&a), 0);
	b = presort(&a, buckets);
	final_sort(&a, &b);
	ft_lstclear(&a);
	return (freebuckets(buckets), 0);
}
