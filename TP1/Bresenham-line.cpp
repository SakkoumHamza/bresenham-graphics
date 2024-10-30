#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <stdlib.h>

//initialisationde mode graphique 
void init_graph(){
    char path[] = "C:\\MinGW\\lib\\libbgi";
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, path);
}

//Traçcage de repere en utilisant l'instruction line

void repere(){
    cleardevice();
    setbkcolor(9);
    setcolor(5);
    line(0,240,640,240);
    line(320,0,320,480);
}

void pixel(int x , int y , int color){
    x=x+320;
    y=240-y;
    putpixel(x,y,color);
}




void Bresenham_line(int xd,int yd,int xf,int yf){
    //Debut 
    int x= xd, y= yd; //initialisation 
    int dx = xf - xd, dy = yf - yd ; // calcul de delta x et delta y
    int i=1;
    
    if(dx>=dy){ // premier octant
        int S=(2*abs(dy))-abs(dx);
        printf("la droite par le premier octant est :\n"); 
        printf("(%d,%d)\n",x,y); //affichage du premier point 
        while (abs(dx)>=i){
            if(dx<0){x--;} else x++;
            if(S>0){
                if(dy<0){y--;} else y++;
                S+=2*(abs(dy)-abs(dx));
                pixel(x,y,WHITE);
                i++;
                printf("(%d,%d)\n",x,y);
            }else{
                S+=2*abs(dy);
                i++;
                pixel(x,y,WHITE);
                printf("(%d,%d)\n",x,y);
            }
        }
        printf("fin");
    }
    
    else{ //deuxieme octant
        int S=(2*abs(dx))-abs(dy);
        printf("la droite par le deuxieme octant est :\n");  
        printf("(%d,%d)\n",x,y); //affichage du premier point
        while (abs(dy)>=i){
            if(S>0){
            if(dy<0){y--;} else y++;
                if(dx<0){x--;} else x++;
                S=S+2*(abs(dx)-abs(dy));
                pixel(x,y,WHITE);
                i++;
                printf("(%d,%d)\n",x,y);
            }else{
                S=S+2*abs(dx);
                pixel(x,y,WHITE);
                i++;
                printf("(%d,%d)\n",x,y);
            }
        }
        printf("fin");
    }


}
int main (){
init_graph();
repere();
Bresenham_line(-6,8,7,-5);
getch();
return 0;
}


