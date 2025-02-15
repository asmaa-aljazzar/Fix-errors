/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:36:53 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:36:55 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(t_use *use,
				int x,
				int y,
				t_found *found);

// Use the existing duplicated map.
// Start flood-fill from the player position.
// Check if all collectibles & exit were reached.
int	is_valid_path(t_root *root, char **map)
{
	t_found	found;
	t_use	use;

	use.map = map;
	use.root = root;
	found.collectibles_found = 0;
	found.exit_found = 0;
	flood_fill(&use, root->game->player.x, root->game->player.y, &found);
	return (found.collectibles_found == root->game->count_coll \
			&& found.exit_found);
}

// Check edges.
// Stop if it's a wall or already visited.
// Check characters and mark all visited, with increase:
// 	| number of counter.
// 	| check if exit found.
// Recursive calls in four directions.
static void	flood_fill(t_use *use, int x, int y, t_found *found)
{
	t_root	*root;

	root = use->root;
	if (x < 0 || y < 0 || x >= root->game->width || y >= root->game->height)
		return ;
	if (use->map[y][x] == '1' || use->map[y][x] == 'V')
		return ;
	if (use->map[y][x] == 'C')
		found->collectibles_found++;
	if (use->map[y][x] == 'E')
		found->exit_found = 1;
	use->map[y][x] = 'V';
	flood_fill(use, x + 1, y, found);
	flood_fill(use, x - 1, y, found);
	flood_fill(use, x, y + 1, found);
	flood_fill(use, x, y - 1, found);
}
