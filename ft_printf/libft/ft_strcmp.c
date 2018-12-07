/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:08:45 by ahuba             #+#    #+#             */
/*   Updated: 2018/06/26 17:08:51 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*news1;
	unsigned char	*news2;

	news1 = (unsigned char*)s1;
	news2 = (unsigned char*)s2;
	while (*news1 == *news2 && *news1 != '\0' && *news2 != '\0')
	{
		news1++;
		news2++;
	}
	if (*news1 != *news2)
		return ((int)(*news1 - *news2));
	return (0);
}
