/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <ahuba@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:14:25 by ahuba             #+#    #+#             */
/*   Updated: 2018/10/31 15:14:27 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

static void		corr_connect(t_env *s, char **room_i)
{
	if (s->end == 0)
		error("ERROR! Empty end\n", KRED);
	if (s->start == 0)
		error("ERROR! Empty start\n", KRED);
	if (ft_strstr(room_i[0], "-") == 0)
		error("ERROR! Bad connection\n", KRED);
	if (connect(s, room_i[0]) == 0)
		error("ERROR! Bad connection\n", KRED);
}

int				connect(t_env *s, char *str)
{
	t_room		*curr;

	curr = s->room;
	if (!s->row)
		malloc_m(s);
	while (curr != NULL)
	{
		str = h_connect(str, curr, s);
		curr = curr->next;
		if (ft_strcmp(str, "-") == 0)
		{
			s->row[s->i2][s->i1] = '1';
			s->row[s->i1][s->i2] = '1';
			return (1);
		}
	}
	return (0);
}

static void		line(t_env *s, int i, char **room_i)
{
	if (i == 1)
		corr_connect(s, room_i);
	if (i == 3)
	{
		check_room_i(s, room_i, 0);
		s->special = 0;
	}
}

int				right_room(t_env *s, int i)
{
	char		**room_i;

	while (ft_get_next_line(0, &s->line) > 0)
	{
		i = 0;
		ft_printf("%s\n", s->line);
		if (s->line[0] == '#')
		{
			start_end(s);
			continue;
		}
		if (s->line[0] != '#' || s->line[0] != '\0')
		{
			(!room_spaces(s->line)) ? error("ERROR! SPACES\n", KRED) : 0;
			room_i = ft_strsplit(s->line, ' ');
			while (room_i[i])
				i++;
			(i != 1 && i != 3) ? error("ERROR! INCORRECT INPUT\n", KRED) : 0;
			line(s, i, room_i);
		}
	}
	return (1);
}

void			start_end(t_env *s)
{
	if (!ft_strcmp("##start", s->line))
	{
		s->start++;
		s->s_n = s->times;
		ft_memdel((void **)&s->line);
		if (s->special != 0)
			error("ERROR! ROOM CAN`T BE START/END\n", KRED);
		s->special = 1;
		s->start > 1 ? error("ERROR! DOUBLE START\n", KRED) : 0;
	}
	else if (!ft_strcmp("##end", s->line))
	{
		s->end++;
		s->e_n = s->times;
		ft_memdel((void **)&s->line);
		if (s->special != 0)
			error("ERROR! ROOM CAN`T BE START/END\n", KRED);
		s->special = 2;
		s->end > 1 ? error("ERROR! DOUBLE END\n", KRED) : 0;
	}
}
