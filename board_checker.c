/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 08:49:27 by erucquoy          #+#    #+#             */
/*   Updated: 2017/03/21 09:29:53 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "board_checker.h"
#include "board_manager.h"

int	check_line(int nb, int **board, int l)
{
	int	c;

	c = 0;
	while (c < 9)
	{
		if (board[l][c] == nb)
			return (0);
		c++;
	}
	return (1);
}

int	check_col(int nb, int **board, int c)
{
	int	l;

	l = 0;
	while (l < 9)
	{
		if (board[l][c] == nb)
			return (0);
		l++;
	}
	return (1);
}

int	check_bloc(int nb, int **board, int l, int c)
{
	int	temp_l;
	int	temp_c;

	temp_l = l - (l % 3);
	temp_c = c - (c % 3);
	l = temp_l;
	c = temp_c;
	while (l < temp_l + 3)
	{
		c = temp_c;
		while (c < temp_c + 3)
		{
			if (board[l][c] == nb)
				return (0);
			c++;
		}
		l++;
	}
	return (1);
}

int	**get_possibilities(int **board)
{
	int	**possibilities;
	int	i;
	int	x;

	if (!(possibilities = (int **)malloc(sizeof(int) * 810)))
		return (0);
	i = -1;
	while (++i < 81)
	{
		if (board[i / 9][i % 9] == '.')
		{
			if (!(possibilities[i] = (int *)malloc(sizeof(int) * 10)))
				return (0);
			possibilities[i][0] = 0;
			x = 0;
			while (++x < 10)
			{
				if (check_bloc(x, board, i / 9, i % 9))
					if (check_line(x, board, i / 9))
						if (check_col(x, board, i % 9))
							possibilities[i][x] = (int)(1);
			}
		}
	}
	return (possibilities);
}

int	check_board(int **board)
{
	int	i;
	int	j;
	int	c;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			c = board[i][j];
			if (c == '.')
			{
				printf("test");
				print_error();
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
