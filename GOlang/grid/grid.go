package main

import "fmt"

//In a (w x h)Grid, grid() function calculates how many paths is there to pass the Grid from position 0,0 to (w-1,h-1)
func grid(w, h int) int {

	if w == 1 || h == 1 {
		return 1
	}

	return grid(w-1, h) + grid(w, h-1)
}

//In a (w x h)Grid, dGrid() function returns same result as grid() function but faster thanks to dynamic programming method
func dGrid(w, h int, memo map[string]int) int {

	if w == 1 || h == 1 {
		return 1
	}

	str := fmt.Sprintf("%d, %d", w, h)
	_, ok := memo[str]

	if !ok {
		memo[str] = dGrid(w-1, h, memo) + dGrid(w, h-1, memo)
	}

	return memo[str]
}

func main() {
	/*
		fmt.Printf("grid(1,2) = %d\n", grid(1, 2))   // 3
		fmt.Printf("grid(3,2) = %d\n", grid(3, 2))   // 3
		fmt.Printf("grid(2,3) = %d\n", grid(2, 3))   // 3
		fmt.Printf("grid(3,3) = %d\n", grid(3, 3))   // 6
		fmt.Printf("grid(18,18) = %d\n", grid(18, 18)) // 2333606220
	*/
	var memo = make(map[string]int)
	fmt.Printf("dGrid(1,2) = %d\n", dGrid(1, 2, memo))     // 3
	fmt.Printf("dGrid(3,2) = %d\n", dGrid(3, 2, memo))     // 3
	fmt.Printf("dGrid(2,3) = %d\n", dGrid(2, 3, memo))     // 3
	fmt.Printf("dGrid(3,3) = %d\n", dGrid(3, 3, memo))     // 6
	fmt.Printf("dGrid(18,18) = %d\n", dGrid(18, 18, memo)) // 2333606220
	fmt.Printf("grid(18,18) = %d\n", grid(18, 18))         // 2333606220

}
