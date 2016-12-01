#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

typedef struct	mlx_s
{
	void	*mlx;
	void	*win;
}				mlx_t;

typedef struct	cor_s
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				cor_t;

typedef struct	line_s
{
	float		dx;
	float		dy;
	float		de;
	float		e;
	int		swap;
}				line_t;

void    bresenham(cor_t cor, mlx_t mlx);
void	bresenham_p(cor_t cor, mlx_t mlx);
cor_t	set_cor(int x1, int y1, int x2, int y2);

#endif