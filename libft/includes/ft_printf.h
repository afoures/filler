/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:02:42 by afoures           #+#    #+#             */
/*   Updated: 2018/02/15 19:12:23 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <locale.h>
# include <stdint.h>
# include <wchar.h>
# include <langinfo.h>
# include <math.h>

# define BUFF_SIZE_PF 4096

int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list ap);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_vsprintf(char *str, const char *format, va_list ap);

#endif
