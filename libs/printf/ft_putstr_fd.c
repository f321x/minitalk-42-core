/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:27:16 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/11/10 09:10:05 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf_fd(char *s, int fd, t_pf_data *data)
{
	int	error;

	while (*s && !data->error)
	{
		error = write(fd, s, 1);
		if (error == -1)
		{
			data->error = 1;
			return ;
		}
		s++;
	}
}
