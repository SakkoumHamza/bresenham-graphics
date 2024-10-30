#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <stdlib.h>
#include <cmath>
//initialisationde mode graphique
void init_graph(){
    char path[] = "C:\\TDM-GCC-32\\lib\\bgi";
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, path);

}

//Tra�age de repere en utilisant l'instruction line

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

//  --------------------------------------------------------------------------------------------------------------

void line_B(int xd,int yd,int xf,int yf){
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

// ----------------------------------------------------------------------------------------------------------------------
void line_P(int xd,int yd,int xf,int yf){
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

// ----------------------------------------------------------------------------------------------------------------------
void cercle_B(int h, int k, int r) {
    int x = 0;
    int y = r;

    int s = 3 - 2 * r;

    while (x < y) {
		if (s > 0) {
            s +=  4 * (x-y) + 10;
            y--;
        }
		else {
            s+= 4 * x + 6;
        }
        x++;


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
// ----------------------------------------------------------------------------------------------------------------------
void cercle_P(int h, int k, int r) {
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
// ----------------------------------------------------------------------------------------------------------------------
void cercle_T(int h, int k, int r) {
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
// ----------------------------------------------------------------------------------------------------------------------
void ellipse_P(int h,int k,int a,int b){
	int x = 0 ;
	while(x<=a){
		float y = sqrt( b*b * ( 1 - float( ( x - h ) * ( x - h )) / ( a * a ) ) ) + k;
		pixel(h + x, k + round(y), WHITE);  // (h+x, k+y)
        pixel(h - x, k + round(y), WHITE);  // (h-x, k+y)
        pixel(h + x, k - round(y), WHITE);  // (h+x, k-y)
        pixel(h - x, k - round(y), WHITE);  // (h-x, k-y)
        ++x;
	}

}

// ------------------------------------------------------------------------------------------
void ellipse_T(int h,int k,int a,int b){
	float o = 0 ;
	while(o<=M_PI/2){
		float x=a*cos(o)+h;
		float y=b*sin(o)+k ;

		pixel(h + round(x), k + round(y), WHITE);  // (h+x, k+y)
        pixel(h - round(x), k + round(y), WHITE);  // (h-x, k+y)
        pixel(h + round(x), k - round(y), WHITE);  // (h+x, k-y)
        pixel(h - round(x), k - round(y), WHITE);  // (h-x, k-y)

        o+=M_PI/100 ;
	}

}


// ----------------------------------------------------------------------------------------------------------------------



int main (){
int choix,methode;
int xd,yd,xf,yf;
int h, k, r, a, b;

printf("Qu'est ce que vous voullez dessiner?\n");
printf("1) Ligne \n");
printf("2) Cercle \n");
printf("3) Ellipse \n");
scanf("%d",&choix);
printf("Methode ?\n");
printf("1) Bresenham \n");
printf("2) Polynomiale \n");
printf("3) Trigonometrique\n");
scanf("%d",&methode);


if(choix==1){
	if(methode==1){
		printf("veuillez entrer les valeur xd,yd,xf,yf");
		scanf("%d %d %d %d",&xd,&yd,&xf,&yf);
		line_B(xd,yd,xf,yf);
	}
	else{
		printf("veuillez entrer les valeur xd,yd,xf,yf");
		scanf("%d %d %d %d",&xd,&yd,&xf,&yf);
		line_P(xd,yd,xf,yf);
	}
}
else if(choix==2){
	if(methode==1){
		printf("veuillez entrer les valeurs (h,k) et r");
		scanf("%d %d %d",&h,&k,&r);
		cercle_B(h,k,r);
	}
	else if(methode==2){
		printf("veuillez entrer les valeurs (h,k) et r");
		scanf("%d %d %d",&h,&k,&r);
		cercle_P(h,k,r);
	}
	else {
		printf("veuillez entrer les valeurs (h,k) et r");
		scanf("%d %d %d",&h,&k,&r);
		cercle_T(h,k,r);
	}
}
	if(choix==3){
		if(methode==2){
			printf("veuillez entrer les valeurs (h,k) et a b ");
			scanf("%d %d %d %d",&h,&k,&a,&b);
			init_graph();

			repere();
			ellipse_P(h,k,a,b);
			getch();
		}
		else if(methode==3){
			printf("veuillez entrer les valeurs (h,k) et a b ");
			scanf("%d %d %d %d",&h,&k,&a,&b);
			init_graph();
			repere();
			ellipse_T(h,k,a,b);
			getch();
		}
	}
return 0;
}
