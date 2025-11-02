/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:01:08 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/02 14:59:07 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int hex, char conv)
{
	int		count;
	int		i;
	char	temp[10];

	i = 0;
	count = 0;
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (hex > 0)
	{
		if (hex % 16 >= 10 && conv == 'x')
			temp[i++] = (char)('a' + ((hex % 16) - 10));
		else if (hex % 16 >= 10 && conv == 'X')
			temp[i++] = (char)('A' + ((hex % 16) - 10));
		else
			temp[i++] = (char)((hex % 16) + '0');
		count++;
		hex /= 16;
	}
	while (i > 0)
		write(1, &temp[--i], 1);
	return (count);
}
