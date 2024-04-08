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

void	print_list(t_stacklist *lst)
{
	int i;
	t_node *print_this;
	print_this = *lst->head;
	i = - 1;
	while(print_this)
	{
		i++;
		printf("tdr in node %d is: %d\n", i, print_this->tdr);
		print_this = print_this->nx;
	}
}

void	putstruct(t_node *node, int *tmp)
{
	printf("node's val is: %d\n", node->val);
	
	// printf("*tmp is: %d\n", tmp[1]);
	int i;
	i = -1;
	while(tmp && *(tmp + 1))
	{
		++i;
		// printf("in putstruct while, i is: %d\n",i );
		if (node->val == tmp[i])
		{
			node->tdr = i;
			break ;
		}
	}

}

void	iter_stacklist(t_stacklist *lst, int *tmp, void (*f)(t_node *, int *))
{
	t_node	*this_node;

	this_node = *lst->head;
	while(this_node)
	{
		f(this_node, tmp);
		this_node = this_node->nx;
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

	// print_list(&a);

//find out tdr using array
	int *tmp_arr;
	tmp_arr = malloc(sizeof(int) * (a.len));
	
	//write from av to array
	int c = -1;
	while (++c < a.len)
		tmp_arr[c] = ft_atoi(av[c + 1]);
	
	//sort the array
	c = -1;
	int max;
	int tmp;
	while(++c < (a.len - 1))
	{
		max = tmp_arr[c];
		if (tmp_arr[c + 1] < max)
		{
			tmp = tmp_arr[c];
			tmp_arr[c] = tmp_arr[c + 1];
			tmp_arr[c + 1] = tmp;
			c = -1;
		}
	}

	//test print the arr
	c = -1;
	while (++c < a.len)
		printf("val in tmp_arr is: %d\n", tmp_arr[c]);

	printf("before iter\n");
	//iter thru list, then iter thru array to find the idx to update the tdr 
	iter_stacklist(&a, tmp_arr, putstruct);
	printf("after iter\n");



	print_list(&a);



	printf("a.len is: %d\n", a.len );
	//free
	return (0);
}
