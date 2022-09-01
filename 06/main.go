package main

import (
    "fmt"
    "math"
    "os"
    "sort"
    "strconv"
    "strings"
)

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func main() {
    file, err := os.ReadFile(os.Args[1])
    if err != nil {
        fmt.Println(err)
        os.Exit(1)
    }

    var input = strings.Split(string(file), ",")
    var numbers = make([]int, 0, len(input)) // Set capacity
    var sum int = 0
    var max int = 0

    // Cast input values to integers
    for _, value := range input {
        i, err := strconv.Atoi(strings.Trim(value, "\n"))
        if err != nil {
            fmt.Println(err)
        }
        numbers = append(numbers, i)
        if max < i {
            max = i
        }
        sum += i
    }

    // Find out median
    sort.Ints(numbers)
    median := numbers[len(numbers)/2]

    var price = 0
    for _, number := range numbers {
        diff := number - median
        if diff < 0 {
            diff = -1 * diff
        }
        price += diff
    }
    fmt.Printf("part one: %d\n", price)

    // Part two
    var avgLower int = int(math.Floor(float64(sum) / float64(len(numbers))))
    var avgUpper int = int(math.Ceil(float64(sum) / float64(len(numbers))))

    price = 0
    for _, number := range numbers {
        diff1 := number - avgLower
        if diff1 < 0 {
            diff1 = -1 * diff1
        }

        diff2 := number - avgUpper
        if diff2 < 0 {
            diff2 = -1 * diff2
        }

        var diff = min(diff1, diff2)

        price += diff * (diff + 1) / 2
    }
    fmt.Printf("part two: %d\n", price)
}
