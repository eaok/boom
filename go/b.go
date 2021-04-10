package main

import (
	"fmt"
	"unsafe"
)

func main() {
	a := 4
	fmt.Printf("%T\n", a)
	fmt.Println(unsafe.Sizeof(a))
}
