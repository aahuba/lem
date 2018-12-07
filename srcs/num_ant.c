/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <ahuba@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:14:56 by ahuba             #+#    #+#             */
/*   Updated: 2018/10/31 15:14:58 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int					numb_ant(t_env *s, int i)
{
	while (s->ant == -1 && i > 0)
	{
		i = ft_get_next_line(0, &s->line);
		ft_printf("%s\n", s->line);
		if ((s->line[0] == '#') && (ft_get_next_line(0, &s->line)))
			free(s->line);
		if (s->line && !(s->line[0] == '#' && !ft_strequ("#start", s->line)
				&& !ft_strequ("#end", s->line)))
		{
			if (ft_str_is_digit(s->line))
			{
				if (ft_atoi(s->line) > 0)
					s->ant = ft_atoi(s->line);
				else
					error("ERROR! INVALID NUMBER OF ANTS\n", KRED);
			}
			else
				error("ERROR! INVALID NUMBER OF ANTS\n", KRED);
		}
		else
			error("ERROR! INVALID NUMBER OF ANTS\n", KRED);
	}
	return (1);
}

int					ft_str_is_digit(char *str)
{
	int				i;

	i = -1;
	while (str[++i] != '\0')
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

void				error(char *line, char *color)
{
	ft_printf("%s%s", color, line);
	exit(1);
}

int					ft_strequ(const char *s1, const char *s2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		a = s1[i];
		b = s2[i];
		while (a == b)
		{
			i++;
			a = s1[i];
			b = s2[i];
			if (a == '\0' && b == '\0')
				return (1);
		}
	}
	return (0);
}
