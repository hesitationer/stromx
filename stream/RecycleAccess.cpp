#include "RecycleAccess.h"

namespace stream
{
    RecycleAccess::RecycleAccess(DataContainer data)
      : m_impl(new impl::RecycleAccessImpl(data))
    {
    }

    Data*const RecycleAccess::operator()()
    {
        if(! m_impl.get())
            return 0;
        
        return (*m_impl)();
    }

    Data*const RecycleAccess::operator()(const unsigned int timeout)
    {
        if(! m_impl.get())
            return 0;
        
        return (*m_impl)(timeout);
    }
    
    void RecycleAccess::add(DataContainer data)
    {
        if(! m_impl.get())
            m_impl = boost::shared_ptr<impl::RecycleAccessImpl>(new impl::RecycleAccessImpl(data));
        else
            m_impl->add(data);
    }
} 
