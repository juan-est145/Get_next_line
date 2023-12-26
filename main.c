/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan_est145 <juan_est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:33:32 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/27 00:23:53 by juan_est145      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*void	ft_leaks(void)
{
	system("valgrind --leak-check=summary ./a.out");
}*/

//atexit(ft_leaks);
int	main(void)
{
	/*int		fd;
	char	*result;

	result = "a";
	fd = open("files/read_error.txt", O_RDONLY);
	while (result != NULL)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free(result);
	}
	close(fd);*/
	char *result;
	int fd = open("files/read_error.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("%s", result);
	result = get_next_line(fd);
	printf("%s", result);
	do {
				result = get_next_line(fd);
				printf("%s", result);
				free(result);
			} while (result != NULL);
	close(fd);
	fd = open("files/read_error.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("%s", result);
	result = get_next_line(fd);
	printf("%s", result);
	result = get_next_line(fd);
	printf("%s", result);
	result = get_next_line(fd);
	printf("%s", result);
	result = get_next_line(fd);
	printf("%s", result);
	close(fd);
	return (0);
}
