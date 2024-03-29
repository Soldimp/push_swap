/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:11:06 by nuno              #+#    #+#             */
/*   Updated: 2023/03/15 13:14:23 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  if (res > LLONG_MAX / 10 || (res == LLONG_MAX / 10 && nptr[i] - '0' > 
LLONG_MAX % 10))
            return (0); */
long long	ft_atoi2(const char *nptr)
{
	int			i;
	int			sig;
	long long	res;

	i = 0;
	sig = 1;
	res = 0;
	while ((nptr[i] == 32) || (nptr[i] == '\n') || (nptr[i] == '\t') || \
			(nptr[i] == '\v') || (nptr[i] == '\f') || (nptr[i] == '\r'))
			i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sig = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sig);
}
