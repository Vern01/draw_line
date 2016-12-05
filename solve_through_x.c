#include "fdf.h"

void	solve_through_x(cor_t cor, line_t line, mlx_t mlx)
{
	 if (cor.x1 > cor.x2)
        swap_points(&cor);
    if ((line.dx > 0 && line.dy < 0))
		while (cor.x1 <= cor.x2)
	    {
			mlx_pixel_put(mlx.mlx, mlx.win, cor.x1, cor.y1, 0x00FFFFFF);
	       	line.eps += line.dy;
	    	if((line.eps << 1) <= line.dx * -1)
    		{
    			cor.y1--;
    			line.eps += line.dx;
    		}
     		cor.x1++;
	    }
	else
		while (cor.x1 <= cor.x2)
	    {  
	    	mlx_pixel_put(mlx.mlx, mlx.win, cor.x1, cor.y1, 0x00FFFFFF);
		    line.eps += line.dy;
	    	if((line.eps << 1) >= line.dx)
	    	{	
	    		cor.y1++;
		    	line.eps -= line.dx;
	    	}
	    	cor.x1++;
	    }
}