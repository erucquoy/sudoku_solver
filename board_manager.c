/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 08:49:16 by erucquoy          #+#    #+#             */
/*   Updated: 2017/03/21 09:29:27 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "board_manager.h"
#include "board_checker.h"

int		fill_board(int **board, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
				board[i - 1][j] = argv[i][j];
			else
			{
				if (add_case(board, i - 1, j, argv[i][j]) == 0)
				{
					printf("test");
					print_error();
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		add_case(int **board, int l, int c, int nb)
{
	if (!(nb >= '1' && nb <= '9'))
		return (0);
	if (check_bloc(nb, board, l, c))
		if (check_line(nb, board, l))
			if (check_col(nb, board, c))
			{
				board[l][c] = nb - 48;
				return (1);
			}
			else
			{
				return (0);
			}
		else
		{
			return (0);
		}
	else
	{
		return (0);
	}
}

int		**create_board(void)
{
	int i;
	int j;
	int **board;

	i = 0;
	j = 0;
	board = (int **)malloc(sizeof(int) * 81);
	while (i < 9)
	{
		board[i] = (int *)malloc(sizeof(int) * 9);
		j = 0;
		while (j < 9)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}

void	print_board(int **board)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	if (!check_board(board))
		return ;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			c = board[i][j] + 48;
			write(1, &c, 1);
			if (j < 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		**boarddup(int **board)
{
	int **tab;
	int i;

	tab = (int **)malloc(sizeof(int) * 90);
	i = 0;
	while (i < 81)
	{
		tab[i / 9] = (int *)malloc(sizeof(int) * 10);
		tab[i / 9][i % 9] = board[i / 9][i % 9];
		i++;
	}
	return tab;
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}
