char *convert(char *pt, int negative)
{
	while (!ft_converter(pt))
	{
		int fw;
		int precision;

		fw = 0;
		precision = 0;

		if (ft_isdigit(*pt))
			fw = atoi_next_pt(pt, &pt);
		if (*pt == '.')
		{
			if (ft_isdigit(*++pt))
				precision = abs(atoi_next_pt(pt, &pt));
			else if(*pt == '*')
				precision = abs(va_arg(args, int));
			else if (ft_isconverter(pt))
				break ;
			else
				return (NULL) // Chaine invalide
		}
		else if (*pt == '*')
		{

		}
		else
			return (NULL) // chaine invalide
	}
}
