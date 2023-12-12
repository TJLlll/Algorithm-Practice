#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int maxLength = 0;
    int start = 0;
    int charIndex[128];  /* 假设字符集为ASCII，可以根据实际情况调整数组大小 */

    memset(charIndex, -1, sizeof(charIndex));

    for (int end = 0; end < n; end++) {
        if (charIndex[s[end]] != -1) 

        {
            start = (charIndex[s[end]] >= start) ? charIndex[s[end]] + 1 : start;  
        }

        /* 更新字符的最新位置 */ 
        charIndex[s[end]] = end;

        /* 更新最大长度 */ 
        maxLength = (end - start + 1 > maxLength) ? (end - start + 1) : maxLength;
    }

    return maxLength;
}

int main() {
    char input[1000];
    printf("请输入字符串: ");
    fgets(input, sizeof(input), stdin);

    /* 将换行符替换为字符串结束符 */ 
    input[strcspn(input, "\n")] = '\0';

    int result = lengthOfLongestSubstring(input);
    printf("无重复字符串的最长子串长度为: %d\n", result);

    return 0;
}