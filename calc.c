#include <Python.h>

static PyObject* hex2dec(PyObject* self, PyObject* args)
{
    const char* s;
    if (!PyArg_ParseTuple(args, "s", &s)) {
        return NULL;
    }
    unsigned long ret;
    ret = strtoul(s, NULL, 16);
    return Py_BuildValue("i", ret);
}

static PyObject* hex2decs(PyObject* self, PyObject* args)
{
    /*
    const char* s;
    // TODO
    if (!PyArg_ParseTuple(args, "s", &s)) {
        return NULL;
    }
    volatile unsigned long ret;
    char tmp[3];
    int n = 0;
    while(*(s + n) != '\0') {
        tmp[0] = *(s + n++);
        tmp[1] = *(s + n++);
        ret = strtoul(tmp, NULL, 16);
    }
    return Py_BuildValue("i", ret);
    */

    const char* s;
    int n;
    if (!PyArg_ParseTuple(args, "si", &s, &n)) {
        return NULL;
    }
    PyListObject *ret;
    ret = (PyListObject *) PyList_New(n);

    unsigned long dec;
    char tmp[3];
    int i = 0;
    int m = 0;
    while(*(s + i) != '\0') {
        tmp[0] = *(s + i++);
        tmp[1] = *(s + i++);
        dec = strtoul(tmp, NULL, 16);
        PyList_SetItem(ret, m++, Py_BuildValue("i", (int)dec));
    }
    return Py_BuildValue("O", ret);
}

static PyMethodDef methods[] = {
    {"hex2dec", hex2dec, METH_VARARGS, "convert hexadecimal string to decimal number\n"},
    {"hex2decs", hex2decs, METH_VARARGS, "convert hexadecimal string to decimal numbers\n"},
    {NULL, NULL, 0, NULL}
};

void initcalc(void)
{
    Py_InitModule3("calc", methods, "C extention calculation module\n");
}
