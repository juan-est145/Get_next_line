/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:45:22 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/20 15:10:57 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10

typedef struct s_list_line
{
	char				*text;
	struct s_list_line	*next;
}						t_strings;
char					*get_next_line(int fd);
void					ft_lstadd_back_list(t_strings **lst, char *text);
char					*ft_strchr_line(const char *s, int c);
size_t					ft_strlcat(char *dst, const char *src);
#endif