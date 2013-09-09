//*****************************************************************//
//    Albany 2.0:  Copyright 2012 Sandia Corporation               //
//    This Software is released under the BSD license detailed     //
//    in the file "license.txt" in the top-level Albany directory  //
//*****************************************************************//
#ifndef AADAPT_ADAPTIVEMODELFACTORY_HPP
#define AADAPT_ADAPTIVEMODELFACTORY_HPP

#include "EpetraExt_ModelEvaluator.h"
#include "Thyra_EpetraModelEvaluator.hpp"
#include "Thyra_LinearOpWithSolveFactoryBase.hpp"

#include "Teuchos_RCP.hpp"
#include "Teuchos_ParameterList.hpp"

class Epetra_MultiVector;
class Epetra_Map;

namespace AAdapt {

class AdaptiveModelFactory {
  public:
    AdaptiveModelFactory(
      const Teuchos::RCP<Teuchos::ParameterList>& parentParams);

    Teuchos::RCP<Thyra::ModelEvaluator<double> > create(const Teuchos::RCP<EpetraExt::ModelEvaluator>& epetraModel,
         const Teuchos::RCP<Thyra::LinearOpWithSolveFactoryBase<double> > &W_factory);

    // Returns a weak pointer to the Thyra model
    Teuchos::RCP<Thyra::ModelEvaluator<double> > 
       getThyraModel(){ return thyra_model; }

  private:

    Teuchos::RCP<Teuchos::ParameterList> params;

    Teuchos::RCP<Teuchos::ParameterList> 
    extractAdaptiveModelParams(const Teuchos::RCP<Teuchos::ParameterList>& source);

    bool useAdaptiveModel() const;

    //! The adaptive thyra model built by the factory
    Teuchos::RCP<Thyra::ModelEvaluator<double> > thyra_model;

    // Disallow copy & assignment
    AdaptiveModelFactory(const AdaptiveModelFactory&);
    AdaptiveModelFactory& operator=(const AdaptiveModelFactory&);
};

} // namespace AAdapt

#endif /* ALBANY_ADAPTIVEMODELFACTORY_HPP */
