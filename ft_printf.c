/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:44:12 by lemmerli          #+#    #+#             */
/*   Updated: 2025/10/30 15:32:58 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_conv(char conv, va_list ap)
{
	int print;

	print = 0;
	if (conv == 'd' || conv == 'i')
		print += ft_print_digit(va_arg(ap, int));
	else if (conv == 'u')
		print += ft_print_udigit(va_arg(ap, unsigned int));
	else if (conv == 'x'  || conv == 'X')
		print += ft_print_hex(va_arg(ap, unsigned int), conv);
	else if (conv == 'c')
		print += ft_print_char(va_arg(ap, int));
	else if (conv == 's')
		print += ft_print_str(va_arg(ap, char *));
	else if (conv == 'p')
		print += ft_print_void(va_arg(ap, void *));
	else if (conv == '%')
		print += write(1, "%", 1);
	else
		print += write(1, &conv, 1);
	return (print);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int 	print;

	va_start(ap, s);
	i = 0;
	print = 0;
	while(s[i] != '\0')
	{
		if(s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			print += ft_print_conv(s[i], ap);
		}
		else if (s[i] != '%')
			print += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (print);
}
