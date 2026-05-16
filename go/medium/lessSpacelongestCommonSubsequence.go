// package main

import (
	"fmt"
)

// DP[i][j]

func longestCommonSubsequence(text1 string, text2 string) int {

	s1Len := len(text1) // rows
	s2Len := len(text2) // cols

	DP := make([][]int, 2)
	for i := range 2 {
		DP[i] = make([]int, s2Len+1)
	}

	for i := 1; i < s1Len+1; i++ {
		for j := 1; j < s2Len+1; j++ {
			if text1[i-1] == text2[j-1] {
				DP[i%2][j] = DP[(i-1)%2][j-1] + 1
			} else {
				DP[i%2][j] = max(DP[(i-1)%2][j], DP[i%2][j-1])
			}
		}
	}

	return max(DP[0][s2Len], DP[1][s2Len])
}

// func main() {
// 	fmt.Println(longestCommonSubsequence("abcba", "abcbcba"))
// }
