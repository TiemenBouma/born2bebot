/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unicode_tochars.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimonis <jsimonis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 18:14:12 by jsimonis      #+#    #+#                 */
/*   Updated: 2020/11/03 20:11:38 by jsimonis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	thease function map a unicode code point into the chars needed to display
**	each of them having a range in what they can decode
**		first  char = (char)(v>>0 )
**		second char = (char)(v>>8 )
**		third  char = (char)(v>>16)
**		fourth char = (char)(v>>24)
*/

unsigned int	ft_unicode_tochars_1(unsigned int u_point)
{
	return (u_point);
}

unsigned int	ft_unicode_tochars_2(unsigned int u_point)
{
	unsigned char	first;
	unsigned char	second;

	first = 0xC0 | (u_point >> 6);
	second = 0x80 | (u_point & 0x3F);
	return (first | (second << 8));
}

unsigned int	ft_unicode_tochars_3(unsigned int u_point)
{
	unsigned char	first;
	unsigned char	second;
	unsigned char	third;

	first = 0xE0 | (u_point >> 12);
	second = 0x80 | ((u_point >> 6) & 0x3F);
	third = 0x80 | (u_point & 0x3F);
	return (first | (second << 8) | (third << 16));
}

/*
**	Have not been able to test tochars_4
**	unicode should currenly at go to at least U+173782
**	but everything above u+55291 gives me 𘚠, maybe its just my pc, dunno
**	Did look at the bit values and confirmed that its working
*/

unsigned int	ft_unicode_tochars_4(unsigned int u_point)
{
	unsigned char	first;
	unsigned char	second;
	unsigned char	third;
	unsigned char	fourth;

	first = 0xF0 | (u_point >> 18);
	second = 0x80 | ((u_point >> 12) & 0x3F);
	third = 0x80 | ((u_point >> 6) & 0x3F);
	fourth = 0x80 | (u_point & 0x3F);
	return (first | (second << 8) | (third << 16) | (fourth << 24));
}

/*
**	ft_unicode_tochars_4 can handle up to 0x1FFFFF
**	but according to https://tools.ietf.org/html/rfc3629#section-3
**	it must be limited to 0x10FFFF
*/

unsigned int	ft_unicode_tochars(unsigned int u_point, int *len)
{
	if (u_point <= 0x7F)
	{
		*len = 1;
		return (ft_unicode_tochars_1(u_point));
	}
	else if (u_point < 0x7FF)
	{
		*len = 2;
		return (ft_unicode_tochars_2(u_point));
	}
	else if (u_point < 0xFFFF)
	{
		*len = 3;
		return (ft_unicode_tochars_3(u_point));
	}
	else if (u_point < 0x10FFFF)
	{
		*len = 4;
		return (ft_unicode_tochars_4(u_point));
	}
	return (-1);
}
