/* 
*  Copyright 2011 Thomas Fidler
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

#ifndef STROMX_RUNTIME_STREAMTEST_H
#define STROMX_RUNTIME_STREAMTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <vector>
#include "stromx/runtime/ExceptionObserver.h"

namespace stromx
{
    namespace runtime
    {
        class Stream;
        class Network;
        class Operator;
        
        class StreamTest : public CPPUNIT_NS :: TestFixture
        {
            CPPUNIT_TEST_SUITE (StreamTest);
            CPPUNIT_TEST(testOperators);
            CPPUNIT_TEST(testConnect);
            CPPUNIT_TEST(testDisconnect);
            CPPUNIT_TEST(testAddOperator);
            CPPUNIT_TEST(testRemoveOperator);            
            CPPUNIT_TEST(testAddThread);
            CPPUNIT_TEST(testRemoveThread);
            CPPUNIT_TEST(testPause);
            CPPUNIT_TEST(testResume);
            CPPUNIT_TEST(testAddObserver);
            CPPUNIT_TEST(testRemoveObserver);
            CPPUNIT_TEST(testObserver);
            CPPUNIT_TEST(testTwoObserver);
            CPPUNIT_TEST(testDelay);
            CPPUNIT_TEST(testStopDelay);
            CPPUNIT_TEST_SUITE_END ();

        public:
            StreamTest() {}
            
            void setUp();
            void tearDown();

        protected:
            void testOperators();
            void testConnect();
            void testDisconnect();
            void testAddOperator();
            void testRemoveOperator();
            void testAddThread();
            void testRemoveThread();
            void testPause();
            void testResume();
            void testAddObserver();
            void testRemoveObserver();
            void testObserver();
            void testTwoObserver();
            void testDelay();
            void testStopDelay();
                
        private:
            class TestObserver : public ExceptionObserver
            {
            public:
                void observe(const Phase phase, const OperatorError & ex, const Thread* const thread) const;
                
                ExceptionObserver::Phase phase() const { return m_phase; }
                const std::string message() const { return m_message; }
                const Thread* thread() const { return m_thread; }
                
            private:
                mutable ExceptionObserver::Phase m_phase;
                mutable std::string m_message;
                mutable const Thread* m_thread;
            };
            
            Stream* m_stream;
            Network* m_network;
            Operator* m_op1;
            Operator* m_op2;
        };
    }
}

#endif // STROMX_RUNTIME_STREAMTEST_H 