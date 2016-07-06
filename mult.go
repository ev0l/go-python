package main

import "time"
import "encoding/json"

// #include <Python.h>
import "C"

type twoNum struct {
	NumOne int
	NumTwo int
}

type result struct {
	Answer int
	Times  int
}

func Test(py Pycall) {
	a := new(twoNum)
	i := 1
	_ = i
	defer PyDone(py)

	_ = json.Unmarshal([]byte(py.json), a)
	for i := 0; i < 10000; i++ {
		time.Sleep(time.Second * 2)
		answer := (a.NumOne + a.NumTwo) * i
		b, _ := json.Marshal(&result{Answer: answer, Times: i})
		i = i + 1
		CallBack(py, string(b))
	}

}
