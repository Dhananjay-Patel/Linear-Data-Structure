#include <stdio.h>
#include <conio.h>

int fact(int num)
{
    int ans = num;
    if (num == 0)
        return 1;
    if (num != 1)
    {
        ans = ans * fact(num - 1);
    }
    else
    {
        return 1;
    }
    return ans;
}
void main()
{
    int num;
    printf("Enter num:");
    scanf("%d", &num);
    printf("Factorial of %d is %d", num, fact(num));
}