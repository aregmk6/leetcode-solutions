package main

type car interface {
	drive() int
}

type lambo struct {
	color string
}

func (l lambo) drive() int {
	return 10
}

// func (l *lambo) drive() int {
// 	return 10
// }

func driveTheCar(c car) {
	c.drive()
}

func main() {
	lmb := lambo{}
	driveTheCar(lmb)
}
