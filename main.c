/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan_est145 <juan_est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:33:32 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/24 13:32:47 by juan_est145      ###   ########.fr       */
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
	int		fd;
	char	*result;

	result = "a";
	fd = open("lorem_ipsum.txt", O_RDONLY);
	while (result != NULL)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free(result);
	}
	close(fd);
	return (0);
}
