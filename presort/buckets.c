/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:38:57 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 10:57:47 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "../struct.h"

int	optimised_size(int nb_elem)
{
	if (nb_elem <= 20)
		return (1);
	if (nb_elem <= 100)
		return (1);
	if (nb_elem <= 500)
		return (3);
	if (nb_elem > 500)
		return (50);
	return (0);
}

void	chunkelse(t_chunks **buckets, int i, int nb_elem)
{
	int	op_size;
	int	reste;

	op_size = optimised_size(nb_elem);
	reste = nb_elem % op_size;
	if (i == 0)
		buckets[i]->start = 0;
	else
		buckets[i]->start = buckets[i - 1]->end + 1;
	buckets[i]->end = buckets[i]->start + (nb_elem / op_size - 1);
	if (i < reste)
		buckets[i]->end++;
	buckets[i]->size = buckets[i]->end - buckets[i]->start + 1;
	buckets[i]->mid = (buckets[i]->size / 2) + buckets[i]->start;
}

void	freebuckets(t_chunks **buckets)
{
	int	i;

	i = 0;
	while (buckets[i])
	{
		free(buckets[i++]);
	}
	free(buckets);
}

t_chunks	**createchunks(int nb_elem)
{
	t_chunks	**buckets;
	int			i;
	int			op_size;

	i = 0;
	op_size = optimised_size(nb_elem);
	buckets = malloc(sizeof(t_chunks *) * (op_size + 1));
	if (!buckets)
		return (NULL);
	while (i < op_size)
	{
		buckets[i] = malloc(sizeof(t_chunks));
		if (!buckets[i])
			return (freebuckets(buckets), NULL);
		chunkelse(buckets, i, nb_elem);
		i++;
	}
	buckets[i] = NULL;
	return (buckets);
}
