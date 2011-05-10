#include "DataContainerTest.h"

#include <stream/DataContainer.h>
#include <stream/None.h>
#include <stream/Exception.h>


#include <cppunit/TestAssert.h>

CPPUNIT_TEST_SUITE_REGISTRATION (stream::DataContainerTest);

namespace stream
{
    void DataContainerTest::setUp ( void )
    {
        Data* data = new stream::None;
        m_container = new DataContainer(data);
    }

    void DataContainerTest::dereferenceTest ( void )
    {
        CPPUNIT_ASSERT_NO_THROW(m_container->reference());
        CPPUNIT_ASSERT_NO_THROW(m_container->reference());
        CPPUNIT_ASSERT_NO_THROW(m_container->dereference());
        CPPUNIT_ASSERT_NO_THROW(m_container->dereference()); 
    }

    void DataContainerTest::getWriteAccessTest()
    {
        CPPUNIT_ASSERT_NO_THROW(m_container->getWriteAccess());
        CPPUNIT_ASSERT_NO_THROW(m_container->reference());
        CPPUNIT_ASSERT_THROW(m_container->getWriteAccess(), ReferenceCountException);
        CPPUNIT_ASSERT_NO_THROW(m_container->dereference());
        CPPUNIT_ASSERT_NO_THROW(m_container->getWriteAccess());
    }

    void DataContainerTest::tearDown ( void )
    {
        delete m_container;
    }
}