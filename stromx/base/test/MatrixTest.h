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

#ifndef STROMX_BASE_MATRIXTEST_H
#define STROMX_BASE_MATRIXTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <stromx/core/Version.h>

namespace stromx
{
    namespace base
    {
        class Matrix;

        class MatrixTest : public CPPUNIT_NS :: TestFixture
        {
            CPPUNIT_TEST_SUITE (MatrixTest);
            CPPUNIT_TEST (testMatrixEmpty);
            CPPUNIT_TEST (testMatrixCopyConstructor);
            CPPUNIT_TEST (testMatrixEmptyCopyConstructor);
            CPPUNIT_TEST (testMatrixDefaultCopyConstructor);
            CPPUNIT_TEST (testImageCvImageConstructor);
            CPPUNIT_TEST (testMatrixFloat);
            CPPUNIT_TEST (testMatrixDefault);
            CPPUNIT_TEST (testSerialize);
            CPPUNIT_TEST (testSerializeEmpty);
            CPPUNIT_TEST (testDeserialize);
            CPPUNIT_TEST (testDeserializeEmpty);
            CPPUNIT_TEST (testResizeDimension);
            CPPUNIT_TEST (testResizeBuffer);
            CPPUNIT_TEST_SUITE_END ();

            public:
                MatrixTest() : m_matrix(0) {}
                
                void setUp();
                void tearDown();

            protected:
                void testMatrixEmpty();
                void testMatrixCopyConstructor();
                void testMatrixEmptyCopyConstructor();
                void testMatrixDefaultCopyConstructor();
                void testImageCvImageConstructor();
                void testMatrixFloat();
                void testMatrixInt16();
                void testMatrixDefault();
                void testSerialize();
                void testSerializeEmpty();
                void testDeserialize();
                void testDeserializeEmpty();
                void testResizeDimension();
                void testResizeBuffer();
                
            private:
                const static stromx::core::Version VERSION;
                
                Matrix* m_matrix;
        };
    }
}

#endif // STROMX_BASE_MATRIXTEST_H