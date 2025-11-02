/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:44:12 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/02 14:02:00 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		print;

	va_start(ap, s);
	i = 0;
	print = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			print += ft_conv(s[i], ap);
		}
		else if (s[i] != '%')
			print += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (print);
}

// #include <limits.h>

// int main()
// {
// 	ft_printf("Test 1:\n%c, %%, %s, %d, %i, %u, %x, %X, %p\n"
// 		,'C', "Teststring", 42, -42, 4294967295u, 255, 255, &ft_printf);
// 	printf("%c, %%, %s, %d, %i, %u, %x, %X, %p\n\n"
// 		, 'C', "Teststring", 42, -42, 4294967295u, 255, 255, &ft_printf);
//	ft_printf("Test 2:\n")
// 	ft_printf("INT_MIN: %d | INT_MAX: %d | UINT_MAX: %u | 0: %d | -0: %i\n"
// 		, INT_MIN, INT_MAX, 4294967295u, 0, -0);
// 	printf("INT_MIN: %d | INT_MAX: %d | UINT_MAX: %u | 0: %d | -0: %i\n\n"
// 		, INT_MIN, INT_MAX, 4294967295u, 0, -0);
// 	ft_printf("Test 3:\nNULL str: %s | NULL ptr: %p | Hex 0: %x | Hex MAX: %X\n"
// 		, (char *)NULL, NULL, 0, 4294967295u);
// 	printf("NULL str: %s | NULL ptr: %p | Hex 0: %x | Hex MAX: %X\n\n"
// 		, (char *)NULL, NULL, 0, 4294967295u);
// 	return(0);
// }