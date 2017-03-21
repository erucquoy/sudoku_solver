/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 08:49:04 by erucquoy          #+#    #+#             */
/*   Updated: 2017/03/21 09:28:44 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_H
# define WORKER_H

void	fill_sudoku(int **board);
int		fill_a_case(int **board, int pos);
int		count_possibilities(int **possibilities, int pos);
int		fill_sudoku_tree(int **board, int pos, int to_test, int first);
int		*get_multi_possib(int **possibilities, int pos);

#endif
