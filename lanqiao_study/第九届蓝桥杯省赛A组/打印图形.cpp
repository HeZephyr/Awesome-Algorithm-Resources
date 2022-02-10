#include <stdio.h>
#include <stdlib.h>

void show(char* buf, int w){
    int i,j;
    for(i=0; i<w; i++){
        for(j=0; j<w; j++){
            printf("%c", buf[i*w+j]==0? ' ' : 'o');
        }
        printf("\n");
    }
}

void draw(char* buf, int w, int x, int y, int size){
    if(size==1){
        buf[y*w+x] = 1;
        return;
    }

    //int n = ________________________ ; //填空
    int n=size/3;
    draw(buf, w, x, y, n);
    draw(buf, w, x-n, y ,n);
    draw(buf, w, x+n, y ,n);
    draw(buf, w, x, y-n ,n);
    draw(buf, w, x, y+n ,n);
}

int main()
{
    int N = 3;
    int t = 1;
    int i;
    for(i=0; i<N; i++) t *= 3;

    char* buf = (char*)malloc(t*t);
    for(i=0; i<t*t; i++) buf[i] = 0;

    draw(buf, t, t/2, t/2, t);
    show(buf, t);
    free(buf);

    return 0;
}