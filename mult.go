package main

import "time"
import "encoding/json"
import "fmt"

// #include <Python.h>
import "C"

type twoNum struct {
	NumOne int
	NumTwo int
}

func Test(py Pycall) {
	a := new(twoNum)
	defer PyDone(py)

	_ = json.Unmarshal([]byte(py.json), a)
	fmt.Println(a)
	for i := 0; i < 10000; i++ {
		time.Sleep(1000)
		b, _ := json.Marshal(a.NumOne + a.NumTwo)

		CallBack(py, string(b))
	}

}
