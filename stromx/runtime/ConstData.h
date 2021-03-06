/* 
*  Copyright 2014 Matthias Fuchs
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*/

#ifndef STROMX_RUNTIME_CONSTDATA_H
#define STROMX_RUNTIME_CONSTDATA_H

#include "stromx/runtime/Config.h"
#include "stromx/runtime/OperatorKernel.h"
#include "stromx/runtime/Primitive.h"
#include "stromx/runtime/RecycleAccess.h"
#include "stromx/runtime/DataOperatorBase.h"

namespace stromx
{
    namespace runtime
    {
        class DataContainer;
    }

    namespace runtime
    {
        /** \brief Outputs a constant value. */
        class STROMX_RUNTIME_API ConstData : public DataOperatorBase
        {
        public:            
            enum DataId
            {
                ALLOCATE_DATA = DataOperatorBase::NUM_BASE_PARAMETERS
            };
            
            ConstData();
            virtual ~ConstData();
            
            virtual OperatorKernel* clone() const { return new ConstData; }
            virtual void setParameter(const unsigned int id, const runtime::Data& value);
            virtual const DataRef getParameter(const unsigned int id) const;
            virtual void deactivate();
            virtual void execute(runtime::DataProvider& provider);
            
        private:
            static const std::vector<const runtime::Parameter*> setupInitParameters();
            
            static const std::string TYPE;
            static const std::string PACKAGE;
            static const runtime::Version VERSION; 
            
            Bool m_allocateData;
            RecycleAccess m_recycleAccess;
        };       
    }
}

#endif // STROMX_RUNTIME_CONSTDATA_H
