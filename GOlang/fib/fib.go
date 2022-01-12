package main

import (
	"fmt"
)

/*
func fib(x int) int {

	if x == 0 {
		return 0
	}
	if x == 1 || x == 2 {
		return 1
	}
	return fib(x-1) + fib(x-2)
}
*/

func fib(x int, memo map[int]int) int {

	if x == 0 {
		return 0
	}
	if x <= 2 {
		return 1
	}
	_, ok := memo[x]
	if !ok {
		memo[x] = fib(x-1, memo) + fib(x-2, memo)
	}
	return memo[x]
}

func main() {

	memo := make(map[int]int)
	fmt.Println(fib(50, memo)) //12586269025

	//fmt.Println(fib(50))
}
