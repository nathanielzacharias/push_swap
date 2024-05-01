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


void	solve(t_systm s)
{
	printf("s.a.len is: %d\n", s.a.len);
}

t_systm init(t_systm s, int ac, char *av[])
{
	(void) av;
	s.a.len = ac - 1;
	return (s);
}

int	main(int ac, char *av[])
{
	t_systm	system;

	system.is_done = -1;
	system = init(system, ac, av);
	solve(system);
	return (0);
}
