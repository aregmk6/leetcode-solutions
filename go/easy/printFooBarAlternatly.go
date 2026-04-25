package main

import (
	"fmt"
	"sync"
)

type FooBar struct {
	allowFoo chan struct{}
	allowBar chan struct{}
	gr       sync.WaitGroup
	n        int
}

func NewFooBar(n int) *FooBar {
	f := FooBar{
		n:        n,
		allowFoo: make(chan struct{}),
		allowBar: make(chan struct{}),
	}
	return &f
}

func (fb *FooBar) Foo(printFoo func()) {
	defer fb.gr.Done()

	for i := 0; i < fb.n; i++ {
		<-fb.allowFoo

		// printFoo() outputs "foo". Do not change or remove this line.
		printFoo()

		fb.allowBar <- struct{}{}
	}
}

func (fb *FooBar) Bar(printBar func()) {
	defer fb.gr.Done()
	for i := 0; i < fb.n; i++ {
		fb.allowFoo <- struct{}{}
		<-fb.allowBar

		// printBar() outputs "bar". Do not change or remove this line.
		printBar()
	}
}

// func main() {
// 	const threadNum int = 2
// 	fb := NewFooBar(3)
//
// 	fb.gr.Add(threadNum)
//
// 	for i := range threadNum {
// 		switch i {
// 		case 0:
// 			go fb.Foo(func() { fmt.Println("Foo") })
// 		case 1:
// 			go fb.Bar(func() { fmt.Println("Bar") })
// 		}
// 	}
//
// 	fb.gr.Wait()
//
// }
