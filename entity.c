#include "entity.h"

int 
    down=0,up=0,
nb_frame=15 ;//3ded les images 




void init_tab_anim_entity(SDL_Rect *clip)
{
    // imashy 3al imin
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = 100;
    clip[0].h = 100;
    int i = 1;
    for (i = 1; i < nb_frame; i++)
    {
        clip[i].w = 100;
        clip[i].h = 100;
        clip[i].x = clip[i].w + clip[i - 1].x;
        clip[i].y = 0;
    }

    //3al isar
    clip[nb_frame].x = 0;
    clip[nb_frame].y = 100;
    clip[nb_frame].w = 100;
    clip[nb_frame].h = 100;
    i = (nb_frame + 1);
    for (i =(nb_frame + 1); i <( 2*nb_frame ); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 100;
        clip[i].h = 100;
    }
    
    clip[2*nb_frame ].x = 0;
    clip[2*nb_frame ].y = 200;
    clip[2*nb_frame ].w = 100;
    clip[2*nb_frame ].h = 100;
    i =(2*nb_frame +1);
    for (i = (2*nb_frame +1); i < (3* nb_frame); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 200;
        clip[i].h = 100;
    }

    
    clip[3* nb_frame].x = 0;
    clip[3* nb_frame].y = 300;
    clip[3* nb_frame].w = 100;
    clip[3* nb_frame].h = 100;
    i =( 3* nb_frame+1);
    for (i = (3* nb_frame+1); i < (4*nb_frame); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 300;
        clip[i].h = 100;
    }
}

void initialiser_entity(entity *e)
{
    e->entity = IMG_Load("run.png");
    e->pos_entity.x = 700;
    e->pos_entity.y = 100;
    init_tab_anim_entity(e->anim_entity);
    e->frame_entity=0;
    
}


void afficher_entity(entity * e , SDL_Surface *screen)
{
   
   SDL_BlitSurface(e->entity,&e->anim_entity[e->frame_entity], screen, &e->pos_entity);

  

}

void mvt_entity(entity *e)
{
int maxi_down=500;
int maxi_up=100;
maxi_down=((rand()%(maxi_down+1))+maxi_down);
maxi_up=((rand()%(maxi_up+1))+maxi_up);

if(e->pos_entity.y>=maxi_down)
{
e->direction =1;
}
if(e->pos_entity.y<=maxi_up)
{
e->direction =0;
}
if(e->direction==1)
{
	e->pos_entity.y-=5;
}
if(e->direction==0)
{
	e->pos_entity.y+=5;
}
}



void anim(entity *e)
{   if (e->frame_entity >=0 && e->frame_entity <(nb_frame-1)) 
 e->frame_entity++;
    if ( e->frame_entity ==(nb_frame-1)) 
       e->frame_entity=0;


}
void update_entity(entity *e)
{
	anim(e);
	mvt_entity(e);
	
}

