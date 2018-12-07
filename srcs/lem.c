/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <ahuba@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:14:41 by ahuba             #+#    #+#             */
/*   Updated: 2018/10/31 15:14:43 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int				fill_room(t_env *s, t_room *lst, int i, int n_road)
{
	lst = s->road[n_road]->this;
	while (lst->next)
	{
		if (lst->n_ant == -1)
		{
			lst->n_ant = i++;
			return (i);
		}
		lst = lst->next;
	}
	if (lst->n_ant == -1)
	{
		lst->n_ant = i++;
		return (i);
	}
	return (-1);
}

int				print_ant(t_room *lst)
{
	while (lst)
	{
		if (lst->n_ant != -1)
		{
			if (lst->n_ant % 7 == 1)
				ft_printf("%s", KRED);
			else if (lst->n_ant % 7 == 2)
				ft_printf("%s", KGRN);
			else if (lst->n_ant % 7 == 3)
				ft_printf("%s", KYEL);
			else if (lst->n_ant % 7 == 4)
				ft_printf("%s", KBLU);
			else if (lst->n_ant % 7 == 5)
				ft_printf("%s", KMAG);
			else if (lst->n_ant % 7 == 6)
				ft_printf("%s", KCYN);
			else if (lst->n_ant % 7 == 0)
				ft_printf("%s", KWHT);
			ft_printf("L%i-%s ", lst->n_ant, lst->name);
		}
		lst = lst->next;
	}
	ft_printf("\n");
	return (0);
}

int			lem_help(t_env *s, int i, t_room *move, int n_road)
{
	while (i <= s->ant)
	{
		i = fill_room(s, move, i, n_road);
		move = s->road[n_road]->this;
		print_ant(move);
		move = s->road[n_road]->this;
		step_ant(s, move, n_road);
		move = s->road[n_road]->this;
	}
	while (move)
	{
		while (move && move->n_ant == -1)
			move = move->next;
		if (!move)
			// exit(1);
			return (1);
		print_ant(move);
		move = s->road[n_road]->this;
		step_ant(s, move, n_road);
		move = s->road[n_road]->this;
	}
	return (0);
}

int				lem(t_env *s, int n_road)
{
	t_room		*move;
	int			i;

	i = 1;

	move = NULL;
					// printf("TEST\n");
	if (s->road[n_road])
		move = s->road[n_road]->this;
	else
		error("ERROR! NO WAY\n", KRED);

	if (move->i != s->e_n)
	{
		while (move->next->i != s->e_n)
			move = move->next;
		move->next->prev = move;
	}
	ft_printf("\n");
	move = s->road[n_road]->this;
	if (lem_help(s, i, move, n_road) == 1)
		return (1);
	return (0);
	// exit(1);
}

int				step_ant(t_env *s, t_room *lst, int n_road)
{
	while (lst)
	{
		if (lst->i == s->e_n)
		{
			if (lst->n_ant != -1)
			{
				lst->n_ant = -1;
				lst = s->road[n_road]->this;
			}
			else
				lst = s->road[n_road]->this;
			break ;
		}
		lst = lst->next;
	}
	step_ant_h(s, lst, n_road);
	return (0);
}
