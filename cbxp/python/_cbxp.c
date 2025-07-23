#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include <stdbool.h>

#define BUFFER_SIZE = 100000

#include "cbxp.h"

// Entry point to the call_cbxp() function
static PyObject* call_cbxp(PyObject* self, PyObject* args, PyObject* kwargs) {
  PyObject* result_dictionary;
  PyObject* debug_pyobj;
  const char* request_as_string;
  bool debug            = false;

  static char* kwlist[] = {"request", "debug", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s|O", kwlist,
                                   &request_as_string, &debug_pyobj)) {
    return NULL;
  }

  debug = PyObject_IsTrue(debug_pyobj);

  char * result_json = static_cast<char *>(calloc(BUFFER_SIZE, sizeof(char)));;

  cbxp(&result, request_as_string, debug);

  result_dictionary = Py_BuildValue(
      "{s:s}", "result_json", result_json);

  free(result_json);

  return result_dictionary;
}

// Method definition
static PyMethodDef _C_methods[] = {
    {"call_racfu", (PyCFunction)call_racfu, METH_VARARGS | METH_KEYWORDS,
     "Python interface to z/OS Control Blocks"},
    {NULL}
};

// Module definition
static struct PyModuleDef _C_module_def = {
    PyModuleDef_HEAD_INIT, "_C", "Python interface to z/OS Control Blocks",
    -1, _C_methods};

// Module initialization function
PyMODINIT_FUNC PyInit__C(void) {
  Py_Initialize();
  return PyModule_Create(&_C_module_def);
}
