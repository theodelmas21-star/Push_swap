/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:22:48 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/12/22 15:03:34 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "struct.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

void		pa(t_stack **globala, t_stack **globalb);
void		pb(t_stack **globala, t_stack **globalb);
int			pushswap(int argc, char **argv);
void		ra(t_stack **globala);
void		rb(t_stack **globalb);
void		rr(t_stack **globala, t_stack **globalb);
void		rra(t_stack **globala);
void		rrb(t_stack **globalb);
void		rrr(t_stack **globala, t_stack **globalb);
void		sa(t_stack **globala);
void		sb(t_stack **globalb);
void		ss(t_stack **globala, t_stack **globalb);
t_stack		*trieur(char **av);
int			verif(t_stack **global);
t_stack		*ft_lstnew(int content, int i);
void		ft_lstclear(t_stack **lst);
long		ft_atoi(const char *nptr);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
char		**ft_split(char const *s, char c);
t_stack		*presort(t_stack **global, t_chunks **buckets);
int			ranking(t_stack **globala);
void		print_list(t_stack *global);
t_chunks	**createchunks(int nb_elem);
t_stack		*find_position(t_stack *node, t_stack *a);
int			find_min(t_stack *a);
int			find_max(t_stack *a);
int			stack_len(t_stack *global);
int			find_node(t_stack *node, t_stack *a);
t_scenario	calcul_best(t_stack *a, t_stack *b);
t_scenario	calculs_rrr(t_stack *a, t_stack *b, t_stack *node);
t_scenario	calculs_rr_node(t_stack *a, t_stack *b, t_stack *node);
t_scenario	initialise_scenario(void);
int			find_position_index(t_stack *a, t_stack *node);
void		apply_scenario(t_stack **a, t_stack **b);
void		final_sort(t_stack **a, t_stack **b);
t_stack		*prefind_position(t_stack *copy, t_stack *node, t_stack *a);
int			verif_0(const char *nptr);
void		verif_type(t_scenario best, t_stack **a, t_stack **b);
void		freebuckets(t_chunks **buckets);
int			second_errorcase(char *s);
char		*assembleur_core(char *def, char **av, int i);
t_stack		*trieur_core(t_stack *a, char **global);
char		*ft_free_all_assembleur(char **global);

#endif