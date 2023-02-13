/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:14:22 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/13 15:11:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_cnt	content_init(void)
{
	t_cnt	content;

	content.isplayer = 0;
	content.collectible = 0;
	content.exit = 0;
	content.player.x = 0;
	content.player.y = 0;
	content.size.x = 0;
	content.size.y = 0;
	return (content);
}

int	ft_setlen(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

t_list	*load_dir(char *path, t_data *game)
{
	t_list	*img;
	int		set;
	char	*str;
	char	number;

	str = ft_strdup(path);
	img = ft_lstnew(mlx_xpm_file_to_image(game->mlx, str, \
		&game->sprite.width, &game->sprite.height));
	number = '1';
	set = ft_setlen(str, '0');
	while (number < '4')
	{
		ft_memset(&str[set], number, 1);
		ft_lstadd_back(&img, ft_lstnew(mlx_xpm_file_to_image(game->mlx, str, \
			&game->sprite.width, &game->sprite.height)));
		number++;
	}
	free(str);
	return (img);
}

void	assign_dir_sprites(t_data *game)
{
	game->sprite.img_down = load_dir("./sprites/dir/down/down0.xpm", game);
	game->sprite.img_up = load_dir("./sprites/dir/up/up0.xpm", game);
	game->sprite.img_left = load_dir("./sprites/dir/left/left0.xpm", game);
	game->sprite.img_right = load_dir("./sprites/dir/right/right0.xpm", game);
}

void	assign_texture(t_data *game)
{
	assign_dir_sprites(game);
	game->sprite.floor[0] = "./sprites/ground.xpm";
	game->sprite.floor[1] = "./sprites/ground1.xpm";
	game->sprite.floor[2] = "./sprites/ground2.xpm";
	game->sprite.wall = "./sprites/wall.xpm";
	game->sprite.collectible = "./sprites/collectible.xpm";
	game->sprite.exit[0] = "./sprites/exit0.xpm";
	game->sprite.exit[1] = "./sprites/exit1.xpm";
	game->sprite.mob = "./sprites/mob.xpm";
	game->sprite.img_wall = mlx_xpm_file_to_image(game->mlx, game->sprite.wall, &game->sprite.width, &game->sprite.height);
	game->sprite.img_floor[0] = mlx_xpm_file_to_image(game->mlx, game->sprite.floor[0], &game->sprite.width, &game->sprite.height);
	game->sprite.img_floor[1] = mlx_xpm_file_to_image(game->mlx, game->sprite.floor[1], &game->sprite.width, &game->sprite.height);
	game->sprite.img_floor[2] = mlx_xpm_file_to_image(game->mlx, game->sprite.floor[2], &game->sprite.width, &game->sprite.height);
	game->sprite.img_collectible = mlx_xpm_file_to_image(game->mlx, game->sprite.collectible, &game->sprite.width, &game->sprite.height);
	game->sprite.img_exit[0] = mlx_xpm_file_to_image(game->mlx, game->sprite.exit[0], &game->sprite.width, &game->sprite.height);
	game->sprite.img_exit[1] = mlx_xpm_file_to_image(game->mlx, game->sprite.exit[1], &game->sprite.width, &game->sprite.height);
	game->sprite.img_mob = mlx_xpm_file_to_image(game->mlx, game->sprite.mob, &game->sprite.width, &game->sprite.height);
}