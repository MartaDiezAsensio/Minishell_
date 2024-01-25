/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:47:51 by mgaspar-          #+#    #+#             */
/*   Updated: 2024/01/25 18:52:36 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	read_and_append(int fd, char **stock)
{
	int			read_len;
	char		buf[BUFFER_SIZE + 1];

	read_len = 1;
	while (!(newline_check(*stock, read_len)))
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len == -1)
			return (-1);
		buf[read_len] = '\0';
		if (read_len == 0 || buf[read_len - 1] != '\n')
			printf("  \b\b");
		*stock = buf_join(*stock, buf);
		if (*stock == NULL)
			return (-1);
	}
	return (read_len);
}
