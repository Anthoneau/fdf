/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:48:01 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/06 16:36:44 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_buffer_modif(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	j = 0;
	i += 1;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*ft_strverif(char *str)
{
	if (!str)
		return (NULL);
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	else
		return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	char static	buffer[BUFFER_SIZE + 1];
	int			rd;

	if ((fd < 0 || fd > OPEN_MAX) || BUFFER_SIZE < 0)
		return (NULL);
	rd = 1;
	str = NULL;
	while (rd > 0)
	{
		str = ft_strjoin_mod(str, buffer);
		if (!str)
			return (NULL);
		if (ft_findchar('\n', buffer))
		{
			ft_buffer_modif(buffer);
			break ;
		}
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd != -1)
			buffer[rd] = '\0';
		else
			return (ft_bzero(buffer, BUFFER_SIZE + 1), free(str), NULL);
	}
	return (ft_strverif(str));
}
