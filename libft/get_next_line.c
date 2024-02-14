/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:14:33 by bwach             #+#    #+#             */
/*   Updated: 2024/01/30 13:43:57 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//free memory and return a empty pointer
static char	*free_str(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

//check if there any \n in the string
static int	ft_len_next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

//split the string contained inside the static buffer: line + left-over
static char	*ft_append_line(char *left_char, char *buffer, int mem_alloc)
{
	char	*tmp;
	int		len;

	len = ft_len_next_line(left_char) + 1;
	tmp = ft_substr_gnl(left_char, 0, len);
	if (!tmp)
		return (NULL);
	ft_strlcpy_gnl(buffer, len + left_char, ft_strlen_gnl(left_char + len) + 1);
	if (mem_alloc)
		free_str(left_char);
	return (tmp);
}

//read the file and create new-line
static char	*ft_get_line(int fd, char *read_char, int *rd_checker)
{
	char	*next_line;

	next_line = ft_substr_gnl(read_char, 0, ft_strlen_gnl(read_char));
	if (!read_char)
		return (NULL);
	while (*rd_checker)
	{
		ft_memset_gnl(read_char, 0, BUFFER_SIZE + 1);
		*rd_checker = (int)read(fd, read_char, BUFFER_SIZE);
		if (*rd_checker == -1)
			return (free_str(next_line));
		next_line = ft_strjoin_gnl(next_line, read_char);
		if (*rd_checker < 1)
		{
			if (ft_strlen_gnl(next_line))
				return (next_line);
			return (free_str(next_line));
		}
		if (ft_len_next_line(next_line) > -1)
			return (ft_append_line(next_line, read_char, 1));
	}
	return (ft_append_line(next_line, read_char, 0));
}

char	*get_next_line(int fd)
{
	static char	left_char[BUFFER_SIZE + 1] = {0};
	int			rd_checker;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd_checker = 1;
	if (ft_len_next_line(left_char) > -1)
		return (ft_append_line(left_char, left_char, 0));
	return (ft_get_line(fd, left_char, &rd_checker));
}

/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line); 
	}
	close(fd);
	return 0;
}*/