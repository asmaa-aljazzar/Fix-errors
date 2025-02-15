/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <aaljazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:36:22 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 17:45:45 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_pressed(int keycode, t_root *root);
int	key_released(int keycode, t_root *root);
int	destroy_hook(t_root *root);

// This will work when key is pressed 
// Update the value to 1 and will still update 
// the map until the key is released.
int	key_pressed(int keycode, t_root *root)
{
	if (keycode == 65307)
		root_destroy(root, 0, 0);
	if (keycode == 119)
		root->game->player_up = 1;
	if (keycode == 115)
		root->game->player_down = 1;
	if (keycode == 97)
		root->game->player_left = 1;
	if (keycode == 100)
		root->game->player_right = 1;
	update(root);
	return (0);
}

// This will work when keyis released
// Update the value to 0 and then update the map.
int	key_released(int keycode, t_root *root)
{
	if (keycode == 119)
		root->game->player_up = 0;
	if (keycode == 115)
		root->game->player_down = 0;
	if (keycode == 97)
		root->game->player_left = 0;
	if (keycode == 100)
		root->game->player_right = 0;
	update(root);
	return (0);
}

int	destroy_hook(t_root *root)
{
	 //(void)keycode;
	// (void)root;
	// root_destroy (0, 0, 0);
	if (root)
	{
		if (root->game)
		{

			game_destroy (root->game);
			// if (root->game->exit)
			// 	free(&oot->game->exit);
		}
		if (root->player)
			mlx_destroy_image (root->mlx_conn, root->player);
		if (root->exit)
			mlx_destroy_image (root->mlx_conn, root->exit);
		if (root->collect)
			mlx_destroy_image (root->mlx_conn, root->collect);
		if (root->wall)
			mlx_destroy_image (root->mlx_conn, root->wall);
		if (root->floor)
			mlx_destroy_image (root->mlx_conn, root->floor);
		if (root->mlx_img)
			mlx_destroy_image (root->mlx_conn, root->mlx_img);
		if (root->mlx_win)
			mlx_destroy_window (root->mlx_conn, root->mlx_win);
		if (root->mlx_conn)
		{
			mlx_destroy_display (root->mlx_conn);
			free(root->mlx_conn);
		}
		// if (root->game->map)
		// 	free_matrix(root, file, root->game->map, root->game->height);
		// if (root->game->coll)
		// 	free(root->game->coll);
		
		// if (root->file)
		// 	free(root->file);
		free (root);
	}
	die ("exit", 0);
	return (0);
}
