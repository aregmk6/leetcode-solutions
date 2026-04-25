// package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

//       1 -> 2 -> 3 -> 4
//       f    s

//       2 -> 3 -> 4
//       1 ->
//      f s

//       2 -> 1 -> 3 -> 4
//       s    f

func swap(first *ListNode, second *ListNode, nextPair *ListNode, prev *ListNode) {
	first.Next = nextPair
	second.Next = first
	if prev != nil {
		prev.Next = second
	}
}

func swapPairs(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return head
	}

	var prev *ListNode
	first := head
	second := head.Next
	nextPair := second.Next

	newHead := second

	for {

		swap(first, second, nextPair, prev)

		if nextPair == nil {
			break
		}

		prev = first
		first = nextPair
		second = first.Next

		if second == nil {
			break
		}

		nextPair = second.Next
	}

	return newHead
}

// func main() {
// 	n6 := ListNode{Val: 7, Next: nil}
// 	n5 := ListNode{Val: 5, Next: &n6}
// 	n4 := ListNode{Val: 2, Next: &n5}
// 	n3 := ListNode{Val: 6, Next: &n4}
// 	n2 := ListNode{Val: 3, Next: &n3}
// 	n1 := ListNode{Val: 1, Next: &n2}
//
// 	cur := &n1
// 	for cur != nil {
// 		fmt.Printf("%d ", cur.Val)
// 		cur = cur.Next
// 	}
// 	fmt.Printf("\n")
//
// 	swapped := swapPairs(&n1)
//
// 	cur = swapped
// 	for cur != nil {
// 		fmt.Printf("%d ", cur.Val)
// 		cur = cur.Next
// 	}
// 	fmt.Printf("\n")
// }
