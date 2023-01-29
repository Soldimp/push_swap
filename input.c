/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:45:09 by nuno              #+#    #+#             */
/*   Updated: 2023/01/28 15:51:54 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static	int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

static int	onlynumbers(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (FALSE);
	return (TRUE);
}

/*  If one of the strings starts with a '+' sign, it is ignored and the rest
 of the number string is checked.
 This is so that +123 == 123 but -123 != 123.
  Return: 0 if the strings match, another value if they do not. */
  
/* static int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
} */

/*static int	dup_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
} */

/* int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!onlynumbers(av[i]))
			return (FALSE);
		/* nb_zeros += arg_is_zero(av[i]);
		i++; 
	}
	/* if (nb_zeros > 1)
		return (0); 
	if (dup_check(av))
		return (FALSE);
	return (TRUE);
} */

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
				return FALSE;
			}
			j++;
		}
		i++;
	}
	return TRUE;
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
	if (onlynumbers(ac,av) != TRUE)
		return FALSE;
	else if (dupnub(ac, av) != TRUE)
		return FALSE;
	else if (checker_max_min(ac, av) != TRUE)
		return FALSE;
	else if (checker_sinal(ac, av) != TRUE)
		return FALSE;
	return TRUE;
}