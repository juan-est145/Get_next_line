/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:44:16 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/19 16:49:19 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_strings	*stash;
	t_strings			*node;
	char				buffer[BUFFER_SIZE + 1];
	bool				found_char;
	int					bytes_read;

	// First draft to a system to create our stash of all strings read.
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
}

// New function to parse the strings stored
static char	*ft_parse_stash(t_strings **stash)
{
	t_strings		*temp;
	char			*full_line;
	unsigned int	words_written;

	words_written = BUFFER_SIZE;
	temp = *stash;
	while (temp != NULL)
	{
		ft_strlcat(full_line, temp->text, BUFFER_SIZE);
		words_written += BUFFER_SIZE;
	}
	return (full_line);
}

// In case that I also have to use malloc on the texts of the linked lists,
//	create the free functions. Test later.

//Also need to later clean the stash of all unwanted chars.

//This has not been compiled yet, probably there are multiple errors of compilation, test later.