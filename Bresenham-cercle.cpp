
#include <graphics.h>

void drawCircle(int h, int k, int r) {	
    int x = 0;
    int y = r;

    
    int s = 3 - 2 * r;  // Decision variable

    while (x < y) {
		if (s > 0) {
            s +=  4 * (x-y) + 10;
            y--; 
        }
		else {
            s+= 4 * x + 6;
        }
        x++;
        
        // Plot the 8 symmetric points of the circle
        putpixel(h + x, k + y, WHITE);  // (h+x, k+y)
        putpixel(h - x, k + y, WHITE);  // (h-x, k+y)
        putpixel(h + x, k - y, WHITE);  // (h+x, k-y)
        putpixel(h - x, k - y, WHITE);  // (h-x, k-y)
        putpixel(h + y, k + x, WHITE);  // (h+y, k+x)
        putpixel(h - y, k + x, WHITE);  // (h-y, k+x)
        putpixel(h + y, k - x, WHITE);  // (h+y, k-x)
        putpixel(h - y, k - x, WHITE);  // (h-y, k-x)

    }
}

int main() {

    // Initialize graphics mode
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, (char *)"");


    int h = 250, k = 250, r = 100;  // Circle center (h, k) and radius r
    drawCircle(h, k, r);  // Draw the circle

    getch();  // Wait for user input
    closegraph();  // Close the graphics window

    return 0;
}