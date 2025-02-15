/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:36:45 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 17:37:57 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_root *root, char *file_name);

//__ This function initialize game structure 
//   by set an initial value to 0 
//   after allocate a memory for it with ( t_game * ) size.
void	game_init(t_root *root, char *file_name)
{
	root->game = (t_game *)malloc (sizeof (t_game));
	if (!root->game)
		root_destroy(root, "game_init(): malloc():", errno);
	root->game->map = 0;
	root->game->coll = 0;
	root->game->count_coll = 0;
	root->game->count_exit = 0;
	root->game->count_player = 0;
	root->game->player_move = 0;
	root->game->player_coll = 0;
	root->game->player_up = 0;
	root->game->player_down = 0;
	root->game->player_left = 0;
	root->game->player_right = 0;
	root->game->coll_found = 0;
	root->game->exit_found = 0;
	map_init (root, file_name);
}
