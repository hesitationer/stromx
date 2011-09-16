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

#include "OutputNode.h"

#include "../Exception.h"
#include "../DataContainer.h"
#include "../Operator.h"

namespace strom
{
    namespace impl
    {
        OutputNode::OutputNode(Operator*const op, const unsigned int outputId)
        : m_operator(op),
            m_outputId(outputId),
            m_remainingCopies(0)
        {}
        
        void OutputNode::addConnectedInput(InputNode*const input)
        {
            if(! input)
                throw WrongArgument("Passed null as input.");
            
            if(m_connectedInputs.count(input))
                throw WrongArgument("Input node has already been connected to this output node.");
            
            m_connectedInputs.insert(input);
        }

        void OutputNode::removeConnectedInput(InputNode*const input)
        {
            if(m_connectedInputs.count(input))
                m_connectedInputs.erase(input);
        }

        DataContainer OutputNode::getOutputData()
        {
            DataContainer value = m_operator->getOutputData(m_outputId);
            
            // the data has been obtained
            // now make sure the connection counter is adapted in an atomic operation
            {
                lock_t lock(m_mutex);
                
                if(! m_remainingCopies)
                {
                    m_operator->clearOutputData(m_outputId);
                    m_remainingCopies = m_connectedInputs.size();
                }
                
                m_remainingCopies--; 
            }
            
            return value;
        }
    }
}