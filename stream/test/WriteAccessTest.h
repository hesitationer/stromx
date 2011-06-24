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

#ifndef STREAM_WRITEACCESSTEST_H
#define STREAM_WRITEACCESSTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

namespace stream
{
    class WriteAccess;
    class Data;
    
    class WriteAccessTest : public CPPUNIT_NS :: TestFixture
    {
        CPPUNIT_TEST_SUITE (WriteAccessTest);
        CPPUNIT_TEST(testWriteAccess);
        CPPUNIT_TEST(testReleaseWriteAccess);
        CPPUNIT_TEST(testWriteAccessDelayed);
        CPPUNIT_TEST_SUITE_END ();

    public:
        WriteAccessTest () : m_data(0) {}
        
        void setUp() {}
        void tearDown() { m_data = 0; }

    protected:
        void testWriteAccess();
        void testReleaseWriteAccess();
        void testWriteAccessDelayed();
            
    private:
        Data* m_data;
        void releaseDelayed(WriteAccess& access);
    };
}

#endif // STREAM_WRITEACCESSTEST_H