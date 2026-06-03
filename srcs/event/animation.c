#include "../../header/header.h"

void    display_hands(t_game *g)
{

    (void)g;
    
    mlx_put_image_to_window(g->mlx, g->win, g->hands[0], 120, 200);
    
    

}
