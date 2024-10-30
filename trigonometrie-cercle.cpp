#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>  
#define M_PI 3.14159265358979323846  
void repere(){
    cleardevice();
    setbkcolor(9);
    setcolor(5);
    line(0,240,640,240);
    line(320,0,320,480);
}
void drawCircle(int h, int k, int r) {	
    int x=0 ,y;
    float a=0;
    while(a <= M_PI/4){
		x=r*cos(a);
		y=r*sin(a);        
        
        putpixel(h + x, k + y, WHITE);  // (h+x, k+y)
        putpixel(h - x, k + y, WHITE);  // (h-x, k+y)
        putpixel(h + x, k - y, WHITE);  // (h+x, k-y)
        putpixel(h - x, k - y, WHITE);  // (h-x, k-y)
        putpixel(h + y, k + x, WHITE);  // (h+y, k+x)
        putpixel(h - y, k + x, WHITE);  // (h-y, k+x)
        putpixel(h + y, k - x, WHITE);  // (h+y, k-x)
        putpixel(h - y, k - x, WHITE);  // (h-y, k-x)
		a+=M_PI/25;
    }
}

int main() {
    int g = DETECT, m;
    
    // Initialize graphics mode
    initgraph(&g, &m,(char*)"");

    int h = 250, k = 250, r = 100;  
    drawCircle(h, k, r);  

    getch();  
    closegraph(); 

    return 0;
}
