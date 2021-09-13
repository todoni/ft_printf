void	function print padding by given length
{
	while (length--)
		write(1, "0", 1); 
}

void	function print space by given length
{
	while (length--)
		write(1, " ", 1); 
}

void	function print argument by given length
{
	write(1, string, length); 
}

void	function print 0x10
{
	write(1, "0x10", 4);
}

int	function print untyped character(const char *fmt, int ret)
{
	write(1, fmt, 1);
	ret++;
	return (ret);
}
