// package main

import (
	"fmt"
)

func sumStrings(num1 []byte, num2 []byte) []byte {
	carry := 0
	var longer []byte
	var shorter []byte
	if len(num1) > len(num2) {
		longer = num1
		shorter = num2
	} else {
		longer = num2
		shorter = num1
	}

	sum := make([]byte, 0, len(longer)+1)
	innerSum := 0
	for i, j := 0, 0; i < len(longer); i, j = i+1, j+1 {
		if j < len(shorter) {
			innerSum = carry + (int(longer[i]) - int('0')) + (int(shorter[j]) - int('0'))
		} else {
			innerSum = carry + (int(longer[i]) - int('0'))
		}
		appendy := innerSum % 10
		sum = append(sum, (byte(appendy + int('0'))))
		carry = innerSum / 10
	}

	if carry != 0 {
		sum = append(sum, byte(carry+int('0')))
	}

	return sum
}

func initResult(num1 string, num2 string) []byte {
	result := make([]byte, 0)
	carry := 0

	if len(num1) > len(num2) {
		num1, num2 = num2, num1
	}

	idx := len(num1) - 1
	for j := len(num2) - 1; j >= 0; j-- {
		prod := carry + (int(num2[j])-int('0'))*(int(num1[idx])-int('0'))
		appendy := prod % 10
		carry = prod / 10

		result = append(result, byte(appendy+int('0')))
	}

	if carry != 0 {
		result = append(result, byte(carry+int('0')))
	}

	return result
}

func flipSlice(s []byte) {
	for left, right := 0, len(s)-1; left < right; left, right = left+1, right-1 {
		s[left], s[right] = s[right], s[left]
	}
}

func createShift(sh int) []byte {
	const value = '0'

	if sh == 0 {
		return []byte{}
	}

	shift := make([]byte, sh)
	shift[0] = value

	for i := 1; i < len(shift); i *= 2 {
		copy(shift[i:], shift[:i])
	}

	return shift
}

func isZero(num string) bool {
	if len(num) == 1 && byte(num[0]) == '0' {
		return true
	}
	return false
}

func multiply(num1 string, num2 string) string {

	if isZero(num1) || isZero(num2) {
		return "0"
	}

	input := make([]byte, 0)
	result := initResult(num1, num2)

	if len(num1) > len(num2) {
		num1, num2 = num2, num1
	}
	for sh, i := 1, len(num1)-2; i >= 0; sh, i = sh+1, i-1 {
		carry := 0
		input = append(input, createShift(sh)...)

		for j := len(num2) - 1; j >= 0; j-- {
			prod := carry + (int(num2[j])-int('0'))*(int(num1[i])-int('0'))
			appendy := prod % 10
			carry = prod / 10

			input = append(input, byte(appendy+int('0')))
		}

		if carry != 0 {
			input = append(input, byte(carry+int('0')))
		}

		result = sumStrings(input, result)

		input = nil

	}

	flipSlice(result)
	return string(result)
}

// func main() {
// 	res := multiply("999", "999")
// 	fmt.Println(res)
// }
