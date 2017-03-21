/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 08:48:56 by erucquoy          #+#    #+#             */
/*   Updated: 2017/03/21 09:29:07 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "worker.h"
#include "board_checker.h"
#include "board_manager.h"

void	fill_sudoku(int **board)
{
	int i;
	int l;
	int c;
	int work;
	int possib;

	i = -1;
	work = 1;
	while (++i < 81 && work)
	{
		l = i / 9;
		c = i % 9;
		if (board[l][c] == '.')
		{
			possib = fill_a_case(board, i);
			if (possib > 0)
			{
				board[l][c] = possib;
				work = 0;
				fill_sudoku(board);
			}
		}
	}
	if (work == 1)
		print_board(board);
}

int		fill_sudoku_tree(int **board, int pos, int to_test, int first)
{
	int i;
	int l;
	int c;
	int work;
	int possib;

	i = -1;
	work = 1;
	if (first)
		board = boarddup(board);
	board[pos / 9][pos % 9] = to_test;
	while (++i < 81 && work)
	{
		l = i / 9;
		c = i % 9;
		if (board[l][c] == '.')
		{
			possib = fill_a_case(board, i);
			if (possib > 0)
			{
				board[l][c] = possib;
				work = 0;
				fill_sudoku_tree(board, pos,  to_test, 0);
			}
		}
	}
	if (work == 1)
		return (to_test);
}

int		fill_a_case(int **board, int pos)
{
	int **possibilities;
	int *possib;
	int res[9];

	possibilities = get_possibilities(board);
	if (count_possibilities(possibilities, pos) == 1)
	{
		possib = get_multi_possib(possibilities, pos);
		if (possib[0] > 0)
		{
			return (possib[0]);
		}
		else
			return (0);
	}
	else if (count_possibilities(possibilities, pos) == 2)
	{
		possib = get_multi_possib(possibilities, pos);
		if (possib[0] > 0 && possib[1] > 0 && possib[0] <= 9 && possib[1] <= 9)
		{
			res[0] = fill_sudoku_tree(board, pos, possib[0], 1);
			res[1] = fill_sudoku_tree(board, pos, possib[1], 1);
			if (res[0] && !res[1])
				return (res[0]);
			if (res[1])
				return (res[1] && !res[0]);
		}
		else
			return (0);
	}
	return (0);
}

int		count_possibilities(int **possibilities, int pos)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 10)
	{
		if (possibilities[pos][i] == 1)
			count++;
		i++;
	}
	return (count);
}

int		*get_multi_possib(int **possibilities, int pos)
{
	int i;
	int *tab;
	int count;

	i = 0;
	count = 0;
	if (!(tab = (int *)malloc(sizeof(int) * 10)))
		return (0);
	while (i < 10)
	{
		if (possibilities[pos][i] == 1)
		{
			tab[count] = i;
			count++;
		}
		i++;
	}
	tab[count] = 0;
	return (tab);
}
