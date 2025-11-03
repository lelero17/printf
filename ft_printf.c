/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:44:12 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/03 17:53:40 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, s);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			count += ft_conv(s[i], ap);
		}
		else if (s[i] != '%')
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
