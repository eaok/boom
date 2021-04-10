package main

import (
	"fmt"
	"time"
)

func main() {
	m := map[string]int{
		"a": 1,
		"b": 2,
		"c": 3,
	}
	for k, v := range m {
		go func(kk *string, vv *int) {
			fmt.Printf(" %v , %v \n", *kk, *vv)
		}(&k, &v)
	}
	time.Sleep(1 * time.Second)
}
