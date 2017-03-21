/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 08:49:10 by erucquoy          #+#    #+#             */
/*   Updated: 2017/03/21 08:49:11 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "board_manager.h"
#include "board_checker.h"
#include "worker.h"

int		count_digits(char **argv)
{
	int i;
	int j;
	int count;

	i = 1;
	count = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] >= '1' && argv[i][j] <= '9')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int		main(int argc, char **argv)
{
	int **board;

	if (argc == 10 && count_digits(argv) >= 17)
	{
		board = create_board();
		if (fill_board(board, argv) == 0)
			return (0);
		fill_sudoku(board);
	}
	else
	{
		print_error();
		return (0);
	}
	return (0);
}
