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

t_node *p_newnode(char *data)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return(NULL);
	new_node->val = ft_atoi(data);
	new_node->nx = NULL;
	return(new_node);
}

void	add_node_to_back(t_node **list, t_node *new)
{
	t_node	*last;
	if (!new)
		return ;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	else
	{
		last = *list;
		while(last->nx)
			last = last->nx;
		last->nx = new;
	}
}

int	main(int ac, char *av[])
{
	t_stacklist	a;
	int			i;
	t_node *new;

	a.len = ac -1;
	a.head = (t_node **)malloc(sizeof(t_node *));
	// a.tail = (t_node *)malloc(sizeof(t_node *));
	i = -1;
	while (++i < a.len)
	{
		new = p_newnode(av[i + 1]);
		add_node_to_back(a.head, new);
	}

	t_node *print_this;
	print_this = *a.head;
	i = - 1;
	while(print_this)
	{
		i++;
		printf("val in node %d is: %d\n", i, print_this->val);
		print_this = print_this->nx;
	}

	printf("a.len is: %d\n", a.len );
	//free
	return (0);
}
