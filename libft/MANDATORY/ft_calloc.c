/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:36:14 by salabbe           #+#    #+#             */
/*   Updated: 2025/02/27 11:47:08 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*tab;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tab = (unsigned char *) malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, nmemb * size);
	return (tab);
}
