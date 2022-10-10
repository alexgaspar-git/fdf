/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:44:00 by algaspar          #+#    #+#             */
/*   Updated: 2022/06/16 22:54:08 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	if (str[i] != '\0' && str[i] == '-')
	{
			isneg = 1;
			i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (nbr < 0 && isneg == 1)
		return (0);
	else if (nbr < 0 && isneg == 0)
		return (-1);
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

char	*ft_strdup(char *src)
{	
	int		i;
	int		size;
	char	*dup;

	size = ft_strlen(src);
	dup = malloc(sizeof(char) * size + 1);
	if (dup == NULL)
		return ((char *) NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
