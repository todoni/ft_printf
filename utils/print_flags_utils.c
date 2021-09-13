void	function print 1 space
{
	write(1, " ", 1);
}

void	function print sign
{
	if value < 0
		write(1, "-", 1);
	else if value > 0
		write(1, "+", 1);
	else
		return ;
}

void	function print 0X
{
	write(1, "0X", 2);
}

void	function print 0x
{

	write(1, "0x", 2);
}
