#include <stdio.h>
#include <string.h>

void killPlace(char* arr)
{   
    int poss = 0;
    int idx = 0;
    
    while (arr[idx] != '\0')
    {
        if (arr[idx] != ' ' || (idx > 0 && arr[idx - 1] != ' '))
        {
            arr[poss++] = arr[idx];
        }
        idx++;
    }
    
    arr[poss] = '\0'; // Terminate the string
    printf("去空格后的字符串为：%s\n", arr);
}

void reverseWords(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;
    
    // Reverse the entire string
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    
    int idx = 0;
    while (str[idx] != '\0')
    {
        int wordStart = idx;
        while (str[idx] != ' ' && str[idx] != '\0')
        {
            idx++;
        }
        int wordEnd = idx - 1;

        // Reverse each word
        while (wordStart < wordEnd)
        {
            char temp = str[wordStart];
            str[wordStart] = str[wordEnd];
            str[wordEnd] = temp;
            wordStart++;
            wordEnd--; 
        }

        // Move to the next word
        idx++;
    }
}

int main()
{
    char str[100];
    printf("输入: ");
    fgets(str, sizeof(str), stdin); // Use fgets instead of gets

    // Remove trailing newline from input
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    killPlace(str);
    reverseWords(str);
    printf("Reversed words: %s\n", str);

    return 0;
}
