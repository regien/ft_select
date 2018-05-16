/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:50:14 by regien            #+#    #+#             */
/*   Updated: 2018/05/14 01:14:13 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	display_usage(char *str)
{
	ft_putstr("USAGE = ");
	ft_putstr(str);
	ft_putstr(" arg1 arg2 arg3 ...\n");
	exit(-1);
}


void	general_error(int value)
{
	ft_putstr("Something unexpected happen\n");
	exit(value);
}


int		 setting_up(char **av, t_total *total)
{
	if (!(total = ft_memalloc(sizeof(t_total))))
		return (-1);
	if ()

	return (0);
}

int main(int ac, char **av)
{
	t_total		*total;

	total = NULL;
	if (ac < 2)
		display_usage(av[0]);
	else
	{
		if (setting_up(av, total) == -1)
			general_error(-1);
	}
	return (0);
}
