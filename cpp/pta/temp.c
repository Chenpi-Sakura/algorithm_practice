#include<stdio.h>
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    int s[100];
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    int j,k,f;
    for(j=0;j<m;j++)
    {
        f=s[i];
        for(k=i-1;k>=0;k--)
        {
            s[k-1]=s[k];
        }
        s[0]=f;
    }
     for (int a = 0; a < n; a++)
    {
        printf("%d", s[a]);
        if (a != n - 1)
        {
            printf(" ");
        }
    }
    return 0;
}