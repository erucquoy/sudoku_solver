/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erucquoy <erucquoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 08:49:39 by erucquoy          #+#    #+#             */
/*   Updated: 2017/03/21 09:28:54 by erucquoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_MANAGER_H
# define BOARD_MANAGER_H

int		fill_board(int **board, char **argv);
int		**create_board(void);
void	print_board(int **board);
int		add_case(int **board, int l, int c, int nb);
int		**boarddup(int **board);
void	print_error();

#endif
