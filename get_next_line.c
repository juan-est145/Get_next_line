/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan_est145 <juan_est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:44:16 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/26 17:07:20 by juan_est145      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_parse_stash(t_strings **stash);
static void	clean_list(t_strings *stash);
static char	*find_next_line(t_strings **stash, int fd, char *buffer);
static void	ft_check_buffer(char *buffer, t_strings **stash);

char	*get_next_line(int fd)
{
	t_strings	*stash;
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	long		special_char_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = NULL;
	ft_check_buffer(buffer, &stash);
	line = find_next_line(&stash, fd, buffer);
	if (line == NULL && stash != NULL)
		clean_list(stash);
	if (line == NULL)
		return (NULL);
	special_char_index = ft_strchr_line(buffer, '\n');
	if (special_char_index != -1)
		ft_clean_buffer(special_char_index, buffer);
	return (line);
}

static char	*find_next_line(t_strings **stash, int fd, char *buffer)
{
	bool	found_char;
	int		bytes_read;
	long	special_char_index;

	found_char = false;
	while (found_char == false)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read != BUFFER_SIZE)
		{
			if (bytes_read == 0 && *stash == NULL)
				return (NULL);
			buffer[bytes_read] = '\0';
			special_char_index = ft_strchr_line(buffer, '\n');
			ft_lstadd_back_list(stash, buffer, special_char_index);
			if (special_char_index == -1)
				ft_clean_buffer(special_char_index, buffer);
			break ;
		}
		special_char_index = ft_strchr_line(buffer, '\n');
		if (special_char_index != -1)
			found_char = true;
		ft_lstadd_back_list(stash, buffer, special_char_index);
	}
	return (ft_parse_stash(stash));
}

static char	*ft_parse_stash(t_strings **stash)
{
	t_strings		*temp;
	char			*full_line;
	unsigned int	counter;

	full_line = NULL;
	temp = *stash;
	counter = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		counter++;
	}
	temp = *stash;
	full_line = (char *)malloc((sizeof(char) * (BUFFER_SIZE * counter)) + 1);
	full_line[0] = '\0';
	while (temp != NULL)
	{
		ft_strlcat(full_line, temp->text, -1);
		temp = temp->next;
	}
	clean_list(*stash);
	return (full_line);
}

static void	clean_list(t_strings *stash)
{
	t_strings	*temp;

	while (stash != NULL)
	{
		temp = stash;
		free(stash->text);
		stash = stash->next;
		free(temp);
	}
}

static void	ft_check_buffer(char *buffer, t_strings **stash)
{
	long	i;
	long	special_char_index;

	i = 0;
	while (i < BUFFER_SIZE && buffer[0] != '\0')
	{
		if (buffer[i] != '\0')
		{
			special_char_index = ft_strchr_line(buffer, '\n');
			ft_lstadd_back_list(stash, &buffer[i], special_char_index);
			break ;
		}
		i++;
	}
}
