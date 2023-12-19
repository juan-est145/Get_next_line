/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:45:35 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/19 16:43:20 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen_line(const char *s);

char	*ft_strchr_line(const char *s, int c)
{
	size_t	i;
	char	*ptr_c;
	size_t	length;

	i = 0;
	length = 0;
	ptr_c = NULL;
	while (s[length] != '\0')
	{
		length++;
	}
	while (i <= length)
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

t_strings	*ft_new_node(char *text)
{
	t_strings	*new_node;

	new_node = (t_strings *)malloc(sizeof(t_strings));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->text = text;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back_list(t_strings **lst, t_strings *new)
{
	t_strings	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	size_t			src_length;
	size_t			dest_length;

	src_length = ft_strlen_line(src);
	dest_length = ft_strlen_line(dst);
	i = 0;
	j = dest_length;
	if (dstsize == 0 || dstsize <= dest_length)
	{
		return (dstsize + src_length);
	}
	while (src[i] != '\0' && i < dstsize - dest_length - 1)
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
