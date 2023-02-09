/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:45:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/09 09:21:04 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	print_img(t_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win.id, img,
		game->sprite.width * x, game->sprite.height * y);
}

static void	print_background(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if ((j % 2 && !(i % 2)) || (!(j % 2) && i % 2))
				print_img(game, game->sprite.img_floor, j, i);
			else
				print_img(game, game->sprite.img_floor1, j, i);
			if (game->map[i][j] == '1')
				print_img(game, game->sprite.img_wall, j, i);
		}
	}
}

static void	print_elements(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	mlx_put_image_to_window(game->mlx, game->win.id, game->sprite.img_down,
		64 * game->content.player.x, 64 * game->content.player.y - 10);
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				print_img(game, game->sprite.img_collectible, j, i);
			else if (game->map[i][j] == 'E')
				print_img(game, game->sprite.img_exit[1], j, i);
			else if (game->map[i][j] == 'M')
				print_img(game, game->sprite.img_mob, j, i);
		}
	}
}

// static void	print_animation(t_data *game)
// {
// 	static int	frame = 0;
// 	static int	i = 0;

// 	frame++;
// 	print_img(game, game->sprite.img_player[i], game->content.player.x, game->content.player.y);
// 	if (frame == 5)
// 		i++;
// 	if (i == 7)
// 		i = 0;
// 	if (frame == 10)
// 		frame = 0;
// }

int	render(t_data *game)
{
	print_background(game);
	print_elements(game);
	// print_animation(game);
	return (0);
}
