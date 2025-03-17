/*
6-7 分词并显示
程序的功能是：调用Input函数读入最多80个字符，要求字符串中只保留字母和空格，遇到读满或者回车结束读入字符，空格用于分隔单词。请将字符串中用空格分隔的单词在屏幕上输出来。
要求用指针完成函数中各参数的传递与访问，自定义函数头和函数体中不得出现数组下标形式的表示法。
*/
#include <stdio.h>

void Input ( char *str );
int Split_Count ( char *str,char **pStr );

int main(void)
{
    char String[81]={0}, *pString[45];
    int i=0, count;
    
    Input(String);
    
    count = Split_Count(String,  pString);
     
    printf("%d Words: ", count);
    for (i=0; i<count-1; i++)
    {
         printf("%s-", pString[i]);
    }
    printf("%s", pString[count-1]);
    putchar('\n');
    return 0;
}

void Input ( char *str )
{
    int i = 0;
    while(i < 80)
    {
        char temp = getchar();
        if (temp == '\n')
            break;
        if (temp == ' ' || (temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
        {
            str[i] = temp;
            i++;
        }
    }
    str[i] = '\0';
    return;
}

int Split_Count( char *str,char **pStr )
{
    int k = 0;
    while (*str != '\0')
    {
        while (*str == ' ')
            str++;
        //跳过空格
        if (*str == '\0')
            break;
        //检查位置
        pStr[k++] = str;
        //指定位置
        while (*str != ' ' && *str != '\0')
            str++;
        //跳过非空格
        if (*str == ' ')
        {
            *str = '\0';
            str++;
        }
        //结束单词的位置
    }
    return k;
}