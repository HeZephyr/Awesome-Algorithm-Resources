#include <stdio.h>
#include<stdlib.h>
 
int quick_select(int a[], int l, int r, int k) {
    int p = rand() % (r - l + 1) + l;//生成一个范围在[l,r]之间的。
    int x = a[p];//随机选取了下标与其进行交换。
    {int t = a[p]; a[p] = a[r]; a[r] = t;}
    int i = l, j = r;//此时j代表的值是x，原来p的值为a[r]。
    while(i < j) {
        //寻找第一个大于等于x的下标。
        while(i < j && a[i] < x) i++;
        //如果找到了，那么就将值传给a[j]。实际上就是以x为参照，选择一个比x大的数，放到高位。
        if(i < j) {
            a[j] = a[i];
            j--;
        }
        //找到最后一个小于等于x的下标。
        while(i < j && a[j] > x) j--;
        //如果找到了就交换这值。
        if(i < j) {
            a[i] = a[j];//选择一个比x小的数，放到低位。
            i++;
        }
    }
    a[i] = x;
    p = i;
    if(i - l + 1 == k) return a[i];//说明区间
    //if(i - l + 1 < k) return quick_select( _____________________________ ); //填空
    if(i - l + 1 < k) return quick_select(a,i+1,r,k-i+l-1); //填空
    else return quick_select(a, l, i - 1, k);
}
    
int main()
{
    int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12};
    printf("%d\n", quick_select(a, 0, 14, 5));
    for(int i=0;i<=14;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
 
}