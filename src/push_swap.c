/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:45:09 by nzachari          #+#    #+#             */
/*   Updated: 2024/04/03 16:03:18 by nzachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>
#include <limits.h>

// void	*make_list(t_stack s, int i, char *av[])
// {



// 	// t_ln	node;

// 	node.val = av[i + 1];
// 	if (0 == i)
// 	{
// 		node.pv = NULL;
// 		*(s.hd) = //&node
// 	}
// 	if (a.len == i)
// 		*(s.tl) = //&node

// 	return (s.hd);
// }

t_node *p_newnode(void *data)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return(NULL);
	new_node->val = data;
	new_node->nx = NULL;
	return(new_node);
}

int	main(int ac, char *av[])
{
	t_stacklist	a;
	int			i;
	t_node *new;

	a.len = ac -1;
	a.head = (t_node *)malloc(sizeof(t_node *));
	a.tail = (t_node *)malloc(sizeof(t_node *));
	i = -1;
	while (++i < a.len)
	{
		new = newnode(av[i]);
		add_node_to_back(a.head)
	}

	printf("a.len is: %d\n", a.len );

}
