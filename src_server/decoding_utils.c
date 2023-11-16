/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoding_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:02:59 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/11/16 12:44:24 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern long long	g_buffer;

size_t	received_bits(bool	add)
{
	size_t	buffer_index;
	size_t	buffer_max_index;

	buffer_max_index = (sizeof(g_buffer) * 8 - 1);
	buffer_index = buffer_max_index;
	while ((g_buffer & (1LL << buffer_index)) && buffer_index > 31)
		buffer_index--;
	if (add)
	{
		g_buffer = g_buffer | (1LL << buffer_index);
		buffer_index--;
	}
	return (buffer_max_index - buffer_index);
}

pid_t	extract_pid(void)
{
	size_t	index;
	pid_t	client_pid;

	client_pid = 0;
	index = 0;
	while (index < (sizeof(pid_t) * 8))
	{
		client_pid |= ((g_buffer >> index) & 1) << index;
		index++;
	}
	return (client_pid);
}

char	extract_char(t_server *server)
{
	size_t	index;
	char	character;

	index = 0;
	character = 0;
	while (index < 8)
	{
		character |= ((g_buffer >> index) & 1) << index;
		index++;
	}
	if (character == '\0')
		server->client_pid = -1;
	return (character);
}
