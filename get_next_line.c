/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:44:16 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/20 15:05:52 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_parse_stash(t_strings **stash);

static void	clean_list(t_strings *stash);

char	*get_next_line(int fd)
{
	t_strings	*stash;
	t_strings	*node;
	static char	buffer[BUFFER_SIZE + 1];
	bool		found_char;
	int			bytes_read;
	char		*last_string;

	stash = NULL;
	last_string = NULL;
	found_char = false;
	while (found_char == false)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == BUFFER_SIZE)
			buffer[BUFFER_SIZE] = '\0';
		else if (bytes_read != BUFFER_SIZE)
		{
			buffer[bytes_read] = '\0';
			node = ft_new_node(buffer);
			ft_lstadd_back_list(&stash, node);
			break ;
		}
		if (ft_strchr_line(buffer, '\n') != NULL)
			found_char = true;
		node = ft_new_node(buffer);
		ft_lstadd_back_list(&stash, node);
	}
	last_string = ft_parse_stash(&stash);
	return (last_string);
}

// New function to parse the strings stored
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
		ft_strlcat(full_line, temp->text);
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

// In case that I also have to use malloc on the texts of the linked lists,
//	create the free functions. Test later.

// TO DO : If we detect a wanted char, we need to copy on the next node
// only up to the first wanted char, the rest stays in the buffer.

//TO DO: DO SOME CLEANUP TO HANDLE THE NORM. START WITH THE NODES.
