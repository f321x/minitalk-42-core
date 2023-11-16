/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:24:12 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/11/16 12:46:02 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long long	g_buffer = 0;

static void	store_character(char c, t_server *server)
{
	char	*buffer;

	if (c == '\0')
	{
		ft_printf("%s\n", server->received_string);
		free(server->received_string);
		server->str_length = 1000;
		server->received_string = ft_calloc(server->str_length, sizeof(char));
		return ;
	}
	else if (ft_strlen(server->received_string) + 2 > server->str_length)
	{
		buffer = server->received_string;
		server->str_length *= 2;
		server->received_string = ft_calloc(server->str_length, sizeof(char));
		if (!server->received_string)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		ft_strlcat(server->received_string, buffer, server->str_length);
		free(buffer);
	}
	server->received_string[ft_strlen(server->received_string)] = c;
}

static void	server_loop(t_server *server)
{
	while (1)
	{
		while (server->client_pid < 0 && received_bits(false)
			< (sizeof(pid_t) * 8))
			usleep(1);
		if (server->client_pid < 0)
			server->client_pid = extract_pid();
		server->prev_received_bits = 0;
		g_buffer = 0;
		kill(server->client_pid, SIGUSR1);
		while (received_bits(false) < 8)
		{
			if (received_bits(false) > server->prev_received_bits)
			{
				server->prev_received_bits++;
				if (received_bits(false) < 8)
					kill(server->client_pid, SIGUSR1);
			}
		}
		store_character(extract_char(server), server);
		g_buffer = 0;
		if (server->end_of_string)
			server->client_pid = -1;
	}
}

int	main(void)
{
	t_server	server;

	server.client_pid = -1;
	server.end_of_string = false;
	server.str_length = 1000;
	server.received_string = ft_calloc(server.str_length, sizeof(char));
	if (!server.received_string)
		return (1);
	ft_printf("Process ID: %d\n", getpid());
	signal(SIGUSR1, handle_one);
	signal(SIGUSR2, handle_zero);
	signal(SIGINT, exit_function);
	server_loop(&server);
}
