/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:00:44 by nzachari          #+#    #+#             */
/*   Updated: 2024/04/03 16:01:10 by nzachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>

#define NTH	0
#define	SA	1
#define SB	2
#define SS	3
#define PA	4
#define PB	5
#define RA	6
#define RB	7
#define RR	8
#define RRA	9
#define RRB	10
#define RRR	11

/* 
*	nx 	next
*	pv 	prev
*	tdr	total desired rank
*	dr	stk desired rank
*	cr	stk current rank
*/
typedef	struct	s_lnode
{
	int		val;
	struct s_lnode	*nx;
	struct s_lnode	*pv;
	int		tdr;
	int		tcr;
	int		dr;
	int		cr;
}	t_node;

/*
*	hd	head
*	nx	next
*	tl	tail
*/
typedef	struct s_stack
{
	int		len;
	t_node	**head;
	t_node	**tail;
	int		max;
	int		min;
	// int		sorted;
	// int		op;

}	t_stacklist;

/*
*	think of the whole problem as a system
*	with 2 stacks
*/
typedef struct s_ps_system
{
	t_stacklist	a;
	t_stacklist	b;
	int		is_done;
}	t_systm;

#endif