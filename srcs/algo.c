/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <ahuba@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:14:07 by ahuba             #+#    #+#             */
/*   Updated: 2018/10/31 15:14:10 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int				right2(t_next *next, t_env *s, t_next *head, t_room *prev, int n_road)
{
	if ((next)->type)
		printf("*%d*\n", (next)->type->mean);
	if ((next)->type && (next)->type->mean != 3 && (next)->type->mean != 2)
	{
		(next)->type->mean = 2;
		(next)->type->prev = prev;
		// printf("|%d %d|\n", (*next)->type->prev->visited, (*next)->type->visited);
		// if ((*next)->type->prev->visited == 1 || (*next)->type->visited == 1)
		// 	return (1);
		if ((next)->type->i == s->e_n)
			print_this(s, (next), n_road);
		if (s->next == NULL)
			s->next = (next);
		else
		{
			head = s->next;
			while (head->next != NULL)
				head = head->next;
			head->next = (next);
		}
	}
	return (0);
}

static int			right(t_env *s, int i, int ind, t_room *prev, int n_road)
{
	t_next			*next;
	t_next			*head;
	t_room			*p;
	int				check;

	check = 0;
	head = NULL;

	if (s->row[ind][i] == '1' && s->row[i][ind] == '1')
	{
		next = malloc(sizeof(t_next));
		p = s->room;

		while (p != NULL)
		{
			if (p->i == i)
				break ;
			p = p->next;
		}
		next->type = p;
		next->next = NULL;
		if ((next->type) && (next->type->mean) != 3 && (next->type->mean) != 2)
			next->type->mean = 0;
		right2(next, s, head, prev, n_road);
		// if (check == 1)
		// 	return (1);
	}
	return (0);
}

void				print_this(t_env *s, t_next *next, int i)
{
	t_road			*road;
	t_room			*curr;

	road = malloc(sizeof(road));
	while (next->type && next->type->i != s->s_n)
	{
		next->type->visited = 1;
		next->type->prev->visited = 1;
		next->type->next = road->this;
		road->this = next->type;
		next->type = next->type->prev;
	}
	curr = road->this;
	while (curr->i != s->e_n)
		curr = curr->next;
	curr->next = NULL;
	s->road[i] = road;
}

t_room				*take_start(int i, t_room *p)
{
	while (p != NULL)
	{
		if (p->i == i)
			break ;
		p = p->next;
	}
	return (p);
}

int				solve(t_env *s, int n_road, int ind)
{
	t_room			*prev;
	int				i;
	int				check;

	check = 0;
	i = -1;
	printf("\n\n!!!%d!!!\n\n", n_road);
	prev = take_start(ind, s->room);
	while (ind != s->e_n)
	{
		(!s->row) ? error("ERROR! Need more connections\n", KRED) : 0;
		while (s->row[ind][++i] != '\0')
			if (s->row[ind][i] == '1' && s->row[i][ind] == '1')
				right(s, i, ind, prev, n_road);
		if (!s->next)
			if (lem(s, n_road) == 1)
				return (1);
		if (s->next)
		{
			prev = s->next->type;
			ind = s->next->type->i;
			s->next->type->mean = 3;
		}
		if (s->next->type->mean == 3)
			s->next = s->next->next;
		i = 0;
	}
	return (0);
}
