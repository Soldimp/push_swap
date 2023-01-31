/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:45:09 by nuno              #+#    #+#             */
/*   Updated: 2023/01/31 14:20:16 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	onlynumbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && (av[i][j] != '-'))
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
			{
				return (FALSE);
			}
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
		{
			//exit(write(2, "Error\n", 6));
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	checker_sinal(int argc, char **argv)
{
	int	i;
	int	j;
	int	h;

	i = 1;
	j = 1;
	while (i < argc)
	{
		h = 0;
		if (argv[j][h] == '-')
		{
			h += 1;
			if (!(argv[j][h] >= '0' && argv[j][h] <= '9'))
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