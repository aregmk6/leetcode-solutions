// package main

import (
	"fmt"
	"sync"
)

type Foo struct {
	m  sync.Mutex
	c  *sync.Cond
	wg sync.WaitGroup

	first  bool
	second bool
	third  bool
}

func NewFoo() *Foo {
	f := Foo{}
	f.c = sync.NewCond(&f.m)

	return &f
}

func (f *Foo) First(printFirst func()) {
	defer f.wg.Done()

	// Do not change this line
	printFirst()

	f.m.Lock()

	f.first = true

	f.c.Broadcast()

	f.m.Unlock()
}

func (f *Foo) Second(printSecond func()) {
	defer f.wg.Done()

	f.m.Lock()

	for !f.first {
		f.c.Wait()
	}

	/// Do not change this line
	printSecond()

	f.second = true

	f.c.Broadcast()

	f.m.Unlock()
}

func (f *Foo) Third(printThird func()) {
	defer f.wg.Done()

	f.m.Lock()

	for !f.first || !f.second {
		f.c.Wait()
	}

	// Do not change this line
	printThird()

	f.third = true

	f.c.Broadcast()

	f.m.Unlock()
}

// func main() {
// 	const threadNum int = 3
// 	var f *Foo = NewFoo()
// 	f.wg.Add(threadNum)
// 	for i := range threadNum {
// 		switch i {
// 		case 0:
// 			go f.First(func() { fmt.Println("first") })
// 		case 1:
// 			go f.Second(func() { fmt.Println("second") })
// 		case 2:
// 			go f.Third(func() { fmt.Println("third") })
// 		}
// 	}
// 	f.wg.Wait()
// }
