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

#ifndef STROMX_CORE_READACCESS_H
#define STROMX_CORE_READACCESS_H

#include <memory>
#include "DataContainer.h"
#include "Exception.h"
#include "impl/ReadAccessImpl.h"

namespace stromx
{
    namespace core
    {
        class Data;
        
        /** \brief Read access to a data container */
        template<typename data_t = Data>
        class ReadAccess
        {
        public:
            ReadAccess(const DataContainer & data)
              : m_impl(new impl::ReadAccessImpl(data))
            {
            }
            
            const data_t & get() const
            {
                try
                {
                    return dynamic_cast<const data_t &>(m_impl->get());
                }
                catch(std::bad_cast &)
                {
                    throw BadCast();
                }
            }
            
            const data_t & operator()() const { return get(); }
            
        private:
            ReadAccess();
            std::tr1::shared_ptr<impl::ReadAccessImpl> m_impl;
        };
    }
}

#endif // STROMX_CORE_READACCESS_H
