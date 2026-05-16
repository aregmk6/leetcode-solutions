// package main

import "fmt"

func searchRange(nums []int, target int) []int {
	retSlice := make([]int, 2, 2)
	retSlice[0], retSlice[1] = -1, -1

	left, right, mid := 0, len(nums)-1, (0+len(nums)-1)/2

	// 4, 5, 6
	// 0, 1, 2
	// l  m  r

	for left <= right {
		mid = (left + right) / 2

		if nums[mid] == target {
			if mid-1 >= 0 && nums[mid-1] == target {
				right = mid - 1
			} else {
				retSlice[0] = mid
				break
			}
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	left, right = 0, len(nums)-1

	for left <= right {
		mid = (left + right) / 2

		if nums[mid] == target {
			if mid+1 < len(nums) && nums[mid+1] == target {
				left = mid + 1
			} else {
				retSlice[1] = mid
				break
			}
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return retSlice
}

// func main() {
// 	nums := []int{5, 7, 7, 8, 8, 10}
//
// 	fmt.Println(searchRange(nums, 8))
// }
