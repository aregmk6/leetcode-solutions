m = 10
n = 90

DP = [[0] * n for _ in range(m)]

for i in range(n):
    DP[0][i] = 1

for j in range(n):
    DP[0][j] = 1

for i in range(m):
    for j in range(n):
        DP[i][j] = DP[i][j-1] + DP[i-1][j]

print(DP[m-1][n-1])
