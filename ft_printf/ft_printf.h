/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:28:36 by jtambra           #+#    #+#             */
/*   Updated: 2021/02/14 01:21:32 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_spec
{
	int			zero;
	int			width;
	int			dot;
	int			minus;
	char		type;
	int			sign_num;
}				t_spec;

int				ft_putchar(char c);
int				ft_strlen(const char *s);
void			ft_specifier(t_spec *value);
int				ft_mini_atoi(const char *format, int *i);
int				ft_c_parse(t_spec value, va_list arg);
int				ft_put_str(int len, char *str);
void			ft_change_value(t_spec value, int *len, int *spaces);
int				ft_s_parse(t_spec value, va_list arg);
size_t			ft_len_base(long long n, int base);
size_t			ft_len_ptr(unsigned long long n, int base);
char			*ft_itoa_base(long long nb, int base);
int				ft_toupper(int c);
int				ft_put_n(char *str, int i);
void			ft_before_num(t_spec *value, char *str, int *count, int len);
void			ft_put_num(t_spec *value, char *str, int *count, int len);
int				ft_no_dot(t_spec value, char *str, int count);
void			ft_put_speces(t_spec value, int *count);
int				ft_dot_exist(t_spec value, char *str, int count, int i);
int				ft_di_parse(t_spec value, va_list arg, int base);
int				ft_u_parse(t_spec value, va_list arg, int base);
char			*ft_itoa_pointer(unsigned long long nb, int base);
int				ft_p_parse(t_spec value, va_list arg, int base);
int				ft_per_parse(t_spec value);
void			ft_x_upper(char *str, t_spec value);
int				ft_x_parse(t_spec value, va_list arg, int base);
int				ft_type_parse(const char *format, int *i, va_list arg,
				t_spec value);
void			ft_parse_flags(const char *format, int *i, t_spec *value);
void			ft_parse_dot(const char *format, int *i, t_spec *value,
				va_list arg);
void			ft_parse_star(t_spec *value, va_list arg, int *i);
int				ft_parser(int *count, const char *format, int *i, va_list arg);

#endif
