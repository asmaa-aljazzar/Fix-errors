/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:36:36 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:36:37 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_destroy(t_game *game);

//__If game = 0 this is mean that it not initialize
//  or not fully initialize.
//
// __ Free what we allocated memory for (map, collictables).
// 	-- allocated in map_read().
void	game_destroy(t_game *game)
{
	int	i;

	if (game)
	{
		if (game->coll)
			free (game->coll);
		if (game->map)
		{
			i = 0;
			while (i < game->height)
				free (game->map[i++]);
			free (game->map);
		}
		free (game);
	}
	// free(game->coll->x);
	// free(game->coll->y);
	if (game->coll)
		free(game->coll);
}
