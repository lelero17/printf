/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:50:49 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/03 17:19:18 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int nbr)
{
	int		count;
	int		i;
	char	temp[10];

	i = 0;
	count = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nbr > 0)
	{
		temp[i++] = (char)((nbr % 10) + '0');
		count++;
		nbr /= 10;
	}
	while (i > 0)
		write(1, &temp[--i], 1);
	return (count);
}

int	ft_print_nbr(int nbr)
{
	int		flag;

	flag = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		flag = 1;
	}
	return (ft_print_unbr((unsigned int)nbr) + flag);
}
