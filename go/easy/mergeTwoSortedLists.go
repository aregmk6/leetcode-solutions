package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	var prev1 *ListNode
	cur1 := list1
	cur2 := list2

	retList := list1

	for cur1 != nil && cur2 != nil {
		if cur1.Val < cur2.Val {
			prev1 = cur1
			cur1 = cur1.Next
		} else {
			target := cur2
			cur2 = cur2.Next
			if prev1 != nil {
				target.Next = cur1
				prev1.Next = target
				prev1 = target
			} else {
				target.Next = cur1
				prev1 = target
				retList = target
			}
		}
	}

	if cur2 != nil {
		if prev1 != nil {
			prev1.Next = cur2
		} else {
			retList = cur2
		}
	}

	return retList
}

func main() {
	n6 := ListNode{Val: 7, Next: nil}
	n5 := ListNode{Val: 5, Next: &n6}
	n4 := ListNode{Val: 2, Next: &n5} // head 2

	n3 := ListNode{Val: 6, Next: nil}
	n2 := ListNode{Val: 3, Next: &n3}
	n1 := ListNode{Val: 1, Next: &n2} // head 1

	merged := mergeTwoLists(&n1, &n4)

	cur := merged
	for cur != nil {
		fmt.Println(cur.Val)
		cur = cur.Next
	}
}
