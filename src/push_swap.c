/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:45:09 by nzachari          #+#    #+#             */
/*   Updated: 2024/05/01 09:08:09 by nzachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>
#include <limits.h>

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

void	putstruct(t_node *node, int *tmp)
{
	printf("node's val is: %d\n", node->val);

	int i;
	i = -1;
	while(tmp && *(tmp + 1))
	{
		++i;
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

void	make_new_list(t_stacklist *lst, char **str)
{
	t_node 	*new_node;
	int		i;

	lst->head = (t_node **)malloc(sizeof(t_node *));
	*(lst->head) = (t_node *){0};
	i = 0;
	while (i < lst->len)
	{
		new_node = p_newnode(str[i + 1]);
		add_node_to_back(lst->head, new_node);
		i++;
	}
	lst->tail = (t_node **)malloc(sizeof(t_node *));
	*(lst->tail) = new_node;
	// printf("in make new list tail val is: %d\n", (*(lst->tail))->val );
	// printf("in make new list head val is: %d\n", (*(lst->head))->val );
}

void	free_list(t_stacklist *lst)
{
	t_node	*this_node;
	t_node	*next;

	this_node = *lst->head;
	while (this_node)
	{
		printf("in free_list\n");
		next = this_node->nx;
		free(this_node);
		this_node = next;
	}
	free(lst->head);
	free(lst->tail);
}

int find_total_desired_rank(t_stacklist *s, char *av[])
{
	int *tmp_arr;
	// tmp_arr = NULL;
	tmp_arr = malloc(sizeof(int) * (s->len));
	//write from av to array
	int c = -1;
	while (++c < s->len)
		tmp_arr[c] = ft_atoi(av[c + 1]);

	//sort the array
	c = -1;
	int max;
	int tmp;
	while(++c < (s->len - 1))
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
	printf("before iter\n");
	//iter thru list, then iter thru array to find the idx to update the tdr
	iter_stacklist(s, tmp_arr, putstruct);
	free(tmp_arr);
	printf("after iter\n");
	return 1;
}

void	solve_for_two(t_stacklist *a)
{
	if ((*a->head)->tcr != (*a->head)->tdr)
	{
		write(1, "sa\n", 3);
		(*a->head)->tcr = 0;
		(*a->tail)->tcr = 1;
	}
	return;
}

void	add_node_to_front(t_node **head, t_node *new_first_node)
{
	if (new_first_node)
	{
		new_first_node->nx = *head;
		*head = new_first_node;
	}
}

void	rem_node_from_front(t_node **head)
{
	*head = (*head)->nx;
}

void	update_len(t_stacklist *lst)
{
	t_node	*this_node;
	int		len;

	this_node = *lst->head;
	len = 0;
	while(this_node)
	{
		len++;
		this_node = this_node->nx;
	}
	lst->len = len;
}

void	push_to(t_stacklist b, t_stacklist a)
{


	add_node_to_front(b.head, *a.head);
	printf("in push to\n");
	rem_node_from_front(a.head);

	update_len(&a);
	update_len(&b);
	write(1, "pb\n", 3);
}

void	solve(t_systm s)
{
	if (s.a.len < 2)
		return ;
	else if (s.a.len == 2)
		solve_for_two(&(s.a));

	else if (s.a.len > 2)
	{
		printf("in solve 204\n");
		push_to(s.b, s.a);
		solve(s);
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

int	main(int ac, char *av[])
{
	t_systm		system;
	t_stacklist	*a;
	t_stacklist	*b;

	a = malloc(sizeof(t_stacklist) * 1);
	b = malloc(sizeof(t_stacklist) * 1);
	// t_stacklist cmp;
	// int			i;
	// t_node *new;
	// a = (t_stacklist){0};
	a->len = ac -1;
	make_new_list(a, av);

	find_total_desired_rank(a, av);
	print_list(a);

	system.a = *a;
	system.b = *b;
	solve(system); //prints &a
	// solve(a);
	free_list(a);
	free(a);
	free(b);
	return (0);
}
