/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/16 21:04:26 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_check_path(int x, int y, t_data *game)
{
	if ((game->map[y][x] != '1' && game->map[y][x] != 'E') || \
		(game->map[y][x] == 'E' && game->check.exit))
		return (1);
	return (0);
}

void	move_dir(int x, int y, t_data *game)
{
	if (game->map[y][x] == 'E')
		ft_close(game);
	else if (game->map[y][x] == 'C')
	{
		game->check.collectible++;
		game->map[y][x] = '0';
		if (game->check.collectible == game->map_content.collectible)
			game->check.exit++;
	}
	game->map[game->player.y][game->player.x] = '0';
	game->player.x = x;
	game->player.y = y;
	game->map[y][x] = 'P';
}