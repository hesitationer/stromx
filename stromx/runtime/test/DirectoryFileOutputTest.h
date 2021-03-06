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

#ifndef STROMX_RUNTIME_DIRECTORYFILEOUTPUTTEST_H
#define STROMX_RUNTIME_DIRECTORYFILEOUTPUTTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

namespace stromx
{
    namespace runtime
    {
        class DirectoryFileOutput;
        
        class DirectoryFileOutputTest : public CPPUNIT_NS :: TestFixture
        {
            CPPUNIT_TEST_SUITE (DirectoryFileOutputTest);
            CPPUNIT_TEST(testText);
            CPPUNIT_TEST(testFile);
            CPPUNIT_TEST(testFileDuplicate);
            CPPUNIT_TEST(testGetFilename);
            CPPUNIT_TEST_SUITE_END ();

        public:
            DirectoryFileOutputTest() : m_output(0) {}
            
            void setUp();
            void tearDown();
            
        protected:
            void testText();
            void testFile();
            void testFileDuplicate();
            void testGetFilename();
                
        private:
            DirectoryFileOutput* m_output;
        };
    }
}

#endif // STROMX_RUNTIME_DIRECTORYFILEOUTPUTTEST_H