#include<stdio.h>
#include<conio.h>

void TowerOfHanoi(int n,char START,char AUX,char END)
{
    if(n>=1)
    {
        int no = 1;
        TowerOfHanoi(n-1,START,END,AUX);
        no++;
        printf("\n%d.)%d is move %c to %c",no,n,START,END);
        
        TowerOfHanoi(n-1,AUX,START,END);
    }
}

int main() {
    int n;
    printf("Enter no of Disk:");
    scanf("%d",&n);
    TowerOfHanoi(n,'a','b','c');
    return 0;
}
