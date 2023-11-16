/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:24:21 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/11/16 12:53:18 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_server {
	size_t	prev_received_bits;
	pid_t	client_pid;
	char	*received_string;
	bool	end_of_string;
	size_t	str_length;
}	t_server;

size_t	received_bits(bool	add);
void	exit_function(int sig);
void	handle_one(int sig);
void	handle_zero(int sig);
pid_t	extract_pid(void);
char	extract_char(t_server *server);

#endif
