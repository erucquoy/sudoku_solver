/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 08:49:22 by erucquoy          #+#    #+#             */
/*   Updated: 2017/03/21 08:49:23 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_CHECKER_H
# define BOARD_CHECKER_H

int		check_bloc(int nb, int **board, int l, int c);
int		check_col(int nb, int **board, int c);
int		check_line(int nb, int **board, int l);
int		**get_possibilities(int **board);
int		check_board(int **board);

#endif
