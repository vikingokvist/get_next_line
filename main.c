/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:58:08 by ctommasi          #+#    #+#             */
/*   Updated: 2024/10/11 10:58:18 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	mandatory(int argc, char *argv[])
{
	int	fd;
	int	i;
	char	*line;
	
	if (argc != 3)
	{
		printf("-------------------------\n");
		printf("\nWrong Amount of Arguments\n");
		printf("Usage: ./a.out test0.txt 1\n");
		printf("-------------------------\n\n");
		return (1);
	}
	//fd = -1;
	//fd = 1;
	//fd = 1025;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file");
		return (1);
	}
	i = 0;
	while (i < (*argv[2] - '0'))
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (printf("%s", line), free(line), 0);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

int	bonus(int argc, char *argv[])
{
	char	*line;
	int	fd[3];
	int	i;
	int	j;
	int	k;

	if (argc < 2)
	{
		printf("--------------------------------------\n");
		printf("\n     Wrong Amount of Arguments      \n");
		printf("Usage: ./a.out test0.txt test1.txt etc\n");
		printf("--------------------------------------\n\n");
		return (1);
	}
	i = 0;
	while (i < argc)
	{
		fd[i] = open(argv[i+1], O_RDONLY);
		i++;
	}
	//fd[0] = 1;
	//fd[0] = 1024;
	//fd[0] = -1;
	j = 0;
	k = 0;
	while ((line = get_next_line(fd[j])))
	{
		printf("%s", line);
		free(line);
		j++;
		k++;
		if (j == i - 1)
			j = 0;
	}
	free(line);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		mandatory(argc, argv);
		//bonus(argc, argv);
	}
	return (0);
}
