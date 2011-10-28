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

#ifndef BASE_TRIGGERTEST_H
#define BASE_TRIGGERTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <stromx/core/DataContainer.h>

namespace core
{
    class OperatorTester;
}

namespace base
{
    class TriggerTest : public CPPUNIT_NS :: TestFixture
    {
        CPPUNIT_TEST_SUITE (TriggerTest);
        CPPUNIT_TEST (testExecuteActive);
        CPPUNIT_TEST (testExecuteInactive);
        CPPUNIT_TEST_SUITE_END ();

        public:
            TriggerTest() : m_operator(0) {}
            
            void setUp();
            void tearDown();

        protected:
            void testExecuteActive();
            void testExecuteInactive();
            
        private:
            void triggerDelayed ();
            void getOutputDataInterrupted();
    
            core::OperatorTester* m_operator;
            core::DataContainer m_image;
    };
}

#endif // BASE_TRIGGERTEST_H