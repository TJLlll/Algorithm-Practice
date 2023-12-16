#include <stdio.h>
#include <string.h>

void killPlace(char* arr)
{   
    int poss = 1;
    int idx = 1;
    while(arr[idx] != '\0')
    {   /* 以下这三个if、elseif、else不可用while替代 */
        if(arr[idx] == ' ' && arr[idx - 1] != ' ')
        {
            arr[poss++] = arr[idx++];
        }
        else if(arr[idx] == ' ' && arr[idx - 1] == ' ')
        {
            idx++;
        }
        else
        {
            arr[poss++] = arr[idx++];
        }
        
    }
    arr[poss] = '\0';/* 结尾加一个'/0' */
    printf("去空格后的字符串为： %s\n", arr);
    //return poss;
}   

void changeWord(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;
    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    int idx = 0;
    while(str[idx] != '\0')
    {
        while(str[idx] == ' ' && str[idx] != '\0')
        {
            idx++;
        }
        int wordStart = idx;
        while(str[idx] != ' '&& str[idx] != '\0')
        {
            idx++;
        }
        int wordEnd = idx-1;
        while(wordStart < wordEnd)
        {
            char temp = str[wordStart];
            str[wordStart] = str[wordEnd];
            str[wordEnd] = temp;
            wordStart++;
            wordEnd--; 
        }
    }
}

int main()
{
    char str[100];
    printf("输入: ");
    gets(str);
    killPlace(str);
    changeWord(str);
    printf("fanzhuan: %s\n",str);
    return 0;
}