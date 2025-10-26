#include <stdlib.h>
#include <string.h>

void backtrack(char** res, int* returnSize, char* cur, int open, int close, int n) {
    if (strlen(cur) == 2 * n) {
        res[*returnSize] = strdup(cur);
        (*returnSize)++;
        return;
    }
    if (open < n) {
        cur[strlen(cur)] = '(';
        cur[strlen(cur) + 1] = '\0';
        backtrack(res, returnSize, cur, open + 1, close, n);
        cur[strlen(cur) - 1] = '\0';
    }
    if (close < open) {
        cur[strlen(cur)] = ')';
        cur[strlen(cur) + 1] = '\0';
        backtrack(res, returnSize, cur, open, close + 1, n);
        cur[strlen(cur) - 1] = '\0';
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int maxCount = 1;
    for (int i = 0; i < n; i++) maxCount *= 4; // rough upper bound
    char** res = (char**)malloc(sizeof(char*) * maxCount);
    *returnSize = 0;
    char cur[20] = "";
    backtrack(res, returnSize, cur, 0, 0, n);
    return res;
}
