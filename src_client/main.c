/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:38:34 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/11/16 12:53:44 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	g_blocked = true;

static void	send_byte(pid_t pid, uint8_t character)
{
	uint8_t	index;

	index = 0;
	while (index < 8)
	{
		while (g_blocked)
			usleep(1);
		g_blocked = true;
		if (character & (1 << index))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		index++;
	}
}

static void	send_handshake(pid_t server_pid, pid_t client_pid)
{
	size_t	index;
	pid_t	one_bit_pid;

	index = 0;
	one_bit_pid = 1;
	while (index < sizeof(pid_t) * 8)
	{
		if (client_pid & (one_bit_pid << index))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		index++;
		usleep(50);
	}
}

static void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_blocked = false;
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	pid_t	client_pid;

	if (argc != 3)
		return (1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid == 0)
		return (1);
	signal(SIGUSR1, ack_handler);
	client_pid = getpid();
	send_handshake(server_pid, client_pid);
	while (*(argv[2]))
	{
		send_byte(server_pid, (uint8_t)(*argv[2]));
		argv[2]++;
	}
	send_byte(server_pid, '\0');
	return (0);
}
