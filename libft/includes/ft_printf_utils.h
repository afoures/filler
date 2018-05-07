/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:03:05 by afoures           #+#    #+#             */
/*   Updated: 2018/04/03 10:53:51 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# define BLUE "\x1b[0;34m"
# define CYAN "\x1b[0;36m"
# define BLACK "\x1b[0;30m"
# define GREEN "\x1b[0;32m"
# define NO_C "\x1b[0m"
# define ORANGE "\x1b[0;33m"
# define PURPLE "\x1b[0;35m"
# define RED "\x1b[0;31m"
# define WHITE "\x1b[1;37m"
# define YELLOW "\x1b[1;33m"

# define KEY "huite"

typedef enum	e_length
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z,
	L
}				t_length;

typedef struct	s_flags
{
	int			hashtag;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			apostrophe;
	int			precision;
	int			c_prec;
	int			width;
	int			c_width;
	t_length	modifier;
	int			rm_zero;
	int			len;
	int			b_len;
	int			e_len;
	int			ok;
	int			p;
	int			fd;
}				t_flags;

int				parser(unsigned char **fmt, va_list ap, int *ret, int fd);

void			pf_init_table(int (*fct[256])());
void			pf_init_flags(int (*fct[256])());
void			pf_init_specifier(int (*fct[256])());

void			pf_cpy_to_buf(unsigned char *buffer, int *index, void *to_put
				, int len);
int				pf_reset_buf_str(int error);
int				pf_init_buf(char *to_put);
int				pf_write_buf(int fd, int error);
int				pf_put_buf(int fd, void *to_put, int len, int error);
int				pf_put_wchar_t(wchar_t c, t_flags *f, int i);
int				pf_put_wstr(wchar_t *str, t_flags *f);
int				pf_put_error(char *error, int len);
int				pf_put_minus_one(int fd);
int				pf_puts_minus_one(void);
int				pf_put_hashtag(char *str, t_flags *f, char *base);
int				pf_put_width(char c, int len, t_flags *f);
int				pf_put_nprint(unsigned char *str, char *base, t_flags *f);
int				pf_put_nprint_c(unsigned char *str2, unsigned char *str
				, char *base);
int				pf_put_exponent(int e, char c, t_flags *f);
int				pf_put_a_exponent(int e, char c, t_flags *f);

size_t			pf_strlen(char *str);
size_t			pf_wchar_strlen(wchar_t *str, t_flags *f);
int				pf_int_toa(intmax_t nb, t_flags *f);
int				pf_uint_toa(uintmax_t nb, char *base, t_flags *f);
int				pf_float_toa(long double nb, t_flags *f);
int				pf_efloat_toa(long double nb, t_flags *f, int e, int i);
int				pf_afloat_toa(long double nb, t_flags *f, int e, int i);
int				pf_gf_float_toa(long double nb, t_flags *f);
int				pf_ge_float_toa(long double nb, t_flags *f, int e, int i);
long double		pf_float_conversion(va_list ap, t_flags *f);
void			pf_round_float(char *str, char *base, t_flags *f, int i);
int				pf_rm_zero(char *str, t_flags *f, char *first, int neg);
void			pf_float_integral(char *str, intmax_t nbr, int *tmp
				, t_flags *f);

int				pf_get_intlen(intmax_t nb, t_flags *f);
int				pf_get_floatlen(long double nb, t_flags *f);
int				pf_get_gfloatlen(long double nb, t_flags *f);
int				pf_get_efloatlen(long double nb, t_flags *f);
int				pf_get_afloatlen(long double nb, t_flags *f);
int				pf_get_uintlen(uintmax_t nb, t_flags *f);
int				pf_get_strlen(char *str, t_flags *f);
int				pf_get_wclen(wchar_t c, t_flags *f);
int				pf_get_wstrlen(wchar_t *str, t_flags *f);

int				pf_h_minus(va_list ap, t_flags *f);
int				pf_h_plus(va_list ap, t_flags *f);
int				pf_h_hashtag(va_list ap, t_flags *f);
int				pf_h_space(va_list ap, t_flags *f);
int				pf_h_zero(va_list ap, t_flags *f);
int				pf_h_apostrophe(va_list ap, t_flags *f);

int				pf_h_wildcard(va_list ap, t_flags *ft);
int				pf_h_width(va_list ap, t_flags *f, unsigned char **fmt);
int				pf_h_precision(va_list ap, t_flags *f, unsigned char **fmt);

int				pf_m_h(va_list ap, t_flags *f);
int				pf_m_l(va_list ap, t_flags *f);
int				pf_m_j(va_list ap, t_flags *f);
int				pf_m_z(va_list ap, t_flags *f);
int				pf_m_q(va_list ap, t_flags *f);
int				pf_m_ll(va_list ap, t_flags *f);

int				pf_no_behavior(va_list ap, t_flags *f, unsigned char **fmt);
int				pf_h_null(va_list ap, t_flags *f);
int				pf_h_d(va_list ap, t_flags *f);
int				pf_h_dd(va_list ap, t_flags *f);
int				pf_h_s(va_list ap, t_flags *f);
int				pf_h_ss(va_list ap, t_flags *f);
int				pf_h_percent(va_list ap, t_flags *f);
int				pf_h_c(va_list ap, t_flags *f);
int				pf_h_cc(va_list ap, t_flags *f);
int				pf_h_o(va_list ap, t_flags *f);
int				pf_h_oo(va_list ap, t_flags *f);
int				pf_h_x(va_list ap, t_flags *f);
int				pf_h_xx(va_list ap, t_flags *f);
int				pf_h_u(va_list ap, t_flags *f);
int				pf_h_uu(va_list ap, t_flags *f);
int				pf_h_b(va_list ap, t_flags *f);
int				pf_h_n(va_list ap, t_flags *f, unsigned char **fmt, int *ret);
int				pf_h_p(va_list ap, t_flags *f);
int				pf_h_r(va_list ap, t_flags *f);
int				pf_h_f(va_list ap, t_flags *f);
int				pf_h_fg(t_flags *f, long double nb);
int				pf_h_ff(va_list ap, t_flags *f);
int				pf_h_ffg(t_flags *f, long double nb);
int				pf_h_e(va_list ap, t_flags *f);
int				pf_h_eg(t_flags *f, long double nb);
int				pf_h_ee(va_list ap, t_flags *f);
int				pf_h_eeg(t_flags *f, long double nb);
int				pf_h_g(va_list ap, t_flags *f);
int				pf_h_gg(va_list ap, t_flags *f);
int				pf_h_a(va_list ap, t_flags *f);
int				pf_h_aa(va_list ap, t_flags *f);
int				pf_h_k(va_list ap, t_flags *f);
int				pf_h_m(va_list ap, t_flags *f);
int				pf_h_mm(va_list ap, t_flags *f);
int				pf_h_w(va_list ap, t_flags *f);
int				pf_h_ww(va_list ap, t_flags *f);

intmax_t		pf_arg_d_none(va_list ap);
intmax_t		pf_arg_d_hh(va_list ap);
intmax_t		pf_arg_d_h(va_list ap);
intmax_t		pf_arg_d_ll(va_list ap);
intmax_t		pf_arg_d_l(va_list ap);
intmax_t		pf_arg_d_j(va_list ap);
intmax_t		pf_arg_d_z(va_list ap);

uintmax_t		pf_arg_v_none(va_list ap);
uintmax_t		pf_arg_v_hh(va_list ap);
uintmax_t		pf_arg_v_h(va_list ap);
uintmax_t		pf_arg_v_ll(va_list ap);
uintmax_t		pf_arg_v_l(va_list ap);
uintmax_t		pf_arg_v_j(va_list ap);
uintmax_t		pf_arg_v_z(va_list ap);

intmax_t		*pf_arg_n_none(va_list ap);
intmax_t		*pf_arg_n_hh(va_list ap);
intmax_t		*pf_arg_n_h(va_list ap);
intmax_t		*pf_arg_n_ll(va_list ap);
intmax_t		*pf_arg_n_l(va_list ap);
intmax_t		*pf_arg_n_j(va_list ap);
intmax_t		*pf_arg_n_z(va_list ap);

void			pf_init_arg_v(uintmax_t (*pf_arg_v[8])(va_list));
void			pf_init_arg_d(intmax_t (*pf_arg_d[8])(va_list));
void			pf_init_arg_n(intmax_t *(*pf_arg_n[8])(va_list));

void			pf_init_color(char **c);
int				pf_color(unsigned char **fmt, int fd);

void			pf_decimal(char *str, long double nbr, int tmp, t_flags *f);
void			pf_adecimal(char *str, long double nbr, int tmp, t_flags *f);
int				pf_e_change(long double *nb, t_flags *f, int g);
int				pf_a_change(long double *nb, t_flags *f);
char			*pf_create_base(int i);
int				pf_h_f_nanorinf(long double nb, t_flags *f);
void			pf_h_f_putinf(long double nb, t_flags *f);
void			pf_h_f_putnan(long double nb, t_flags *f);
int				pf_h_f_infinite(long double nb, t_flags *f);
int				pf_h_f_nan(long double nb, t_flags *f);
int				pf_h_ff_nanorinf(long double nb, t_flags *f);
void			pf_h_ff_putinf(long double nb, t_flags *f);
void			pf_h_ff_putnan(long double nb, t_flags *f);
int				pf_h_ff_infinite(long double nb, t_flags *f);
int				pf_h_ff_nan(long double nb, t_flags *f);

#endif
