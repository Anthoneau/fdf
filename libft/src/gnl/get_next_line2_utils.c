/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:54:08 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/11 17:14:05 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_bn(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_freestr(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*ptr;
	char	*tmp;
	char	*sub_s1;

	sub_s1 = s1;
	ptr = malloc(ft_strlen_bn(s1) + ft_strlen_bn(s2) + 1);
	if (!ptr)
		return (ft_freestr(s1));
	tmp = ptr;
	if (s1)
	{
		while (*s1 && *s1 != '\n')
			*tmp++ = *s1++;
	}
	while (*s2 && *s2 != '\n')
		*tmp++ = *s2++;
	*tmp = '\0';
	ft_freestr(sub_s1);
	return (ptr);
}

int	ft_findchar(char c, char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}





void	ft_buffer_modif(char *buffer)
{
	char	*b1;
	char	*b2;

	b1 = buffer;
	b2 = buffer;
	while (*b1 && *b1 != '\n')
		b1++;
	b1++;
	while (*b2)
		*b2++ = *b1++;
	*b2 = '\0';
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

static void	ft_bzero_mod(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
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
			return (ft_bzero_mod(buffer, BUFFER_SIZE + 1), free(str), NULL);
	}
	return (ft_strverif(str));
}