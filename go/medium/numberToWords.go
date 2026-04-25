import (
	"fmt"
	"strings"
)

// outer rec
var postfix = [...]string{"", "Thousand ", "Million ", "Billion "}

// inner rec
var teens = [...]string{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}

var tens = [...]string{"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}

var ones = [...]string{"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"}

var str strings.Builder

var innerCount int

func getNum(num int, group []string, postfix string) string {
	var b strings.Builder
	offset := (10 - len(group))
	b.WriteString(group[num-offset])
	b.WriteString(" ")
	b.WriteString(postfix)
	return b.String()
}

func innerRec(num int, pos int) string {
	if num == 0 {
		return ""
	}
	numStr := innerRec(num/10, pos+1)
	if numStr != "s" {
		str.WriteString(numStr)
	}
	curNum := num % 10
	switch pos {
	case 0:
		if numStr == "s" {
			return getNum(curNum, teens[:], "")
		} else {
			switch curNum {
			case 0:
				innerCount++
				return ""
			default:
				return getNum(curNum, ones[:], "")
			}
		}
	case 1:
		switch curNum {
		case 0:
			innerCount++
			return ""
		case 1:
			return "s"
		default:
			return getNum(curNum, tens[:], "")
		}
	case 2:
		switch curNum {
		case 0:
			innerCount++
			return ""
		default:
			return getNum(curNum, ones[:], "Hundred ")
		}
	}
	return ""
}

func outerRec(num int, innerPos int, outerPos int) string {
	if num == 0 {
		return ""
	}
	str.WriteString(outerRec(num/1000, innerPos, outerPos+1))
	innerStr := innerRec(num, innerPos)
	str.WriteString(innerStr)

	var retStr string
	if innerCount == 3 {
		retStr = ""
	} else {
		retStr = postfix[outerPos]
	}

	innerCount = 0

	return retStr
}

func numberToWords(num int) string {
	if num == 0 {
		return "Zero"
	}
	str.Reset()
	str.WriteString(outerRec(num, 0, 0))
	return str.String()[:len(str.String())-1]
}

