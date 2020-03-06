/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:21:59 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/27 14:11:12 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Define Font Color
*/

# define BLACK				"\033[0:30m"
# define BOLD_BLACK			"\033[1:30m"
# define RED 				"\033[0;31m"
# define BOLD_RED 			"\033[1;31m"
# define GREEN 				"\033[0;32m"
# define BOLD_GREEN 		"\033[1;32m"
# define YELLOW 			"\033[0;33m"
# define BOLD_YELLOW 		"\033[01;33m"
# define BLUE 				"\033[0;34m"
# define BOLD_BLUE 			"\033[1;34m"
# define MAGENTA 			"\033[0;35m"
# define BOLD_MAGENTA 		"\033[1;35m"
# define CYAN 				"\033[0;36m"
# define BOLD_CYAN 			"\033[1;36m"
# define WHITE				"\033[0:37m"
# define BOLD_WHITE			"\033[1:37m"
# define RESET 				"\033[0m"

/*
** Define Background Color
*/

# define BG_BLACK			"\033[0:40m"
# define BG_BOLD_BLACK		"\033[1:40m"
# define BG_RED 			"\033[0;41m"
# define BG_BOLD_RED 		"\033[1;41m"
# define BG_GREEN 			"\033[0;42m"
# define BG_BOLD_GREEN 		"\033[1;42m"
# define BG_YELLOW 			"\033[0;43m"
# define BG_BOLD_YELLOW 	"\033[1;43m"
# define BG_BLUE 			"\033[0;44m"
# define BG_BOLD_BLUE 		"\033[1;44m"
# define BG_MAGENTA 		"\033[0;45m"
# define BG_BOLD_MAGENTA 	"\033[1;45m"
# define BG_CYAN 			"\033[0;46m"
# define BG_BOLD_CYAN 		"\033[1;46m"
# define BG_WHITE			"\033[0:47m"
# define BG_BOLD_WHITE		"\033[1:47m"

/*
** Librarys needed for my ft_printf
*/

# include "../libft/includes/libft.h"
# include <float.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>

/*
** Defined Macros
*/

# define H					1
# define HH					2
# define L					3
# define LL					4
# define J					5
# define Z					6
# define CAPL				7
# define POSITIVE			8
# define NEGATIVE			9
# define FCONVERSION		"cspdiouxXf%"
# define FFLAGS				"#-+ .*0123456789hljz"
# define ASYMBOLS			"cspdiouxXf%#-+ .*0123456789hLljz"

typedef struct	s_struct
{
	int		i;
	int		len;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		precision;
	int		width;
	int		length;
	int		n_print;
	int		precision_dot;
	char	*format;
}				t_struct;

typedef struct	s_fstruct
{
	char		*s1;
	char		*s2;
	char		c;
	char		sign;
	int			sign_int;
	int			before_dec_nbr;
	int			hash;
	int			dot;
	int			zeros;
	int			precisionadd;
	int			padding;
	long double	i;
	long double	flt;
	int			precision;
}				t_fstruct;

char			find_char(t_struct *f);
void			error(void);
void			w_start(const char *format, t_struct *f, va_list ap);
void			modifie(const char *format, t_struct *f, va_list ap);
int				par1(const char *format, t_struct *list, va_list ap, int pos);
int				par2(t_struct *f, int position, const char *format, va_list ap);
int				unbr_len(uintmax_t n, int base);
int				snbr_len(intmax_t n, int base);
void			initialize(t_struct *list);
int				ft_printf(const char *format, ...);
void			length(const char *format, t_struct *f, int i);
void			precision(const char *format, t_struct *f, va_list ap, int p);
void			flags(const char *format, t_struct *f);
void			width(const char *format, t_struct *f, va_list ap);
void			write_zeros(int n);
void			write_blank(int n);
void			percent_case(t_struct *f);
void			display_char(t_struct *f, va_list ap);
void			convert(char c, va_list ap, t_struct *f);
void			re_initialize(t_struct *list);
void			aligned_left(t_struct *f, char c, char *s, int i);
void			aligned_right(t_struct *f, char c, char *s, int i);
void			display_str(t_struct *f, va_list ap);
void			display_uint(t_struct *f, va_list ap);
void			aligned_left_uint(t_struct *f, int len, char *s, int sign);
void			aligned_right_uint(t_struct *f, int len, char *s, int sign);
void			format_uint(uintmax_t n, t_struct *f, int sign);
void			display_pointer(t_struct *f, va_list ap, int hex);
void			display_hex(t_struct *f, va_list ap, char x);
void			display_octal(t_struct *f, va_list ap);
void			display_string(t_struct *f, va_list ap);
void			display_int(t_struct *f, va_list ap, int sign, intmax_t n);
void			aligned_right_flt(t_struct *f, t_fstruct g);
void			aligned_left_flt(t_struct *f, t_fstruct g);
void			display_float(t_struct *f, va_list ap);
char			*ft_toupper_str(char *str, int len);
char			*ft_itoa_base_upper(intmax_t value, intmax_t base);

#endif
