/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:45:09 by nuno              #+#    #+#             */
/*   Updated: 2023/03/16 16:01:44 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int onlynumbers(int ac, char **av)
{
    int i;
    int j;

	i = 1;
    while (i < ac)
    {
        if (av[i][0] == '-') 
        {
            if (av[i][1] == '\0' || !ft_isdigit(av[i][1])) 
                return (FALSE);
            j = 2;
        }
        else
        {
            j = 0;
        }
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]))
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

int	dupnub(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi2(av[i]) == ft_atoi2(av[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	checker_max_min(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi2(av[i]) < INT_MIN || ft_atoi2(av[i]) > INT_MAX)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	checker_sinal(int ac, char **av)
{
	int	i;
	int	j;
	int	h;

	i = 1;
	j = 1;
	while (i < ac)
	{
		h = 0;
		if (av[j][h] == '-')
		{
			h += 1;
			if (!(av[j][h] >= '0' && av[j][h] <= '9'))
				return (FALSE);
		}
		j++;
		i++;
	}
	return (TRUE);
}

int	checkvalid_iput(int ac, char **av)
{
	if (onlynumbers(ac, av) != TRUE)
		return (FALSE);
	else if (dupnub(ac, av) != TRUE)
		return (FALSE);
	else if (checker_max_min(ac, av) != TRUE)
		return (FALSE);
	else if (checker_sinal(ac, av) != TRUE)
		return (FALSE);
	return (TRUE);
}
