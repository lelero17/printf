/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_vptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:02:54 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/02 16:14:09 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_vptr(void *ptr)
{
	int				count;
	int				i;
	unsigned long	n;
	char			temp[16];

	i = 0;
	count = 0;
	n = (unsigned long) ptr;
	if (n == 0)
		return (write(1, "(nil)", 5));
	while (n > 0)
	{
		if (n % 16 >= 10)
			temp[i++] = (char)('a' + ((n % 16) - 10));
		else
			temp[i++] = (char)((n % 16) + '0');
		count++;
		n /= 16;
	}
	write(1, "0x", 2);
	while (i > 0)
		write(1, &temp[--i], 1);
	return (count + 2);
}
