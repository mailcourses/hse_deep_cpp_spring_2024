#include <iostream>
#include <Python.h>

PyObject* cutils_sum(PyObject* self, PyObject* args)
{
    PyObject* list;
    long max_len = 0;
    if (!PyArg_ParseTuple(args, "Ol", &list, &max_len))
    {
        std::cerr << "Failed to parse arguments!" << std::endl;
        return NULL;
    }

    long res = 0;
    long list_len = PyList_Size(list);
    for (int i = 0; i < max_len && i < list_len; ++i)
    {
        PyObject* elem = PyList_GetItem(list, i);
        res += PyLong_AsLong(elem);
    }

    return Py_BuildValue("l", res);
}

long fibonacci(long n)
{
    if (n < 2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

PyObject* cutils_fibonacci(PyObject* self, PyObject* args)
{
    long num = 0;
    if (!PyArg_ParseTuple(args, "l", &num))
    {
        std::cerr << "Failed to parse arguments!" << std::endl;
        return NULL;
    }
    long res = fibonacci(num);
    return Py_BuildValue("l", res);
}

static PyMethodDef cutils_methods[] = {
    {"sum", cutils_sum, METH_VARARGS, "Method for calculating sum of array elements."},
    {"fibonacci", cutils_fibonacci, METH_VARARGS, "Method for calculating n-th element of Fibonacci sequence."},
    {NULL, NULL, 0, NULL}
};

static PyModuleDef cutils_module = {
    PyModuleDef_HEAD_INIT,
    "cutils",
    "Module with different methods",
    -1,
    cutils_methods
};

PyMODINIT_FUNC PyInit_cutils(void) {
    return PyModule_Create(&cutils_module);
}
