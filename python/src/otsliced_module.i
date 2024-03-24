// SWIG file otsliced_module.i

%module(docstring="otsliced module") otsliced

%{
#include <openturns/OT.hxx>
#include <openturns/PythonWrappingFunctions.hxx>
%}

// Prerequisites needed
%include typemaps.i
%include exception.i
%ignore *::load(OT::Advocate & adv);
%ignore *::save(OT::Advocate & adv) const;

%import base_module.i
%import uncertainty_module.i

// The new classes
%include otsliced/otslicedprivate.hxx
%include SlicedInverseRegressionResult.i
%include SlicedInverseRegression.i


