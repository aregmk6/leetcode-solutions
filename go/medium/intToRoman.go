import (
	"fmt"
	"math"
	"strings"
)

var iToR = map[int]string{
	1:    "I",
	4:    "IV",
	5:    "V",
	9:    "IX",
	10:   "X",
	40:   "XL",
	50:   "L",
	90:   "XC",
	100:  "C",
	400:  "CD",
	500:  "D",
	900:  "CM",
	1000: "M",
}

var str strings.Builder

func writeNum(romanNum string, repeat int, prefix string) string {
	var romanStr strings.Builder
	romanStr.WriteString(prefix)
	for range repeat {
		romanStr.WriteString(romanNum)
	}

	return romanStr.String()
}

func rec(num int, pos int) string {
	if num == 0 {
		return ""
	}
	str.WriteString(rec(num/10, pos+1))
	curSize := int(math.Pow10(pos))
	curNum := num % 10
	var realNum int
	switch curNum {
	case 4:
		realNum = 4 * curSize
		return iToR[realNum]
	case 9:
		realNum = 9 * curSize
		return iToR[realNum]
	default:
		if curNum*curSize-5*curSize < 0 {
			return writeNum(iToR[1*curSize], curNum, "")
		} else {
			return writeNum(iToR[1*curSize], curNum-5, iToR[5*curSize])
		}
	}
}

func intToRoman(num int) string {
	str.Reset()
	str.WriteString(rec(num, 0))
	return str.String()
}

func main() {
	fmt.Println(intToRoman(3749))
}
