/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:33:32 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/20 19:02:16 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	int		fd;
	char	*result;

	atexit(ft_leaks);
	fd = open("lorem_ipsum.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("%s\n", result);
	free(result);
	result = get_next_line(fd);
	printf("%s\n", result);
	free(result);
	result = get_next_line(fd);
	printf("%s\n", result);
	free(result);
	close(fd);
	return (0);
}
