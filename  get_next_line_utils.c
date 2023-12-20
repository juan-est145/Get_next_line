/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:45:35 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/20 16:16:53 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_strings	*ft_new_node(char *text, long special_char_index);

long	ft_strchr_line(const char *s, int c)
{
	long	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static t_strings	*ft_new_node(char *text, long special_char_index)
{
	t_strings	*new_node;

	new_node = (t_strings *)malloc(sizeof(t_strings));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new_node->text == NULL)
	{
		free(new_node);
		return (NULL);
	}
	ft_strlcat(new_node->text, text, special_char_index);
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back_list(t_strings **lst, char *text,
		long special_char_index)
{
	t_strings	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = ft_new_node(text, special_char_index);
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = ft_new_node(text, special_char_index);
}

void	ft_strlcat(char *dst, const char *src, long special_char_index)
{
	unsigned int	i;
	size_t			dest_length;

	dest_length = 0;
	i = 0;
	while (dst[dest_length] != '\0')
	{
		dest_length++;
	}
	while (src[i] != '\0')
	{
		dst[dest_length] = src[i];
		if (special_char_index != -1 && (long)i == special_char_index)
		{
			dest_length++;
			break ;
		}
		i++;
		dest_length++;
	}
	dst[dest_length] = '\0';
}
