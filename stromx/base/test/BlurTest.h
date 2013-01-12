/* 
*  Copyright 2012 Matthias Fuchs
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

#ifndef STROMX_BASE_BLURTEST_H
#define STROMX_BASE_BLURTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

namespace stromx
{
    namespace runtime
    {
        class OperatorTester;
    }

    namespace base
    {
        class BlurTest : public CPPUNIT_NS :: TestFixture
        {
            CPPUNIT_TEST_SUITE (BlurTest);
            CPPUNIT_TEST (testExecuteCopy);
            CPPUNIT_TEST (testExecuteGaussianMono);
            CPPUNIT_TEST (testExecuteGaussianColor);
            CPPUNIT_TEST (testExecuteMedianMono);
            CPPUNIT_TEST (testExecuteMedianColor);
            CPPUNIT_TEST_SUITE_END ();

            public:
                BlurTest() : m_operator(0) {}
                
                void setUp();
                void tearDown();

            protected:
                void testExecuteCopy();
                void testExecuteGaussianMono();
                void testExecuteGaussianColor();
                void testExecuteMedianMono();
                void testExecuteMedianColor();
                
            private:
                runtime::OperatorTester* m_operator;
        };
    }
}

#endif // STROMX_BASE_BLURTEST_H