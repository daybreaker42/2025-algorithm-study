def solution():
    n = int(input())
    
    # Initialize dp table
    dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
    
    for i in range(1, n+1):
        t, p = map(int, input().split())
        
        if i + t - 1 > n:  # Can't complete this consultation before retirement
            for ii in range(1, n+1):
                dp[i][ii] = dp[i-1][ii]
        else:
            for ii in range(1, n+1):
                if ii < i + t - 1:
                    dp[i][ii] = dp[i-1][ii]
                elif ii == i + t - 1:
                    dp[i][ii] = max(dp[i-1][ii-t] + p, dp[i-1][ii])
                else:
                    dp[i][ii] = max(dp[i-1][ii], dp[i][ii-1])
    
    return dp[n][n]

if __name__ == "__main__":
    print(solution())
