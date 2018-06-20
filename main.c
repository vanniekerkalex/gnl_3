/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:56:57 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/20 11:58:21 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

int	main()
{

	 clock_t start, end;
	 double time_spent;
     
     start = clock();
	int i;
	int fd = open("failed.txt", O_RDONLY);
	char	**line;
	line = malloc(100000);
	*line = malloc(100000);
	i = 1;
	// int count = 0;
	while (i > 0 && i < 800)
	{	
		// count++;
		i = get_next_line(fd, line);
		printf("%d: Buff: {%d}  len: %zu [%s]\n",i ,BUFF_SIZE,ft_strlen(*line), *line);
		// ft_strclr(line);
		// ft_strclr(*line);
	}
	 end = clock();
	

	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
 	printf("%f\n",time_spent); 
	return(0);
}
