/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:23:44 by hanmpark          #+#    #+#             */
/*   Updated: 2023/02/12 21:25:26 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/libft/includes/get_next_line.h"
# include "../src/libft/includes/ft_printf.h"
# include <mlx.h>

# define MAP_OKAY 1
# define MAP_WRONG 0

/* ***************************** Error messages ***************************** */
# define ERR_MALLOC "Error\nMalloc failed\n"
# define ERR_FORMAT "Error\nFormat error\n"
# define ERR_WALLS "Error\nFound an element different from '1' for wall(s)\n"
# define ERR_ELEMENTS "Error\nWrong number of elements\n"
# define ERR_IMPOSSIBLE "Error\nYour map is impossible !\n"
# define ERR_CASE "Error\nSomething wrong with case(s)\n"
# define ERR_BER "Error\n.ber file does not exist\n"
# define ERR_MLX "Error\nMLX problem\n"

/* ******************************* Key events ******************************* */
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEY_ESC 53
# define KEY_L 0
# define KEY_D 1
# define KEY_R 2
# define KEY_U 13

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_win
{
	void	*id;
	t_pos	size;
}				t_win;

typedef struct	s_img
{
	t_list	*img_down;
	t_list	*img_left;
	t_list	*img_right;
	t_list	*img_up;
	void	*img_floor[3];
	void	*img_wall;
	void	*img_collectible;
	void	*img_exit[2];
	void	*img_mob;
	char	*down;
	char	*left;
	char	*right;
	char	*up;
	char	*floor[3];
	char	*wall;
	char	*collectible;
	char	*exit[2];
	char	*mob;
	int		height;
	int		width;
}				t_img;

typedef struct	s_content
{
	t_pos	player;
	int		isplayer;
	int		collectible;
	int		exit;
	t_pos	size;
}				t_cnt;

typedef struct	s_data
{
	char	**map;
	t_cnt	content;
	t_cnt	check;
	void	*mlx;
	t_win	win;
	t_img	sprite;
}				t_data;

char	**map_init(const char *file, t_cnt *mapi);
void	check_edges(char **map, t_cnt *mapi);
void	check_content(char **map, t_cnt *mapi);

void	game_init(t_data *game);
t_cnt	content_init(void);
void	assign_texture(t_data *game);
t_list	*load_dir(char *path, t_data *game);

int		ft_close(t_data *data);
int		key_hook(int keycode, t_data *game);

void	print_background(t_list *img_player, t_pos pos, t_data *game);
void	print_img(t_data *game, void *img, int x, int y);
void	set_img_dir(int dir, t_pos pos, t_data *game);
void	anim_dir(t_data *game, t_list *img, t_pos win, t_pos m);

#endif