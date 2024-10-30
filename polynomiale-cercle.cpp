#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h> 

void drawCircle(int h, int k, int r) {	
    int x=0,y;
    int i=0.25;
    while(x<=r/sqrt(2)){
    	
		y=sqrt(r*r-(x-h)*(x-h))+k;
		x++;
        putpixel(h + x, k + y, WHITE);  // (h+x, k+y) -
        putpixel(h - x, k + y, WHITE);  // (h-x, k+y) -
        putpixel(h + x, k - y, WHITE);  // (h+x, k-y) -
        putpixel(h - x, k - y, WHITE);  // (h-x, k-y)  -
        putpixel(h + y, k + x, WHITE);  // (h+y, k+x) -
        putpixel(h - y, k + x, WHITE);  // (h-y, k+x)  -
        putpixel(h + y, k - x, WHITE);  // (h+y, k-x)  -
        putpixel(h - y, k - x, WHITE);  // (h-y, k-x)  -       
    }
}

int main() {
    int g = DETECT, m;
    
    // Initialize graphics mode
    initgraph(&g, &m,(char*)"");

    int h = 250, k = 250, r = 300; 
    drawCircle(h, k, r);  

    getch();  
	closegraph();
    return 0;
}
