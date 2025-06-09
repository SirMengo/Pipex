/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:19:12 by msimoes           #+#    #+#             */
/*   Updated: 2025/06/09 14:25:41 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	mult;

	if (n == 0 || size == 0)
		return (malloc(0));
	mult = n * size;
	if (n > INT_MAX / size)
		return (NULL);
	ptr = malloc(mult);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, mult);
	return (ptr);
}
