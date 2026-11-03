/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:22:58 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 11:14:15 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "pushswap.h"

typedef enum e_type
{
	UU,
	DD,
	UD,
	DU,
}					t_type;

typedef struct s_stack
{
	struct s_stack	*previous;
	int				content;
	int				rank;
	struct s_stack	*next;
}					t_stack;

typedef struct t_chunks
{
	int				start;
	int				end;
	int				mid;
	int				size;
}					t_chunks;

typedef struct s_scenario
{
	int				ra;
	int				rra;
	int				rrb;
	int				rb;
	int				total;
	t_type			type;
	t_stack			*node;
}					t_scenario;

typedef struct t_data
{
	int				len_a;
	int				index;
	int				len_b;
	t_stack			*a;
}					t_data;

#endif