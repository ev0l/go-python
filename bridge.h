/* Created by "go tool cgo" - DO NOT EDIT. */

/* package _/vagrant */

/* Start of preamble from import "C" comments.  */


#line 3 "/vagrant/bridge.go"

 #define Py_LIMITED_API
 #include <Python.h>
 int PyArg_ParseTuple_LL(PyObject *, long long *, long long *);
 int PyArg_ParseTuple_sOs(PyObject * args, char ** a, PyObject ** b, char ** c);
 void Py_Inc(PyObject *);
 void Py_Dec(PyObject *);
 PyObject * Py_BuildValue_s(char * c);



/* End of preamble from import "C" comments.  */


/* Start of boilerplate cgo prologue.  */

#ifndef GO_CGO_PROLOGUE_H
#define GO_CGO_PROLOGUE_H

typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef unsigned long long GoUint64;
typedef GoInt64 GoInt;
typedef GoUint64 GoUint;
typedef __SIZE_TYPE__ GoUintptr;
typedef float GoFloat32;
typedef double GoFloat64;
typedef float _Complex GoComplex64;
typedef double _Complex GoComplex128;

/*
  static assertion to make sure the file is being used on architecture
  at least with matching size of GoInt.
*/
typedef char _check_for_64_bit_pointer_matching_GoInt[sizeof(void*)==64/8 ? 1:-1];

typedef struct { const char *p; GoInt n; } GoString;
typedef void *GoMap;
typedef void *GoChan;
typedef struct { void *t; void *v; } GoInterface;
typedef struct { void *data; GoInt len; GoInt cap; } GoSlice;

#endif

/* End of boilerplate cgo prologue.  */

#ifdef __cplusplus
extern "C" {
#endif


extern PyObject* call(PyObject* p0, PyObject* p1);

extern PyObject* sum(PyObject* p0, PyObject* p1);

#ifdef __cplusplus
}
#endif
