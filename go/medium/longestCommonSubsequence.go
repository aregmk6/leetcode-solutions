// package main

import (
	"fmt"
)

// DP[i][j]

func longestCommonSubsequence(text1 string, text2 string) int {

	s1Len := len(text1) // rows
	s2Len := len(text2) // cols

	DP := make([][]int, s1Len+1)
	for i := range s1Len + 1 {
		DP[i] = make([]int, s2Len+1)
	}

	for i := 1; i < s1Len+1; i++ {
		for j := 1; j < s2Len+1; j++ {
			if text1[i-1] == text2[j-1] {
				DP[i][j] = DP[i-1][j-1] + 1
			} else {
				DP[i][j] = max(DP[i-1][j], DP[i][j-1])
			}
		}
	}

	return DP[s1Len][s2Len]
}

// func main() {
// 	fmt.Println(longestCommonSubsequence("abcba", "abcbcba"))
// }
