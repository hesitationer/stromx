/* 
 *  Copyright 2016 Matthias Fuchs
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

#ifndef STROMX_RUNTIME_OUTPUT_H
#define STROMX_RUNTIME_OUTPUT_H

#include "stromx/runtime/ConnectorDescription.h"

namespace stromx
{
    namespace runtime
    {
        
        /** \brief %Description of an input. */
        class STROMX_RUNTIME_API Output : public ConnectorDescription
        {
        public:
            /** Constructs a description. */
            Output(const unsigned int id, const VariantHandle& variant)
              : ConnectorDescription(id, variant, OUTPUT)
            {}
            
            virtual Type originalType() const { return OUTPUT; }
            virtual Type currentType() const { return OUTPUT; }
            
        private:
            unsigned int m_operatorThread;
            Type m_defaultType;
        };
    }
}

#endif // STROMX_RUNTIME_OUTPUT_H