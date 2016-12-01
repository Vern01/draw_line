#include "fdf.h"

cor_t	set_cor(int x1, int y1, int x2, int y2)
{
	cor_t cor;

	cor.x1 = x1;
	cor.y1 = y1;
	cor.x2 = x2;
	cor.y2 = y2;
	return cor;
}

void    bresenham(cor_t cor, mlx_t mlx)
{
	int		dx;
	int		dy;
	int		eps;
	int		color;

	dx = cor.x2 - cor.x1;
	dy = cor.y2 - cor.y1;
	eps = 0;
	color = 0x00FFFFFF;
	while (cor.x1 <= cor.x2)
	{
		mlx_pixel_put(mlx.mlx, mlx.win, cor.x1, cor.y1, color);
		eps += dy;
		if((eps << 1) <= dx * -1)
		{
			color = 0x00FFAABB;
			cor.y1--;
			eps += dx;
		}
		cor.x1++;
	}
/*	while (cor.x1 <= cor.x2)
	{
		mlx_pixel_put(mlx.mlx, mlx.win, cor.x1, cor.y1, color);
		eps += dy;
		if((eps << 1) >= dx)
		{
			color = 0x00FFAABB;
			cor.y1++;
			eps -= dx;
		}
		cor.x1++;
	}*/
}