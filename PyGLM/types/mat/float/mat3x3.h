#pragma once

#include "../forward_declarations.h"

static PyMethodDef hfmat3x3_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{"length", (PyCFunction)mat_length<3>, METH_NOARGS, "returns the length of glm::mat3x3"},
	{ "__getstate__", (PyCFunction)mat_to_tuple<3, 3, float>, METH_NOARGS, "Returns a picklable state of this object"},
	{ "__setstate__", (PyCFunction)mat_setstate<3, 3, float>, METH_O, "Restores a state that was previously acquired"},
	{ "to_list", (PyCFunction)mat_to_list<3, 3, float>, METH_NOARGS, "Return the components of this matrix as a nested list"},
	{ "to_tuple", (PyCFunction)mat_to_tuple<3, 3, float>, METH_NOARGS, "Return the components of this matrix as a nested tuple"},
	{ "to_bytes", (PyCFunction)generic_to_bytes, METH_NOARGS, "Create a bytes string from this object"},
	{ "from_bytes", (PyCFunction)mat_from_bytes<3, 3, float>, METH_O | METH_STATIC, "Create a matrix from a bytes string"},
	{ NULL }
};
static PyBufferProcs hfmat3x3BufferMethods = {
	(getbufferproc)mat_getbuffer<3, 3, float>,
	(releasebufferproc)mat_releasebuffer,
};
static PySequenceMethods hfmat3x3SeqMethods = {
	(lenfunc)mat_len<3>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	0, // sq_item
	0,
	0, // sq_ass_item
	0,
	(objobjproc)mat_contains<3, 3, float>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyMappingMethods hfmat3x3MapMethods = {
	(lenfunc)mat_len<3>, // mp_length
	(binaryfunc)mat3x3_mp_item<float>, // mp_subscript
	(objobjargproc)mat3x3_mp_ass_item<float>, // mp_ass_subscript
};
static PyNumberMethods hfmat3x3NumMethods = {
	(binaryfunc)matsq_add<3, 3, float>, //nb_add
	(binaryfunc)matsq_sub<3, 3, float>, //nb_subtract
	(binaryfunc)mat_mul<3, 3, float>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)mat_neg<3, 3, float>, //nb_negative
	(unaryfunc)mat_pos<3, 3, float>, //nb_positive
	0, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float
	(binaryfunc)matsq_iadd<3, 3, float>, //nb_inplace_add
	(binaryfunc)matsq_isub<3, 3, float>, //nb_inplace_subtract
	(binaryfunc)mat_imul<3, 3, float>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)matsq_div<3, 3, float>,
	0, //nb_inplace_floor_divide
	(binaryfunc)matsq_idiv<3, 3, float>, //nb_inplace_true_divide
	0, //nb_index
	(binaryfunc)mat_matmul, //nb_matrix_multiply
	(binaryfunc)mat_imatmul<3, 3, float>, //nb_inplace_matrix_multiply
};
static PyTypeObject hfmat3x3IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"mat3x3Iter",             /* tp_name */
	sizeof(matIter<3, 3, float>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)matIter_dealloc<3, 3, float>, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"mat3x3 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)matIter_next<3, 3, float>,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)matIter_new<3, 3, float>,                 /* tp_new */
};

static PyGLMTypeObject hfmat3x3GLMType = {
	{
		PyObject_HEAD_INIT(NULL)
		"glm.mat3x3",             /* tp_name */
		sizeof(mat<3, 3, float>),             /* tp_basicsize */
		0,                         /* tp_itemsize */
		(destructor)mat_dealloc, /* tp_dealloc */
		0,                         /* tp_print */
		0,                         /* tp_getattr */
		0,                         /* tp_setattr */
		0,                         /* tp_reserved */
		(reprfunc)mat3x3_repr<float>,                         /* tp_repr */
		& hfmat3x3NumMethods,             /* tp_as_number */
		& hfmat3x3SeqMethods,                         /* tp_as_sequence */
		& hfmat3x3MapMethods,                         /* tp_as_mapping */
		(hashfunc)mat_hash<3, 3, float>,                         /* tp_hash  */
		0,                         /* tp_call */
		(reprfunc)mat3x3_str<float>,                         /* tp_str */
		0,                         /* tp_getattro */
		0,                         /* tp_setattro */
		& hfmat3x3BufferMethods,                         /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT |
		Py_TPFLAGS_BASETYPE,   /* tp_flags */
		"mat3x3( <mat3x3 compatible type(s)> )\n3 columns of 3 components matrix of floating-point numbers.",           /* tp_doc */
		0,                         /* tp_traverse */
		0,                         /* tp_clear */
		(richcmpfunc)mat_richcompare<3, 3, float>,                         /* tp_richcompare */
		0,                         /* tp_weaklistoffset */
		(getiterfunc)mat_geniter<3, 3, float>,                         /* tp_iter */
		0,                         /* tp_iternext */
		hfmat3x3_methods,             /* tp_methods */
		0,             /* tp_members */
		0,           			/* tp_getset */
		0,                         /* tp_base */
		0,                         /* tp_dict */
		0,                         /* tp_descr_get */
		0,                         /* tp_descr_set */
		0,                         /* tp_dictoffset */
		(initproc)mat3x3_init<float>,      /* tp_init */
		0,                         /* tp_alloc */
		(newfunc)mat_new<3, 3, float>,                 /* tp_new */
	},
	PyGLM_TYPE_MAT,
	3,
	3,
	sizeof(float),
	sizeof(glm::mat<3, 3, float>),
	PyGLM_FS_FLOAT
};

static PyTypeObject& hfmat3x3Type = *((PyTypeObject*)&hfmat3x3GLMType);