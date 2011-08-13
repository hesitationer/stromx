#include "InputNode.h"

#include "../DataContainer.h"
#include "../Exception.h"
#include "../Operator.h"

#include "OutputNode.h"

namespace stream
{
    InputNode::InputNode(Operator* const op, const unsigned int inputId)
      : m_source(0),
        m_inputId(inputId),
        m_operator(op)
    {

    }

    void InputNode::connect(OutputNode* const output)
    {
        if(m_source)
            throw InvalidState("Input node has already been connected.");
        
        m_source = output;
        m_source->addConnectedInput(this);
    }
    
    void InputNode::setInputData()
    {
        if(! m_source)
            throw InvalidState("Input node has not been connected.");
        
        DataContainer inputData = m_source->getOutputData();
        
        m_operator->setInputData(m_inputId, inputData);
    }
    
    void InputNode::disconnect()
    {
        if(m_source)
            m_source->removeConnectedInput(this);
        
        m_source = 0;
    }
}