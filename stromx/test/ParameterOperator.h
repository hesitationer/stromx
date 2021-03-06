/* 
*  Copyright 2012 Matthias Fuchs
*
*  This file is part of stromx-studio.
*
*  Stromx-studio is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  Stromx-studio is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with stromx-studio.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef STROMX_TEST_PARAMETEROPERATOR_H
#define STROMX_TEST_PARAMETEROPERATOR_H

#include <stromx/runtime/OperatorKernel.h>
#include <stromx/runtime/Primitive.h>
#include <stromx/cvsupport/Matrix.h>

#include "stromx/test/Config.h"

namespace stromx
{
    namespace test
    {
        class STROMX_TEST_API ParameterOperator : public stromx::runtime::OperatorKernel
        {
        public:
            enum DataId 
            { 
                INPUT_1, 
                INPUT_2,
                OUTPUT_1, 
                OUTPUT_2,
                INITIALIZE_PARAM,
                PARAM_GROUP_1,
                PARAM_GROUP_2,
                INT_PARAM,
                ENUM_PARAM,
                BOOL_PARAM,
                MATRIX_PARAM,
                INT_MATRIX_PARAM,
                TRIGGER_VALUE_PARAM,
                TRIGGER_PARAM,
                PUSH_PARAM,
                PULL_PARAM
            };
            
            ParameterOperator();
            
            virtual OperatorKernel* clone() const { return new ParameterOperator; }
            virtual void setParameter(const unsigned int id, const stromx::runtime::Data& value);
            const stromx::runtime::DataRef getParameter(const unsigned int id) const;
            virtual void execute(stromx::runtime::DataProvider& provider);
            virtual void initialize();
            
        private:
            static const std::vector<const runtime::Input*> setupInputs();
            static const std::vector<const runtime::Output*> setupOutputs();
            static const std::vector<const stromx::runtime::Parameter*> setupInitParameters();
            static const std::vector<const stromx::runtime::Parameter*> setupParameters();
            
            static const std::string TYPE;
            static const std::string PACKAGE;
            static const stromx::runtime::Version VERSION;
            
            stromx::runtime::UInt32 m_initializeParam;
            stromx::runtime::Int32 m_intParam;
            stromx::runtime::Enum m_enumParam;
            stromx::runtime::Bool m_boolParam;
            stromx::cvsupport::Matrix m_matrixParam;
            stromx::cvsupport::Matrix m_intMatrixParam;
            stromx::runtime::Bool m_triggerValue;
            stromx::runtime::Float32 m_pullValue;
            stromx::runtime::Float32 m_pushValue;
        };
    }
}

#endif // STROMX_TEST_PARAMETEROPERATOR_H
