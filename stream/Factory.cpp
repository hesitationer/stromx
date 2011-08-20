#include "Factory.h"

#include "Exception.h"
#include "OperatorKernel.h"
#include "Operator.h"
#include "Data.h"


namespace stream
{
    Factory::~Factory()
    {
        for(std::vector<const OperatorKernel*>::iterator iter = m_operators.begin();
            iter != m_operators.end();
            ++iter)
        {
            delete (*iter);
        }
        
        for(std::vector<const Data*>::iterator iter = m_dataTypes.begin();
            iter != m_dataTypes.end();
            ++iter)
        {
            delete (*iter);
        }
    }

    void Factory::registerOperator(const OperatorKernel*const op)
    {
        if(op == 0)
        {
            throw WrongArgument("Invalid argument: Null pointer.");
        }
        
        for(std::vector<const OperatorKernel*>::iterator iter = m_operators.begin();
            iter != m_operators.end();
            ++iter)
        {
            if(op->name() == (*iter)->name() && op->package() == (*iter)->package())
            {
                throw WrongArgument("Invalid argument: Operator already registered.");
            }
        }
        
        m_operators.push_back(op);
    }

    void Factory::registerData(const Data*const data)
    {
        if(data == 0)
        {
            throw WrongArgument("Invalid argument: Null pointer.");
        }
        
        for(std::vector<const Data*>::iterator iter = m_dataTypes.begin();
            iter != m_dataTypes.end();
            ++iter)
        {
            if(data->name() == (*iter)->name() && data->package() == (*iter)->package())
            {
                throw WrongArgument("Invalid argument: Data already registered.");
            }
        }
        
        m_dataTypes.push_back(data);
    }

    const std::vector< const OperatorKernel*>& Factory::availableOperators() const
    {
        return m_operators;
    }

    Operator*const Factory::newOperator(const std::string& package, const std::string& name) const
    {
        for(std::vector<const OperatorKernel*>::const_iterator iter = m_operators.begin();
            iter != m_operators.end();
            ++iter)
        {
            if((*iter)->name() == name && (*iter)->package() == package)
            {
                OperatorKernel* newOp = 0;
                newOp = (*iter)->clone();
                if (newOp == 0)
                { 
                    throw InternalError("Invalid argument received: Null pointer. Cloning failed");
                }

                return new Operator(newOp);
            }
        }
        
       throw WrongArgument("Invalid argument: Operator (" + package + ", " + name + ") unknown. Register first unknown operator.");        
    }

    Data*const Factory::newData(const std::string& package, const std::string& name) const
    {
        for(std::vector<const Data*>::const_iterator iter = m_dataTypes.begin();
            iter != m_dataTypes.end();
            ++iter)
        {
            if((*iter)->name() == name && (*iter)->package() == package)
            {
                Data* newData = 0;
                newData = (*iter)->clone();
                if (newData == 0)
                { 
                    throw InternalError("Invalid argument received: Null pointer. Cloning failed");
                }

                return newData;
            }
        }
        
       throw WrongArgument("Invalid argument: Data (" + package + ", " + name + ") unknown. Register first unknown data.");        
    }
} 