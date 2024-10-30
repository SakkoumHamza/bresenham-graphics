#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <stdlib.h>
 
void init_graph(){
    int g = DETECT, m;
    // Initialize graphics mode
    initgraph(&g, &m,(char*)"");
}


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



void polynomiale(int xd,int yd,int xf,int yf){
    //Debut 
    int x= xd, y= yd,px,py; //initialisation 
    int dx = xf - xd, dy = yf - yd ; // calcul de delta x et delta y
    float a,b;
    
    px=xd>xf?-1:1;
    py=yd>yf?-1:1;
    
    pixel(xd,yd,WHITE);
    pixel(xf,yf,WHITE);
    if(	abs(dx)>=abs(dy)){
    	a=(float)dy/dx;
    	b=yd-xd*a;
    	for(x=xd+px; x!=xf; x+=px){
    		y=a*x+b;
    		pixel(x,y,WHITE);	
		}
	}else{
		a=(float)dx/dy;
    	b=xd-yd*a;
    for(y=yd+py; y!=yf; y+=py){
    		x=a*y+b;
    		pixel(x,y,WHITE);
	}
	}
}
int main (){
init_graph();
polynomiale(-6,8,7,-5);
getch();  // Wait for user input
closegraph();
return 0;
}


    


