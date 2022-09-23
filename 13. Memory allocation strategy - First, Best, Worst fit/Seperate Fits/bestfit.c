#include<stdio.h>
#include<conio.h>

int main() {
    int p[20], f[20], min, minindex, n, i, j, c, f1[20], f2[20], f3[20], 
    k = 0, h = 0, flag, t = 0, n1;
    printf("\n\n-----BEST FIT-----\n\n");
    printf("\nEnter the number of memory partitions : ");
    scanf("%d", & n);
    printf("\nEnter the number of process : ");
    scanf("%d", & n1);
    for (i = 0; i < n; i++) {
        printf("\n Enter the memory partition size %d: ", i + 1);
        scanf("%d", & f[i]);
        f1[i] = f[i];
        f2[i] = f[i];
        f3[i] = f[i];
    }
    for (i = 0; i < n; i++) {
        printf("\n Enter the page size %d: ", i + 1);
        scanf("%d", & p[i]);
    }
    
        
            for (i = 0; i < n1; i++) {
                min = 9999;
                minindex = -1;
                for (j = 0; j < n; j++) {
                    if (p[i] <= f2[j] && f2[j] != 0 && min > f2[j]) {
                        min = f2[j];
                        minindex = j;
                    }
                }
                f1[i] = f[minindex];
                f2[minindex] = 0;
            }
            
        printf("\n----------\n\n");
        printf("\n|Page          |Frame          |Free \n");
        printf("\n----------\n");
        t = 0;
        for (i = 0; i < n1; i++) {
            h = f1[i] - p[i];
            if (h < 0)
                h = 0;
            printf("\n%d\t\t%d\t\t%d", p[i], f1[i], h);
            t = t + h;
        }
        printf("\n----------\n");
        printf("\n Total free space in memory: %d\n\n", t);
    
}
