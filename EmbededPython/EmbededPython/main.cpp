#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <Python.h>
using std::string;
using std::stringstream;
using std::list;

#define PYERR_IF(boolean, body) if(boolean){body}else{PYERR_Print();}

int main(void)
{
	PyObject *pName, *pModule, *pFunc;
	PyObject *pArgs, *pValue;
	string str; // = "This is C string.";
	int i = 22;
	
	list<string> aa;
	list<string>::iterator it;

	for(int i=0; i<3; i++) {
		string bb;
		stringstream dd;
		dd << __DATE__ << " " << __TIME__ << "\n";
		dd << "\t" << "watch: " << "\/watch?" << "\n";
		dd << "\t" << "index: " << i << "\n";
		bb = dd.str();
		aa.push_back(bb);
	}

	Py_Initialize();
	PySys_SetPath(L"");

	for(it = aa.begin(); it != aa.end(); it++) {
		str = *it;
	
		pName = PyUnicode_FromString("test");
		pModule = PyImport_Import(pName);
		Py_DECREF(pName);

		if( pModule != NULL ) {
			pFunc = PyObject_GetAttrString(pModule, "test_print");
			if( pFunc && PyCallable_Check(pFunc) )
			{
				pArgs = PyTuple_New(2);
				pValue = PyUnicode_FromString(str.c_str());
				if( !pValue) {
					Py_DECREF(pArgs);
					Py_DECREF(pModule);
				}
				PyTuple_SetItem(pArgs, 0, pValue);
				pValue = PyLong_FromLong(i);
				if( !pValue) {
					Py_DECREF(pArgs);
					Py_DECREF(pModule);
				}
				PyTuple_SetItem(pArgs, 1, pValue);
		
				PyObject_CallObject(pFunc, pArgs);
				Py_DECREF(pArgs);
			}
			else {
				if( PyErr_Occurred())
					PyErr_Print();
			}

			Py_XDECREF(pFunc);
			Py_DECREF(pModule);
		}
		else {
			PyErr_Print(); 
			system("pause");
			return 1;
		}
	}
	PyErr_Print();
	system("pause");
	return 0;
}