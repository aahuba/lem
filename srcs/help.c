/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <ahuba@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:14:35 by ahuba             #+#    #+#             */
/*   Updated: 2018/10/31 15:14:37 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int				malloc_m(t_env *s)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	s->row = (char**)malloc(sizeof(char*) * (s->times + 1));
	while (i < s->times)
	{
		j = 0;
		s->row[i] = (char*)malloc(sizeof(char) * (s->times + 1));
		while (j < s->times)
		{
			s->row[i][j] = '0';
			j++;
		}
		s->row[i][s->times] = '\0';
		i++;
	}
	s->row[i] = NULL;
	return (0);
}

int				step_ant_h(t_env *s, t_room *lst, int n_road)
{
	while (lst)
	{
		while (lst && lst->n_ant == -1)
			lst = lst->next;
		while (lst && lst->n_ant != -1)
			lst = lst->next;
		if (!lst)
			return (0);
		if (lst->n_ant == -1)
		{
			lst->n_ant = lst->prev->n_ant;
			while (lst != s->road[n_road]->this)
			{
				lst = lst->prev;
				lst->n_ant = lst->prev->n_ant;
			}
		}
		if (s->road[n_road]->this->n_ant == -1)
			return (0);
	}
	return (0);
}

char			*h_connect(char *str, t_room *curr, t_env *s)
{
	char		*prev;
	char		*this;
	char		*next;

	this = strchr(str, '-');
	prev = ft_strsub((str), (unsigned int)(this - (str) + 1),
ft_strlen(this) - 1);
	next = ft_strsub((str), 0, this - (str));
	if (ft_strcmp(curr->name, prev) == 0)
	{
		s->i2 = curr->i;
		str[this - str + 1] = '\0';
	}
	if (ft_strcmp(curr->name, next) == 0)
	{
		s->i1 = curr->i;
		str = this;
	}
	return (str);
}

int				room_spaces(char *line)
{
	int			i;
	int			j;

	i = -1;
	j = 0;
	if (!ft_strchr(line, '-'))
	{
		while (line[++i] != '\0')
			if (line[i] == ' ')
				j++;
		if (j == 2)
			return (1);
	}
	else
		return (1);
	return (0);
}
