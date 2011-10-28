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

#ifndef STROM_RECYCLEACCESSTEST_H
#define STROM_RECYCLEACCESSTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <stromx/core/RecycleAccess.h>

namespace stromx
{
    namespace core
    {
        class DataContainer;
        class RecycleAccess;
        
        class RecycleAccessTest : public CPPUNIT_NS :: TestFixture
        {
            CPPUNIT_TEST_SUITE (RecycleAccessTest);
            CPPUNIT_TEST(testRecycle);
            CPPUNIT_TEST(testNoRecycle);
            CPPUNIT_TEST(testDelayedRecycle);
            CPPUNIT_TEST(testRecycleNoTimeout);
            CPPUNIT_TEST(testRecycleTimeout);
            CPPUNIT_TEST(testCopiedRecycle);
            CPPUNIT_TEST(testRecycleInterrupt);
            CPPUNIT_TEST(testGetRecycleAccessDelayed);
            CPPUNIT_TEST(testGetRecycleAccessInterrupt);
            CPPUNIT_TEST(testAdd);
            CPPUNIT_TEST(testRecycleMultiple);
            CPPUNIT_TEST_SUITE_END ();

        public:
            RecycleAccessTest () {}
            
            void setUp() {}
            void tearDown() {}

        protected:
            void testRecycle();
            void testNoRecycle();
            void testDelayedRecycle();
            void testCopiedRecycle();
            void testRecycleNoTimeout();
            void testRecycleTimeout();
            void testRecycleInterrupt();
            void testGetRecycleAccessDelayed();
            void testGetRecycleAccessInterrupt();
            void testAdd();
            void testRecycleMultiple();
            
        private:
            void destroyDelayed(DataContainer & container);
            void recycleInterrupt(RecycleAccess & access);
            void releaseAccessDelayed(RecycleAccess & access);
            void getAccessInterrupt(DataContainer & container);
        };
    }
}

#endif // STROM_RECYCLEACCESSTEST_H