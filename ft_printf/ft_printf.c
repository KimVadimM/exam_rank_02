#include "unistd.h"
#include "stdarg.h"
#include "stdio.h"


int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
} 

int ft_len_calc(long int nbr, int base)
{
	int i;
	
	i = 0;
	while (nbr >= base)
	{
		nbr = nbr/base;
		i++;
	} 
	i++;
	return (i);
}

int ft_putspaceandzero(int len, int width, int  precision, int is_negative)
{
	int i;
	int num;

	i = 0;
	num = 0;
 
	precision = len > precision ? len : precision;
	width = width > precision ? width : precision;
	while (i < (width - precision))
	{
		write(1, " ", 1);
		i++;
		num++;
	}
	if (is_negative > 0)
	{
		write(1, "-", 1);
		num++;
	}
	i = 0;
	while(i < (precision - len))
	{
		write(1, "0", 1);
  		i++;
		num++;
	}
	return (num);
}

void ft_putnbr_base(long int nbr, int base)
{
	int rem;
	char c;

	if (nbr < 0)
		nbr *= -1;
	if (nbr > base)
		ft_putnbr_base(nbr/base, base);
	rem = nbr % base;
	c = rem < 10 ? rem + '0' : rem + 'W';
	write(1, &c, 1);	
}

int ft_outxxx(int width, int precision, va_list args)
{
	unsigned long int arg;
	int ret;
	int len;
	int i;

	i = 0;
	ret = 0;
	arg = va_arg(args, unsigned long int);
	len = ft_len_calc(arg, 16);
	precision = precision > len ? (precision - len) : 0;
	width = width > precision + len ? width - (precision + len) : 0;
	while (i < width)
	{
		write(1, " ", 1);
		i++;
		ret++;
	}
	i = 0;
	while (i < precision)
	{
		write(1, "0", 1);
		i++;
		ret++;
	}
	ft_putnbr_base(arg, 16);
	ret += len;
	return (ret);
}





int ft_outstr(int width, int precision, va_list args)
{
	char *str;
	int len;
	int i;
	int ret;
	
	i = 0;	
	ret = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	len = (precision >= 0 && precision < len) ? precision : len;
	width = width > len ? (width - len) : 0;
   	while (width > i)
	{
		write(1, " ", 1);
		i++;
		ret++;
	}
	i = 0;
	while (len > i)
	{
		write(1, &str[i], 1);
		i++;
		ret++;
	}
	return (ret);
}


int ft_intoutput(int width, int precision, va_list args)
{
	int len;
	long int arg;
	int is_negative;
	int is_null;
	int ret;

	ret = 0;
	is_negative = 0;
	is_null = 0;
	arg = (long int)va_arg(args, int);
	if (precision == 0 && arg == 0)
		is_null = -1;
	if (arg < 0) //if num negative
	{
		is_negative = 1;
		arg *= -1;
		width += -1;
	}
	len = is_null == -1 ? 0 : ft_len_calc(arg, 10); // в зависимости от нулл делаем расчет
	ret += ft_putspaceandzero(len, width, precision, is_negative);
	if (is_null != -1)
		ft_putnbr_base(arg, 10);
	ret += len;
	return (ret);		
}



	

int ft_core (const char *str, va_list args)  
{
	int i;
	int ret;
	int width;
	int precision;

	i = 0;
	ret = 0;
	width = 0;
	precision = -1;
	while (str[i] != 0)
	{
		if (str[i] != '%' && str[i])
			ret += write(1, &str[i], 1);
		if (str[i] == '%')
		{
			width = 0;
			precision = -1;
			i++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				width = width * 10 + (str[i] - 48);
				i++;
			}
			if (str[i] == '.')
			{
				i++;
				precision = 0;
				while (str[i] >= '0' && str[i] <= '9')
				{
					precision = precision * 10 + (str[i] - 48);
					i++;
				}
			}
			if (str[i] == 's')
				ret += ft_outstr(width, precision, args);
			else if (str[i] == 'd')
				ret += ft_intoutput(width, precision, args);
			else if (str[i] == 'x')
				ret += ft_outxxx(width, precision, args);
									
		}
	i++;
	}
	return (ret);						 
}	






int ft_printf(const char *str, ...)
{
	va_list args;
	int sym;
	
	va_start(args, str);
	sym = ft_core(str, args);
	va_end(args);
	return (sym); 
}

int main ()
{
	int min = 0;
	int num;
	int num1;
	num = ft_printf("%d", -2147483647);
	printf("\n%d\n", num);
	num1 = printf("%d", -2147483647);
	printf("\n%d\n", num1);
}
/*

//String specifiers, other tests
int s_two_strings_lj_and_rj(void){return test("%-7s%5s", "hello", "world");}
int s_two_strings_rj_and_lj(void){return test("%7s%-5s", "hello", "world");}
//String specifiers - NULL strings
int s_null_basic_string_expansion(void){return test("hello, %s.", NULL);}
int s_null_only_string_expansion(void){return test("%s", NULL);}
int s_null_space_padded_field_width(void){return test("%32s", NULL);}
int s_null_space_padded_over_field_width(void){return test("%2s", NULL);}
int s_null_space_padded_field_width_lj(void){return test("%-32s", NULL);}
int s_null_space_padded_field_width2_lj(void){return test("%-16s", NULL);}
int s_null_space_padded_over_field_width_lj(void){return test("%-3s", NULL);}

*/












