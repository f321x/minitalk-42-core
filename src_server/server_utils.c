/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:52:58 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/11/16 12:54:56 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern long long	g_buffer;

void	exit_function(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\nGoodbye!\n");
		exit(EXIT_SUCCESS);
	}
}

void	handle_one(int sig)
{
	size_t	index;

	if (sig == SIGUSR1)
	{
		index = received_bits(true) - 1;
		g_buffer |= 1LL << index;
	}
}

void	handle_zero(int sig)
{
	if (sig == SIGUSR2)
		received_bits(true);
}
