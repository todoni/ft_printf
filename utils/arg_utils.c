
void	function get argument value
{
	if (type & int_mask)
		_int = va_arg(arg_ptr, int);
	else if (type & string)
		str = va_arg(arg_ptr, char*);
	else if (type & pointer)
		_int = va_arg(arg_ptr, unsigned long long);
	else if (type & u_integer)
		_int = va_arg(arg_ptr, unsigned int);
	else if (type & percent)
		str = "%";
}

void	function make integer argument string
{
	char	*base;

	if (type & int_base_mask)
		base = "0123456789";
	else if (type & x_base_mask)
		base = "0123456789abcdef";
	else if (type & hex_up)
		base = "0123456789ABCDEF";
	
	if (!str)
		str = ft_itoa(_int, base);
}

