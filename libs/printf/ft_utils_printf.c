/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:05:38 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/10/19 14:09:34 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_char(t_pf_data *data)
{
	int	position;

	position = 0;
	data->put_space = 0;
	data->pad_zero = 0;
	if (*(data->string_position) == '%')
	{
		data->string_position++;
		ft_parse_arg(data);
	}
	else
	{
		ft_putchar_fd(*(data->string_position), 1, data);
		data->letter_count++;
		data->string_position++;
	}
}

void	ft_parse_arg(t_pf_data *data)
{
	if (*(data->string_position) == 'c' || *(data->string_position) == '%')
		ft_print_char_argument(data);
	else if (*(data->string_position) == 's')
		ft_print_string_argument(data);
	else if (*(data->string_position) == 'p')
		ft_print_ptr(data);
	else if (*(data->string_position) == 'd'
		|| *(data->string_position) == 'i')
		ft_print_number_argument(data);
	else if (*(data->string_position) == 'u')
		ft_putunsigned(data);
	else if (*(data->string_position) == 'x')
		ft_to_hex(data, 0);
	else if (*(data->string_position) == 'X')
		ft_to_hex(data, 1);
	else
		data->string_position++;
}

char	*ft_get_digit(const char *string_pos)
{
	char	*buffer;
	int		index;

	index = 0;
	string_pos++;
	buffer = ft_calloc(12, sizeof(char));
	if (!buffer)
		return (NULL);
	while (ft_isdigit(*string_pos))
	{
		buffer[index] = *string_pos;
		index++;
		string_pos++;
	}
	return (buffer);
}
