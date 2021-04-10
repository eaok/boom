package main

import (
	"fmt"
)

func main() {
	str := "123"
	//    str[0] = 'a'
	//    []byte(str)[1] = 'b'
	byte1 := []byte(str)
	byte1[1] = 'b'
	fmt.Printf("%v\n", str)
	fmt.Printf("%v %s\n", byte1, byte1)
}
