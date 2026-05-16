// package main

import (
	"fmt"
)

// X = (S - T) / 2

func findTargetSumWays(nums []int, target int) int {
	sumAll := func(nums []int) int {
		sum := 0
		for _, v := range nums {
			sum += v
		}
		return sum
	}(nums)

	if sumAll < target || (sumAll-target)%2 != 0 {
		return 0
	}

	DPmat := make([][]int, len(nums)+1)
	for i := range len(nums) + 1 {
		DPmat[i] = make([]int, ((sumAll-target)/2)+1)
	}

	DPmat[0][0] = 1
	for i := 1; i < len(nums)+1; i++ {
		for j := 0; j < ((sumAll-target)/2)+1; j++ {
			if j-nums[i-1] >= 0 {
				DPmat[i][j] = DPmat[i-1][j] + DPmat[i-1][j-nums[i-1]]
			} else {
				DPmat[i][j] = DPmat[i-1][j]
			}
		}
	}

	return DPmat[len(nums)][(sumAll-target)/2]
}

// func main() {
// 	count := findTargetSumWays([]int{1, 1, 1, 1, 1}, 3)
// 	fmt.Println(count)
// }
