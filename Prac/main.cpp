#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define INT_MAX 2147483647
#define MAX_DIFF 400000
#define MAX_WEIGHT 20000

typedef struct _pair{
    int first;
    int second;
} Pair;

int main(void){
    int n;
    int i, j, ans;
    int diffA, diffB;
    int **dp;
    Pair *pairs;

    scanf("%d", &n);

    pairs = (Pair*)malloc(sizeof(Pair) * n);
    dp = (int**)malloc(sizeof(int*) * (n + 1));
    for(i = 0; i <= n; i++){
        dp[i] = (int*)malloc(sizeof(int) * (MAX_DIFF + 1));
        memset(dp[i], FALSE, sizeof(int) * (MAX_DIFF + 1));
    }

    for(i = 0; i < n; i++){
        scanf("%d %d", &pairs[i].first, &pairs[i].second);
    }

    dp[0][MAX_WEIGHT] = TRUE;

    for(i = 0; i < n; i++){
        diffA = pairs[i].first - pairs[i].second;
        diffB = pairs[i].second - pairs[i].first;
        for(j = 0; j <= MAX_DIFF; j++){
            if(dp[i][j]){
                dp[i + 1][j + diffA] = TRUE;
                dp[i + 1][j + diffB] = TRUE;
            }
        }
    }

    ans = INT_MAX;
    for(i = 0; i <= MAX_DIFF; i++){
        if(dp[n][i]){
            ans = (ans < abs(i - MAX_WEIGHT)) ? ans : abs(i - MAX_WEIGHT);
        }
    }

    printf("%d", ans);

    return 0;
}