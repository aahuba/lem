/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 04:57:31 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/09 04:57:32 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/ftprintf/ft_printf.h"
# include <fcntl.h>

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				i;
	struct s_room	*next;
	struct s_room	*prev;
	int				mean;
	int				n_ant;
	int				visited;
}					t_room;

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef	struct		s_next
{
	t_room			*type;
	struct s_next	*next;
}					t_next;

typedef	struct		s_road
{
	t_room			*this;
	struct s_road	*next;
}					t_road;

typedef struct		s_env
{
	char			*line;
	int				ant;
	t_room			*room;
	t_next			*next;
	t_road			**road;
	int				start;
	int				end;
	char			**row;
	int				times;
	int				s_n;
	int				e_n;
	int				i1;
	int				i2;
	int				special;
}					t_env;

/*
**	check_room_info.c
*/
int					check_room_i(t_env *s, char **room_i, int i);
void				memory(char **room_i, t_env *s, t_xy *xy);

/*
**	right_room.c
*/
int					right_room(t_env *s, int i);
int					connect(t_env *s, char *str);
void				start_end(t_env *s);

/*
**	algo.c
*/
int					solve(t_env *s, int n_road, int ind);
void				print_this(t_env *s, t_next *next, int n_road);
int					right2(t_next *next, t_env *s, t_next *head, t_room *prev, int n_road);

/*
**	numb_ant.c
*/
int					numb_ant(t_env *s, int i);
int					ft_str_is_digit(char *str);
void				error(char *line, char *color);
int					ft_strequ(const char *s1, const char *s2);

/*
**	help.c
*/
int					malloc_m(t_env *s);
int					step_ant_h(t_env *s, t_room *lst, int n_road);
char				*h_connect(char *str, t_room *curr, t_env *s);
int					room_spaces(char *line);

/*
**	lem.c
*/
int					lem(t_env *s, int n_road);
int					step_ant(t_env *s, t_room *lst, int n_road);

#endif
