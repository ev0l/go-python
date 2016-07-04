#define Py_LIMITED_API
#include <Python.h>

PyObject * call(PyObject *, PyObject *);

// Workaround missing variadic function support
// https://github.com/golang/go/issues/975
int PyArg_ParseTuple_LL(PyObject * args, long long * a, long long * b) {  
    return PyArg_ParseTuple(args, "LL", a, b);
}

int PyArg_ParseTuple_sOs(PyObject * args, char ** a, PyObject ** b, char ** c) {  
    return PyArg_ParseTuple(args, "sOs", a, b, c);
}

void Py_Inc(PyObject * o){
    Py_INCREF(o);
}

void Py_Dec(PyObject * o){
    Py_DECREF(o);
}

PyObject * Py_BuildValue_s(char * c){
    return Py_BuildValue("(s)", c);
}

static PyMethodDef BridgeMethods[] = {  
    {"call", call, METH_VARARGS, "Threaded Stuff."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef bridgemodule = {  
   PyModuleDef_HEAD_INIT, "bridge", NULL, -1, BridgeMethods
};

PyMODINIT_FUNC  
PyInit_bridge(void)  
{
    PyEval_InitThreads();
    return PyModule_Create(&bridgemodule);
}