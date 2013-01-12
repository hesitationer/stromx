/* 
*  Copyright 2011 Matthias Fuchs
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

#ifndef STROMX_BASE_BUFFER_H
#define STROMX_BASE_BUFFER_H

#include "Config.h"
#include <stromx/runtime/OperatorKernel.h>
#include <stromx/runtime/Primitive.h>
#include <stromx/runtime/RecycleAccess.h>

namespace stromx
{
    namespace runtime
    {
        class Data;
    }

    namespace base
    {
        /** \brief Manages an array or reusable image buffers. */
        class STROMX_BASE_API Buffer : public runtime::OperatorKernel
        {
        public:
            enum OutputId
            {
                OUTPUT
            };
            
            enum ParameterId
            {
                NUM_BUFFERS,
                BUFFER_SIZE
            };
            
            Buffer();
            
            virtual OperatorKernel* clone() const { return new Buffer; }
            virtual void setParameter(const unsigned int id, const runtime::Data& value);
            virtual const runtime::DataRef getParameter(const unsigned int id) const;
            virtual void execute(runtime::DataProvider& provider);
            virtual void activate();
            virtual void deactivate();
            
        private:
            static const std::vector<const runtime::Description*> setupInputs();
            static const std::vector<const runtime::Description*> setupOutputs();
            static const std::vector<const runtime::Parameter*> setupParameters();
            
            static const std::string TYPE;
            static const std::string PACKAGE;
            static const runtime::Version VERSION;
            
            runtime::RecycleAccess m_buffers;
            runtime::UInt32 m_bufferSize;
            runtime::UInt32 m_numBuffers;
        };
    }
}

#endif // STROMX_BASE_BUFFER_H

