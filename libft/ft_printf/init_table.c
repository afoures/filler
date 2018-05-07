/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:33:52 by afoures           #+#    #+#             */
/*   Updated: 2018/03/05 10:11:36 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

void	pf_init_table(int (*fct[256])())
{
	int i;

	i = 1;
	fct['\0'] = pf_h_null;
	while (i < 256)
	{
		fct[i] = pf_no_behavior;
		i++;
	}
	pf_init_flags(fct);
	pf_init_specifier(fct);
}

void	pf_init_flags(int (*fct[256])())
{
	int i;

	i = 0;
	fct['-'] = pf_h_minus;
	fct['+'] = pf_h_plus;
	fct['#'] = pf_h_hashtag;
	fct['0'] = pf_h_zero;
	fct[' '] = pf_h_space;
	fct['\''] = pf_h_apostrophe;
	while (i < 9)
		fct['1' + i++] = pf_h_width;
	fct['*'] = pf_h_wildcard;
	fct['.'] = pf_h_precision;
	fct['h'] = pf_m_h;
	fct['l'] = pf_m_l;
	fct['j'] = pf_m_j;
	fct['z'] = pf_m_z;
	fct['q'] = pf_m_q;
	fct['L'] = pf_m_ll;
	fct['r'] = pf_h_r;
	fct['k'] = pf_h_k;
	fct['m'] = pf_h_m;
	fct['M'] = pf_h_mm;
	fct['w'] = pf_h_w;
	fct['W'] = pf_h_ww;
}

void	pf_init_specifier(int (*fct[256])())
{
	fct['s'] = pf_h_s;
	fct['S'] = pf_h_ss;
	fct['i'] = pf_h_d;
	fct['d'] = pf_h_d;
	fct['D'] = pf_h_dd;
	fct['c'] = pf_h_c;
	fct['C'] = pf_h_cc;
	fct['o'] = pf_h_o;
	fct['O'] = pf_h_oo;
	fct['u'] = pf_h_u;
	fct['U'] = pf_h_uu;
	fct['x'] = pf_h_x;
	fct['X'] = pf_h_xx;
	fct['n'] = pf_h_n;
	fct['p'] = pf_h_p;
	fct['b'] = pf_h_b;
	fct['f'] = pf_h_f;
	fct['f'] = pf_h_f;
	fct['F'] = pf_h_ff;
	fct['e'] = pf_h_e;
	fct['E'] = pf_h_ee;
	fct['g'] = pf_h_g;
	fct['G'] = pf_h_gg;
	fct['a'] = pf_h_a;
	fct['A'] = pf_h_aa;
}
