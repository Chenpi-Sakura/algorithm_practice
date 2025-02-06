#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 5;

void pointexchange(char **s)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (strcmp(s[j], s[j + 1]) > 0)
            {
                char *temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void cpyexchange(char s[][101])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (strcmp(s[j], s[j + 1]) > 0)
            {
                char temp[101];
                strcpy(temp, s[j]);
                strcpy(s[j], s[j + 1]);
                strcpy(s[j + 1], temp);
            }
        }
    }
}

int main()
{
    char *ss[5], sss[5][101];
    for (int i = 0; i < N; i++)
    {
        ss[i] = (char *)malloc(101 * sizeof(char));
        fgets(sss[i], 101, stdin);
        strcpy(ss[i], sss[i]);
    }
    cpyexchange(sss);
    printf("方法（1）：\n");
    for (int i = 0; i < N; i++)
    {
        printf("%s", sss[i]);
    }
    pointexchange(ss);
    printf("方法（2）：\n");
    for (int i = 0; i < N; i++)
    {
        printf("%s", ss[i]);
    }
    return 0;
}