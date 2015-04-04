package main

/*
Solution for Easy Challenge #004
Author: Keydrain
Date: 03/30/15

Note: Includes extra credit for variable input lengths and loops.
*/

import (
	"bufio"     // Input and Output tools
	"fmt"       // Printing tools
	"math/rand" // For random things
	"os"        // OS tools
	"strconv"   // String conversion tools
	"strings"   // For string manipulation
	"time"      // Time info
)

func main() {

	// Space and prep reader
	fmt.Print("\n")
	reader := bufio.NewReader(os.Stdin)

	// Get the number of passwords and check input type
	fmt.Print("Number of passwords to generate: ")
	input1, _ := reader.ReadString('\n')
	input1 = strings.TrimRight(input1, "\n")
	number, err := strconv.Atoi(input1)
	if err != nil {
		fmt.Println(err)
		os.Exit(2)
	}

	// Get the number of characters each password should have and check input
	fmt.Print("Password length: ")
	input2, _ := reader.ReadString('\n')
	input2 = strings.TrimRight(input2, "\n")
	length, err := strconv.Atoi(input2)
	if err != nil {
		fmt.Println(err)
		os.Exit(2)
	}

	// Generate random number in range of normal ascii chars and append to out string
	for i := 0; i < number; i++ {
		ans := ""
		for j := 0; j < length; j++ {
			var r *rand.Rand
			r = rand.New(rand.NewSource(time.Now().UTC().UnixNano()))
			randChar := r.Intn(127-33) + 33
			ans = ans + string(randChar)
		}
		fmt.Println(ans)
	}
}
