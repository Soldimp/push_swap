/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:24:21 by nugarcia          #+#    #+#             */
/*   Updated: 2023/02/07 11:38:16 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
		ft_putstr("-2147483648", len);
	else if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr *= -1;
		ft_putnbr(nbr, len);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
	else
		ft_putchar(nbr + 48, len);
}

void	ft_unsigputnbr(unsigned int nb, int *len)
{
	if (nb > 9)
	{
		ft_unsigputnbr(nb / 10, len);
		ft_unsigputnbr(nb % 10, len);
	}
	else
		ft_putchar(nb + 48, len);
}

void	ft_hexa(unsigned int nbr, char cs, int *len)
{
	char	*base;

	if (cs == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_hexa((nbr / 16), cs, len);
		ft_hexa((nbr % 16), cs, len);
	}
	else
		ft_putchar(base[nbr % 16], len);
}

static void	ft_puthex(unsigned long int nb, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(base[nb % 16], len);
	else
	{
		ft_puthex(nb / 16, len);
		ft_puthex(nb % 16, len);
	}
}

void	ft_print_memory(unsigned long ptr, int *len)
{
	unsigned long int	address;

	address = (unsigned long int)ptr;
	if (address == 0)
	{
		*len += write (1, "(nil)", 5);
		return ;
	}
	ft_putstr("0x", len);
	ft_puthex(address, len);
}
