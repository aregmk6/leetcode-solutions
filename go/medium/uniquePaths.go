// package main

import (
	"fmt"
)

func uniquePaths(m int, n int) int {
	DP := make([][]int, m)
	for i := range m {
		DP[i] = make([]int, n)
	}

	for j := range n {
		DP[0][j] = 1
	}
	for i := range m {
		DP[i][0] = 1
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			DP[i][j] = DP[i][j-1] + DP[i-1][j]
		}
	}

	return DP[m-1][n-1]
}

// func main() {
// 	fmt.Println(uniquePaths(10, 10))
// }
