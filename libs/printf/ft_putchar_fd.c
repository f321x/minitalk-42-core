/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:36:18 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/11/10 09:09:47 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf_fd(char c, int fd, t_pf_data *data)
{
	int	error;

	error = write(fd, &c, 1);
	if (error == -1)
		data->error = 1;
}
