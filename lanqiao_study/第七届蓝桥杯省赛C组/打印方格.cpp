#include <stdio.h>


//打印m列，n行的方格 
void f(int m, int n)
{
    int row;
    int col;
    for(row=0; row<n; row++){
        for(col=0; col<m; col++) printf("+---");
        printf("+\n");
        for(col=0; col<m; col++) printf("|   ");
        printf("|\n");
    }
    printf("+");
    //_____________________________;   //填空
    for(col =0;col<m;col++)printf("---+");
    printf("\n");
}


int main()
{
    f(10,4);
    return 0;
}
