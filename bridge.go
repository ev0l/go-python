package main

// #cgo pkg-config: python3
// #define Py_LIMITED_API
// #include <Python.h>
// int PyArg_ParseTuple_LL(PyObject *, long long *, long long *);
// int PyArg_ParseTuple_sOs(PyObject * args, char ** a, PyObject ** b, char ** c);
// void Py_Inc(PyObject *);
// void Py_Dec(PyObject *);
// PyObject * Py_BuildValue_s(char * c);
import "C"

type Pycall struct {
	funcname *C.char
	callback *C.PyObject
	json     string
}

//export call
func call(self, args *C.PyObject) *C.PyObject {
	var funcname *C.char
	var callback *C.PyObject
	var json *C.char

	if C.PyArg_ParseTuple_sOs(args, &funcname, &callback, &json) == 0 {
		return nil
	}

	//MEMROY LEAK. WHERE DO I DEINCREMENT THIS?
	if callback != nil {
		C.Py_Inc(callback)
	}

	call := Pycall{funcname: funcname, callback: callback, json: C.GoString(json)}
	go Test(call)

	return C.PyLong_FromLongLong(1)
}

func CallBack(py Pycall, json string) {

	var arglist *C.PyObject
	//var result *C.PyObject

	var gstate C.PyGILState_STATE

	gstate = C.PyGILState_Ensure()

	/* Time to call the callback */
	arglist = C.Py_BuildValue_s(C.CString(json))
	_ = C.PyObject_CallObject(py.callback, arglist)
	C.Py_Dec(arglist)
	C.PyGILState_Release(gstate)
}

func PyDone(py Pycall) {

	var gstate C.PyGILState_STATE
	gstate = C.PyGILState_Ensure()
	C.Py_Dec(py.callback)
	C.PyGILState_Release(gstate)

}

//export sum
func sum(self, args *C.PyObject) *C.PyObject {
	var a, b C.longlong
	if C.PyArg_ParseTuple_LL(args, &a, &b) == 0 {
		return nil
	}
	return C.PyLong_FromLongLong(a + b)
}

func main() {}
