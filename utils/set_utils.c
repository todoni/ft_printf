void	function set flag
{
	while (*fmt is flag type)
		if (*fmt == '0')
			flag |= zero;
		else if (*fmt == '-')
			flag |= minus;
		else if (*fmt == '+')
			flag |= plus;
		else if (*fmt == ' ')
			flag |= space;
		else if (*fmt == '#')
			flag |= sharp;
		move address of fmt by 1;
}

void	function set width
{
	if (*fmt is number and not '0')
		width = atoi(fmt);
		move address of fmt by digit;
}

void	function set precision
{
	if (*fmt == '.')
		move address of fmt by 1;
		precision = atoi(fmt);
		move address of fmt by digit;
}

void	function set type
{
	if (*fmt == 'c')
		type |= character;
	else if (*fmt == 's')
		type |= string;
	else if (*fmt == 'p')
		type |= pointer;
	else if (*fmt == 'd')
		type |= integer;
	else if (*fmt == 'i')
		type |= integer;
	else if (*fmt == 'u')
		type |= u_integer;
	else if (*fmt == 'x')
		type |= hex_low;
	else if (*fmt == 'X')
		type |= hex_up;
	else if (*fmt == '%')
		type |= percent;
	
	move address of fmt by 1;
}


void	function set print length
{
	length of space = width - plus flag length(1) - space flag length(1) - sharp flag length(2) - precision flag length(width of precision);
	total width = width;
	length of padding = width of precision - length of value;

	if all lengths < 0
		lengths = 0;
}
