/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:48:01 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/11 18:22:04 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>
#include <stdio.h>

static char	*append_buffer(char *buffer, char *mini_buffer)
{
	char	*temp;

	if (!mini_buffer)
		return (NULL);
	temp = ft_strjoin(buffer, mini_buffer);
	if (!temp)
		return (buffer);
	free(buffer);
	buffer = NULL;
	return (temp);
}

static char	*read_file(int fd, char *big_buffer)
{
	char	*mini_buffer;
	int		bytes;

	if (!big_buffer)
		return (NULL);
	mini_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(mini_buffer))
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, mini_buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(mini_buffer), free(big_buffer), NULL);
		mini_buffer[bytes] = '\0';
		big_buffer = append_buffer(big_buffer, mini_buffer);
		if (ft_strchr(big_buffer, '\n'))
			break ;
	}
	free(mini_buffer);
	mini_buffer = NULL;
	return (big_buffer);
}

static char	*get_line(char *buffer)
{
	char	*temp;
	char	*res;
	int		i;

	if (!buffer)
		return (NULL);
	if (*buffer == '\0')
		return (ft_strdup(""));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i++;
	temp = malloc((i + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	res = temp;
	while (i--)
		*temp++ = *buffer++;
	*temp = '\0';
	return (res);
}

static char	*get_remaining(char *buffer)
{
	char	*temp;
	char	*res;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	res = temp;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		*temp++ = buffer[i++];
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	*temp = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*big_buffer[1024];
	char		*line;
	clock_t		start, end;
	double	diff;

	start = clock();
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!big_buffer[fd])
		big_buffer[fd] = ft_calloc(1, sizeof(char));
	if (!ft_strchr(big_buffer[fd], '\n'))
		big_buffer[fd] = read_file(fd, big_buffer[fd]);
	if (!big_buffer[fd])
		return (NULL);
	line = NULL;
	line = get_line(big_buffer[fd]);
	big_buffer[fd] = get_remaining(big_buffer[fd]);
	if (!(line) || line[0] == '\0')
		return (free(line), free(big_buffer[fd]), big_buffer[fd] = NULL, NULL);
	end = clock();
	diff = ((double)end - start) / CLOCKS_PER_SEC;
	printf("%.2fs ", diff);
	return (line);
}
