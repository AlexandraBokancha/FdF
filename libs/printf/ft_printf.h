/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:33:12 by albokanc          #+#    #+#             */
/*   Updated: 2024/01/06 15:34:11 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_find_adress(void *ptr);
int		ft_strnlen(char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_unsgnd(unsigned int nb);
int		ft_hex(unsigned int nbr, char c);
int		ft_putnbr_base(unsigned long long nbr, char *base);

#endif
