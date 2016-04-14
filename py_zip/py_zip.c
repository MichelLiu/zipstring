#include <Python.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "zip.h"

static PyObject* py_zip_to_string(PyObject* self, PyObject* args);

static PyMethodDef py_zip_methods[] = {
    {"zip_to_string", py_zip_to_string, METH_VARARGS | METH_KEYWORDS, "pack zip string"},
    {NULL, NULL, 0, NULL}
};

PyDoc_STRVAR(module_doc, "unpack gzip for Python.");

PyMODINIT_FUNC initpy_zip(void)
{
    PyObject* m;
    m = Py_InitModule3("py_zip", py_zip_methods, module_doc);

    PyModule_AddStringConstant(m, "__version__", "0.1");
}


static PyObject* py_zip_to_string(PyObject* self, PyObject* args)
{
    char **pBuf;
    size_t size = 0;
    char c = '\0';
    char *t;
    t = &c;
    pBuf = &t;

    struct zip_t *zip = zip_open(ZIP_DEFAULT_COMPRESSION_LEVEL, 0);
    // we should check if zip is NULL
    if(zip)
    {
        PyObject *dict = NULL;
        PyObject *pKey = NULL, *pValue = NULL;
        Py_ssize_t pos = 0;

        if (!PyArg_ParseTuple(args, "O", &dict))
        {
            return NULL;
        }

        while (PyDict_Next(dict, &pos, &pKey, &pValue)) {
            Py_ssize_t lenvalue = 0;
            char *key = NULL, *value = NULL;
            key = PyString_AsString(pKey);
            PyString_AsStringAndSize(pValue, &value, &lenvalue);
            printf("key:%s\n", key);
            printf("value:%s\n", value);

            zip_entry_open(zip, key);
            {
                zip_entry_write(zip, value, lenvalue*sizeof(char));
            }
            zip_entry_close(zip);
        }
        zip_close(zip, (void**)pBuf, &size);
    }

    PyObject* ret = PyString_FromStringAndSize(*pBuf, size);
    free(*pBuf);
    *pBuf=NULL;
    return ret;
}
