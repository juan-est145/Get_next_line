/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan_est145 <juan_est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:45:22 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/24 12:32:43 by juan_est145      ###   ########.fr       */
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
void					ft_clean_buffer(long i, long special_char_index,
							char *buffer);
#endif