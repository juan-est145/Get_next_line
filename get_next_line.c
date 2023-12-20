/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:44:16 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/20 16:17:53 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_parse_stash(t_strings **stash);
static void	clean_list(t_strings *stash);

char	*get_next_line(int fd)
{
	t_strings	*stash;
	static char	buffer[BUFFER_SIZE + 1];
	bool		found_char;
	int			bytes_read;
	long		special_char_index;

	stash = NULL;
	found_char = false;
	while (found_char == false)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == BUFFER_SIZE)
			buffer[BUFFER_SIZE] = '\0';
		else if (bytes_read != BUFFER_SIZE)
		{
			buffer[bytes_read] = '\0';
			ft_lstadd_back_list(&stash, buffer, special_char_index);
			break ;
		}
		special_char_index = ft_strchr_line(buffer, '\n');
		if (special_char_index != -1)
			found_char = true;
		ft_lstadd_back_list(&stash, buffer, special_char_index);
	}
	return (ft_parse_stash(&stash));
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

// TO DO : If we detect a wanted char, we need to copy on the next node
// only up to the first wanted char, the rest stays in the buffer.

// TO DO: DO SOME CLEANUP TO HANDLE THE NORM. START WITH THE NODES.

// If I need more functions in utils,
//	try to eliminate the need of the static strlen function.

//Change stchr_line so that it returns the position of the first \n.