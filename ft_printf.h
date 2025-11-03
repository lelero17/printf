/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:35:05 by lemmerli          #+#    #+#             */
/*   Updated: 2025/11/03 15:40:51 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *s, ...);
int	ft_conv(char conv, va_list ap);
int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_nbr(int nbr);
int	ft_print_unbr(unsigned int nbr);
int	ft_print_hex( unsigned int hex, char conv);
int	ft_print_vptr(void *ptr);

#endif