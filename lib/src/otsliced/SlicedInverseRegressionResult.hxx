//                                               -*- C++ -*-
/**
 *  @brief SlicedInverseRegressionResult
 *
 *  Copyright 2005-2024 Airbus-EDF-IMACS-ONERA-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OTSLICED_SLICEDINVERSEREGRESSIONRESULT_HXX
#define OTSLICED_SLICEDINVERSEREGRESSIONRESULT_HXX

#include "otsliced/otslicedprivate.hxx"

#include <openturns/PersistentObject.hxx>
#include <openturns/StorageManager.hxx>
#include <openturns/Function.hxx>

namespace OTSLICED
{

/**
 * @class SlicedInverseRegressionResult
 *
 * Result from SIR algorithm 
 */
class OTSLICED_API SlicedInverseRegressionResult
  : public OT::PersistentObject
{
  CLASSNAME

public:
  /** Default constructor */
  SlicedInverseRegressionResult();

  SlicedInverseRegressionResult(const OT::Matrix & linear,
                                const OT::Point & center,
                                const OT::Point & eigenValues);

  /** Virtual constructor method */
  SlicedInverseRegressionResult * clone() const override;

  OT::Matrix getDirections() const;
  OT::Point getEigenvalues() const;
  
  OT::Function getTransformation() const;
  OT::Function getInverseTransformation() const;

  /** String converter */
  OT::String __repr__() const override;

  /** Method save() stores the object through the StorageManager */
  void save(OT::Advocate & adv) const override;

  /** Method load() reloads the object from the StorageManager */
  void load(OT::Advocate & adv) override;

private:
  OT::Matrix directions_;
  OT::Point center_;
  OT::Point eigenValues_;

}; /* class SlicedInverseRegressionResult */

} /* namespace OTSLICED */

#endif /* OTSLICED_SLICEDINVERSEREGRESSIONRESULT_HXX */
