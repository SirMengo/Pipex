/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:58:32 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/06 12:06:59 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bg, const char *ltl, size_t len)
{
	size_t	i;
	size_t	j;

	if (*ltl == '\0')
		return ((char *)(bg));
	i = 0;
	while (i < len && bg[i] != '\0')
	{
		j = 0;
		if (bg[i] == ltl[0])
		{
			while ((i + j < len) && ltl[j] != '\0' && bg[i + j] == ltl[j])
				j++;
			if (ltl[j] == '\0')
				return ((char *)(bg + i));
		}
		i++;
	}
	return (0);
}
