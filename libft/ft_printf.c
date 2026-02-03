/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:21:22 by yucchen           #+#    #+#             */
/*   Updated: 2025/07/10 19:07:08 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(unsigned char c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr(const char *s)
{
	int	cnt;

	if (!s)
		return (write(1, "(null)", 6));
	cnt = 0;
	while (s[cnt])
	{
		ft_putchar((unsigned char)s[cnt]);
		cnt++;
	}
	return (cnt);
}

static int	ft_handle_format(char c, va_list args)
{
	void	*p;

	if (c == 'c')
		return (ft_putchar((unsigned char)va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, const char *)));
	else if (c == 'p')
	{
		p = va_arg(args, void *);
		if (!p)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_putptr((uintptr_t)p));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunsignednbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthexalower(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_puthexaupper(va_arg(args, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
	return (write(1, "%", 1) + write(1, &c, 1));
}

/**
 *  @brief	Formatted output conversion
 *	@param	format const char *
 *	@return The number of characters printed 
 			(excluding the null byte used to end output to strings)
	@note	'...' is C syntax for a variadic function
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_handle_format(format[i + 1], args);
			i += 2;
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}

/* #include <stdio.h>

int main(void)
{
	int i;
	int	j;
	
	// %c
	i = printf("%c\n", 'A');
	j = ft_printf("%c\n", 'A');
	printf("i = %d vs j = %d\n", i, j);

	// %s
	i = printf("Hello %s\n", "World");
	j = ft_printf("Hello %s\n", "World");
	printf("i = %d vs j = %d\n", i, j);
	i = printf("Test: %s\n", "");
	j = ft_printf("Test: %s\n", "");
	printf("i = %d vs j = %d\n", i, j);

	//i = printf("NULL test: %s\n", NULL);
	//printf("i = %d\n", i);
	j = ft_printf("NULL test: %s\n", NULL);
	printf("j = %d\n", j);

	// %p
	int	test;
	test = 123;
	i = printf("Address: %p\n", &test);
	j = ft_printf("Address: %p\n", &test);
	printf("i = %d vs j = %d\n", i, j);

	i = printf("Address: %p\n", NULL);
	j = ft_printf("Address: %p\n", NULL);
	printf("i = %d vs j = %d\n", i, j);

	// %d
	i = printf("INT_MAX: %d\n", 2147483647);
	j = ft_printf("INT_MAX: %d\n", 2147483647);
	printf("i = %d vs j = %d\n", i, j);
	i = printf("Zero: %d\n", 0);
	j = ft_printf("Zero: %d\n", 0);
	printf("i = %d vs j = %d\n", i, j);
	i = printf("Forty two(d): %d\n", 42);
	j = ft_printf("Forty two(d): %d\n", 42);
	printf("i = %d vs j = %d\n", i, j);

	// %i
	i = printf("Forty two(i): %i\n", 42);
	j = ft_printf("Forty two(i): %i\n", 42);
	printf("i = %d vs j = %d\n", i, j);

	// %u
	i = printf("Unsigned -1: %u\n", -1);
	j = ft_printf("Unsigned -1: %u\n", -1);
	printf("i = %d vs j = %d\n", i, j);
	i = printf("Unsigned 0: %u\n", 0);
	j = ft_printf("Unsigned 0: %u\n", 0);
	printf("i = %d vs j = %d\n", i, j);

	// %x
	i = printf("lower hexa 255: %x\n", 255);
	j = ft_printf("lower hexa 255: %x\n", 255);
	printf("i = %d vs j = %d\n", i, j);

	// %X
	i = printf("upper hexa 255: %X\n", 255);
	j = ft_printf("upper hexa 255: %X\n", 255);
	printf("i = %d vs j = %d\n", i, j);
	i = printf("zero hexa(lower upper): %x %X\n", 0, 0);
	j = ft_printf("zero hexa(lower upper): %x %X\n", 0, 0);
	printf("i = %d vs j = %d\n", i, j);

	// %%
	i = printf("Percent only: %%\n");
	j = ft_printf("Percent only: %%\n");
	printf("i = %d vs j = %d\n", i, j);

	// mix
	i = printf("Mix: %c %s %% %c\n", 'X', "OK", 'Y');
	j = ft_printf("Mix: %c %s %% %c\n", 'X', "OK", 'Y');
	printf("i = %d vs j = %d\n", i, j);

	// % invalid
	// i = printf("%8\n", 42);
	// printf("i = %d\n", i);
	j = ft_printf("%8\n", 42);
	printf("j = %d\n", j);

	// i = printf("%b\n", 42);
	// printf("i = %d\n", i);
	j = ft_printf("%b\n", 42);
	printf("j = %d\n", j);
	return (0);
} */
