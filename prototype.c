#include "fdf.h"

void      set_line_info(line_t *line, cor_t cor)
{
    line->dx = cor.x2 - cor.x1;
    line->dy = cor.y2 - cor.y1;
    line->de = fabsf(line->dy) * 2;
    line->e = 0;
}

int     swap_xy(cor_t *cor)
{
    int     temp;

    temp = cor->x1;
    cor->x1 = cor->y1;
    cor->y1 = temp;
    temp = cor->x2;
    cor->x2 = cor->y2;
    cor->y2 = temp;
    return (1);
}

void    swap_points(cor_t *cor)
{
    int     temp;

    temp = cor->x1;
    cor->x1 = cor->x2;
    cor->x2 = temp;
    temp = cor->y1;
    cor->y1 = cor->y2;
    cor->y2 = temp;
}

void	bresenham_p(cor_t cor, mlx_t mlx)
{
	line_t	line;

	line.swap = 0;
    if (abs(cor.x1 - cor.x2) < abs(cor.y1 - cor.y2))
        line.swap = swap_xy(&cor);
    if (cor.x1 > cor.x2)
        swap_points(&cor);
    set_line_info(&line, cor);
	while (cor.x1 < cor.x2)
	{
		if (line.swap)
			mlx_pixel_put(mlx.mlx, mlx.win, cor.y1, cor.x1, 0x00FFFFFF);
		else
			mlx_pixel_put(mlx.mlx, mlx.win, cor.x1, cor.y1, 0x00FFFFFF);
		line.e += line.de;
		if (line.e > line.dx)
		{
			cor.y1 += (cor.y1 > cor.y2 ? 1 : -1);
			line.e -= line.dx * 2;
		}
	}
}