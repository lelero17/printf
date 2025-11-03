/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:42:46 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/03 19:07:49 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv(char conv, va_list ap)
{
	int	count;

	count = 0;
	if (conv == 'd' || conv == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	else if (conv == 'u')
		count += ft_print_unbr(va_arg(ap, unsigned int));
	else if (conv == 'x' || conv == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), conv);
	else if (conv == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (conv == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (conv == 'p')
		count += ft_print_vptr(va_arg(ap, void *));
	else if (conv == '%')
		count += write(1, "%", 1);
	else
	{
		count += write(1, "%", 1);
		count += write(1, &conv, 1);
	}
	return (count);
}
