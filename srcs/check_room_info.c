/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <ahuba@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:14:17 by ahuba             #+#    #+#             */
/*   Updated: 2018/10/31 15:14:19 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

static void		info(char *str, t_env *s)
{
	t_room		*value;

	value = s->room;
	while (value)
	{
		if (!ft_strcmp(value->name, str))
			error("ERROR! Check room name\n", KRED);
		value = value->next;
	}
}

int				check_room_i(t_env *s, char **room_i, int i)
{
	t_room		*curr;
	t_xy		*xy;

	xy = malloc(sizeof(xy));
	info(room_i[0], s);
	memory(room_i, s, xy);
	if (!ft_str_is_digit(&room_i[1][i]))
		error("ERROR! Room info(X)\n", KRED);
	i = 0;
	if (!ft_str_is_digit(&room_i[2][i]))
		error("ERROR! Room info(Y)\n", KRED);
	curr = s->room;
	while (curr->next != NULL)
	{
		if (curr->next == NULL && curr->x == xy->x && curr->y == xy->y)
			break ;
		if (curr->x == xy->x && curr->y == xy->y)
			error("ERROR! Overleap\n", KRED);
		curr = curr->next;
	}
	return (1);
}

static void		mem(char **room_i, t_env *s, t_room *room, t_xy *xy)
{
	room->y = ft_atoi(room_i[2]);
	room->i = s->times;
	room->x = ft_atoi(room_i[1]);
	if (room_i[0][0] == 'L' || ft_strchr(room_i[0], '-'))
		error("ERROR! Check room name\n", KRED);
	s->times++;
	room->name = ft_strdup(room_i[0]);
	room->n_ant = -1;
	xy->x = room->x;
	xy->y = room->y;
}

void			memory(char **room_i, t_env *s, t_xy *xy)
{
	t_room		*room;
	t_room		*curr;

	curr = s->room;
	room = malloc(sizeof(t_room));
	if (!room)
		error("ERROR! Invalid room\n", KRED);
	if (curr == NULL)
	{
		s->room = room;
		s->room->next = NULL;
	}
	else
	{
		while (curr && curr->next != NULL)
			curr = curr->next;
		curr->next = room;
		room->next = NULL;
	}
	mem(room_i, s, room, xy);
}
