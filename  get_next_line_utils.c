/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:45:35 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/20 15:21:23 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t		ft_strlen_line(const char *s);

char	*ft_strchr_line(const char *s, int c)
{
	size_t	i;
	char	*ptr_c;

	i = 0;
	ptr_c = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			ptr_c = (char *)&s[i];
			return (ptr_c);
		}
		i++;
	}
	return (ptr_c);
}

static t_strings	*ft_new_node(char *text)
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
	ft_strlcat(new_node->text, text);
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back_list(t_strings **lst, char *text)
{
	t_strings	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = ft_new_node(text);
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = ft_new_node(text);
}

size_t	ft_strlcat(char *dst, const char *src)
{
	unsigned int	i;
	unsigned int	j;
	size_t			src_length;
	size_t			dest_length;

	src_length = ft_strlen_line(src);
	dest_length = ft_strlen_line(dst);
	i = 0;
	j = dest_length;
	while (src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (src_length + dest_length);
}

static size_t	ft_strlen_line(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
