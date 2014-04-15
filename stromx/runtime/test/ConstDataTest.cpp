/* 
*  Copyright 2014 Matthias Fuchs
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

#include <cppunit/TestAssert.h>
#include "stromx/runtime/test/ConstDataTest.h"
#include "stromx/runtime/ConstData.h"
#include "stromx/runtime/DataContainer.h"
#include "stromx/runtime/OperatorTester.h"
#include "stromx/runtime/ReadAccess.h"

CPPUNIT_TEST_SUITE_REGISTRATION (stromx::runtime::ConstDataTest);

namespace stromx
{
    using namespace runtime;

    namespace runtime
    {
        void ConstDataTest::setUp()
        {
            m_operator = new OperatorTester(new ConstData());
            m_operator->initialize();
            m_operator->activate();
        }

        void ConstDataTest::testExecute()
        {
        }

        void ConstDataTest::tearDown()
        {
            delete m_operator;
        }
    }
}
