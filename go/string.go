package main

import (
	"fmt"
	"unsafe"
)

func main() {
	s1 := "string"
	s2 := s1
	s3 := s1[3:]
	fmt.Println(&s1, &s2, &s3)

	printAddr := func(sp *string) {
		unsafePtr := unsafe.Pointer(sp)
		ptr := (*uintptr)(unsafePtr)
		fmt.Println(*ptr, *(*string)(unsafe.Pointer(ptr)))
	}

	printAddr(&s1)
	printAddr(&s2)
	printAddr(&s3)
}
