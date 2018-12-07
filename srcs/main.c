/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <ahuba@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:15:44 by ahuba             #+#    #+#             */
/*   Updated: 2018/10/31 15:15:47 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int					main(void)
{
	t_env			s;
	int				n_road;
	t_room			*croom;
	char		**crow;
	t_next		*cnext;

	n_road = 0;
	s.ant = -1;
	s.line = "\0";
	s.room = NULL;
	s.next = NULL;
	s.row = NULL;
	s.road = (t_road **)malloc(sizeof(t_road*) * 8);
	s.special = 0;
	numb_ant(&s, 1);
	if (!right_room(&s, 0))
		return (0);
	if (!s.room)
		error("ERROR! NEED MORE INFO\n", KRED);
	croom = s.room;
	cnext = s.next;
	crow = s.row;
	if (n_road == 0)
	{
		solve(&s, n_road, s.s_n);
		n_road++;
	}
	s.room = croom;
	s.next = cnext;
	s.row = crow;
	if (n_road == 1)
	{
		solve(&s, n_road, s.s_n);
		n_road++;
	}
	// if (n_road == 2)
	// {
	// 	solve(&s, n_road, s.s_n);
	// 	n_road++;
	// }
	// if (n_road == 3)
	// {
	// 	solve(&s, n_road, s.s_n);
	// 	n_road++;
	// }
	return (0);
}
