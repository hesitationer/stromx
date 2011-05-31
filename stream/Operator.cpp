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

#include "Operator.h"

#include "Exception.h"

#include <set>
#include <boost/lexical_cast.hpp>

namespace stream
{
    Operator::Operator (const std::string & name,
                        const Version & version,
                        const std::vector<Description>& inputs,
                        const std::vector<Description>& outputs,
                        const std::vector<Parameter>& parameters)
      : m_name(name),
        m_version(version),
        m_inputs(inputs),
        m_outputs(outputs),
        m_parameters(parameters)
    {
        validate(inputs);
        validate(outputs);
        validate(parameters);
    }
    
    Description& Operator::getParameterDescription(unsigned int id)
    {
        if(id >= m_parameters.size())
            throw WrongIdException("No parameter with ID " + id);
        
        return m_parameters[id];
    }
    
    void Operator::validate(const std::vector<Description>& descriptors)
    {
        std::set<unsigned int> ids;
        
        for(std::vector<Description>::const_iterator iter = descriptors.begin();
            iter != descriptors.end();
            ++iter)
        {
            if(ids.count(iter->id()))
                throw ArgumentException("ID " + boost::lexical_cast<std::string>(iter->id()) + " appears twice.");
        }
    }
    
    void Operator::validate(const std::vector<Parameter>& descriptors)
    {
        std::set<unsigned int> ids;
        
        for(std::vector<Parameter>::const_iterator iter = descriptors.begin();
            iter != descriptors.end();
            ++iter)
        {
            if(ids.count(iter->id()))
                throw ArgumentException("ID " + boost::lexical_cast<std::string>(iter->id()) + " appears twice.");
        }
    }
}