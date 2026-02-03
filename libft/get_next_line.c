/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:17:13 by yucchen           #+#    #+#             */
/*   Updated: 2026/01/12 15:50:48 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_until_newline(char *storage, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*temp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(storage, buffer);
		free(storage);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
		storage = temp;
	}
	free(buffer);
	return (storage);
}

static char	*extract_line(char *newline, char *storage)
{
	if (newline)
		return (ft_substr(storage, 0, newline - storage + 1));
	return (ft_strdup(storage));
}

static char	*extract_storage(char *newline)
{
	if (newline)
		return (ft_strdup(newline + 1));
	return (NULL);
}

/**
 *  @brief	Write a function that returns a line read from a file descriptor
 *	@param fd The file descriptor to read from.
 *	@return (Read line: correct behavior);
			NULL: there is nothing else to read, or an error occurred
 */
char	*get_next_line(int fd, char **storage)
{
	char	*newline;
	char	*line;
	char	*temp;

	if (!storage || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!*storage)
	{
		*storage = ft_strdup("");
		if (!*storage)
			return (NULL);
	}
	*storage = read_until_newline(*storage, fd);
	if (!*storage || (*storage)[0] == '\0')
		return (free(*storage), *storage = NULL, NULL);
	newline = ft_strchr(*storage, '\n');
	line = extract_line(newline, *storage);
	temp = extract_storage(newline);
	if (!line || (newline && !temp))
		return (free(*storage), *storage = NULL, free(line), free(temp), NULL);
	free(*storage);
	*storage = temp;
	return (line);
}

void	gnl_clean(char **storage)
{
	if (!storage)
		return ;
	free(*storage);
	*storage = NULL;
}

/* #include <fcntl.h>   // open
#include <stdio.h> 		// printf, perror

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("test_normal.txt", O_RDONLY);
	//fd = open("test_empty.txt", O_RDONLY);
	//fd = open("test_nolastnewline.txt", O_RDONLY);
	//fd = open("test_longline.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open error");
		return (1);
	}
	while ((next_line = get_next_line(fd)))
	{
		count++;
		printf("%d: %s\n", count, next_line);
		free(next_line);
	}
	printf("[EOF reached]\n");
	count++;
	printf("%d: %s\n", count, next_line);
	free(next_line);
	close(fd);
	return (0);
} */
/* next_line = get_next_line(fd);
count++;
printf("%d: %s\n", count, next_line);
free(next_line); */
/* // test fd error
int	main(void)
{
	next_line = get_next_line(42);
	if (next_line == NULL)
		printf("Invalid fd handled correctly (returned NULL)\n");
	else
	{
		printf("Invalid fd returned non-NULL\n");
		free(next_line);
	}
} */
/* // test stdin
printf("=== Test stdin (type something then press Ctrl+D) ===\n");
while	((next_line = get_next_line(0)))
{
	printf("stdin line %d: %s", ++count, next_line);
	free(next_line);
}
printf("[EOF on stdin]\n\n"); */