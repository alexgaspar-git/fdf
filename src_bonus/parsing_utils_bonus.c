/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:43:29 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:49:32 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	get_len(char **line)
{
	int	len;

	len = 0;
	while (line[len])
		len++;
	return (len);
}

int	has_hex(char *num)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (num[i])
	{
		if (num[i] == ',')
			v++;
		i++;
	}
	return (v);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1] != 0)
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (str[i] == '\n' && str[i + 1] == 0)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ishex(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))
		return (1);
	else
		return (0);
}

int	check_hex(char *hex)
{
	int	i;

	if (hex[0] != '0')
		return (0);
	if (hex[1] != 'x')
		return (0);
	i = 2;
	while (hex[i])
	{
		hex[i] = ft_toupper(hex[i]);
		if (ishex(hex[i]) == 0)
		{
			if (hex[i] == '\n' && hex[i + 1] == 0)
				return (1);
			else
				return (0);
		}
		if (i > 7)
			return (0);
		i++;
	}
	return (1);
}
