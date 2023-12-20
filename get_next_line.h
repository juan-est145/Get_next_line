/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:45:22 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/20 19:43:52 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list_line
{
	char				*text;
	struct s_list_line	*next;
}						t_strings;
char					*get_next_line(int fd);
void					ft_lstadd_back_list(t_strings **lst, char *text,
							long special_char_index);
long					ft_strchr_line(const char *s, int c);
void					ft_strlcat(char *dst, const char *src,
							long special_char_index);
#endif