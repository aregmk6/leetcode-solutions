// package main

import (
	"fmt"
	"slices"
)

func threeSum(nums []int) [][]int {
	slices.Sort(nums)

	var triplets [][]int
	for i, v := range nums {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		target := -v
		left, right := i+1, len(nums)-1
		for left < right {
			sum := nums[left] + nums[right]
			if sum == target {
				triplets = append(triplets, []int{nums[i], nums[left], nums[right]})
				right--
				left++

				for left < right && nums[left] == nums[left-1] {
					left++
				}
			} else if sum > target {
				right--
			} else {
				left++
			}
		}
	}

	return triplets
}

// func main() {
// 	nums := []int{1, 0, -1, 2, 1, 0, -1}
// 	// [-1 -1 0 0 1 1 2]
// 	triplets := threeSum(nums)
//
// 	fmt.Println(triplets)
// }
