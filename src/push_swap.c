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


int	main(int ac, char *av[])
{
	t_stack	a;

	(void) av;
	a.len = ac -1;
	a.max = INT_MIN;

	int i;
	i = -1;

	while (++i < ac -1)
	{

	}

	printf("a.len is: %d\n", a.len );

}
