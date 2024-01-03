/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josilvei <josilvei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:44:07 by josilvei          #+#    #+#             */
/*   Updated: 2023/01/08 16:16:19 by josilvei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	if (dest == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while ((i < (size - 1)) && (src[i] != '\0'))
	{
		dest[i] = (unsigned char)src[i];
		i++;
	}
	if (size)
		dest[i] = '\0';
	if (ft_strlen(src) > i)
		i = ft_strlen(src);
	return (i);
}
