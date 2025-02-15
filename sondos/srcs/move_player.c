/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:38:39 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:38:41 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_root *root, int x, int y);
void	move_down(t_root *root, int x, int y);
void	move_right(t_root *root, int x, int y);
void	move_left(t_root *root, int x, int y);

void	move_up(t_root *root, int x, int y)
{
	if (root->game->map[y - 1][x] == 0)
		root->game->player.y -= 1;
}

void	move_down(t_root *root, int x, int y)
{
	if (root->game->map[y + 1][x] == 0)
		root->game->player.y += 1;
}

void	move_right(t_root *root, int x, int y)
{
	if (root->game->map[y][x + 1] == 0)
		root->game->player.x += 1;
}

void	move_left(t_root *root, int x, int y)
{
	if (root->game->map[y][x - 1] == 0)
		root->game->player.x -= 1;
}
