#include "fdf.h"

void	solve_through_y(cor_t cor, line_t line, mlx_t mlx)
{
	if (cor.y1 > cor.y2)
        swap_points(&cor);
    if ((line.dy > 0 && line.dx < 0))
		while (cor.y1 <= cor.y2)
	    {
	        mlx_pixel_put(mlx.mlx, mlx.win, cor.x1, cor.y1, 0x00FFFFFF);
	       	line.eps += line.dx;
	    	if((line.eps << 1) <= line.dy * -1)
    		{
    			cor.x1--;
    			line.eps += line.dy;
    		}
     		cor.y1++;
	    }
	else
		while (cor.y1 <= cor.y2)
	    {
	        mlx_pixel_put(mlx.mlx, mlx.win, cor.x1, cor.y1, 0x00FFFFFF);
		    line.eps += line.dx;
	    	if((line.eps << 1) <= line.dy)
	    	{	
	    		cor.x1++;
		    	line.eps -= line.dy;
	    	}
	    	cor.y1++;
		}
}