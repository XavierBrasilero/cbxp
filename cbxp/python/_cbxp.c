#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFFER_SIZE 100000

#include "cbxp.h"

// Entry point to the call_cbxp() function
static PyObject* call_cbxp(PyObject* self, PyObject* args, PyObject* kwargs) {
  PyObject* result_dictionary;
  PyObject* debug_pyobj;
  const char* request_as_string;
  Py_ssize_t request_length;
  bool debug            = false;
  int rc;

  static char* kwlist[] = {"request", "debug", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s#|O", kwlist,
                                   &request_as_string, &request_length, &debug_pyobj)) {
    return NULL;
  }

  debug             = PyObject_IsTrue(debug_pyobj);

  char* result_json = (char*)calloc(BUFFER_SIZE, sizeof(char));

  rc = cbxp(result_json, request_as_string, request_length, debug);

  result_dictionary = Py_BuildValue("{s:s, s:i}", "result_json", result_json, "return_code", rc);

  free(result_json);

  return result_dictionary;
}

// Method definition
static PyMethodDef _C_methods[] = {
    {"call_cbxp", (PyCFunction)call_cbxp, METH_VARARGS | METH_KEYWORDS,
     "Python interface to z/OS Control Block Explorer"},
    {NULL}
};

// Module definition
static struct PyModuleDef _C_module_def = {
    PyModuleDef_HEAD_INIT, "_C", "Python interface to z/OS Control Block Explorer", -1,
    _C_methods};

// Module initialization function
PyMODINIT_FUNC PyInit__C(void) {
  Py_Initialize();
  return PyModule_Create(&_C_module_def);
}
