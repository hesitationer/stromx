#ifndef STROMX_CVIMGPROC_WARPPERSPECTIVETEST_H
#define STROMX_CVIMGPROC_WARPPERSPECTIVETEST_H

#include "stromx/cvimgproc/Config.h"

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

#include "stromx/runtime/OperatorTester.h"

namespace stromx
{
    namespace cvimgproc
    {
        class WarpPerspectiveTest : public CPPUNIT_NS::TestFixture
        {
            CPPUNIT_TEST_SUITE(WarpPerspectiveTest);
            CPPUNIT_TEST(testManual0);
            CPPUNIT_TEST(testManual1);
            CPPUNIT_TEST(testAllocate0);
            CPPUNIT_TEST_SUITE_END();
            
        public:
            WarpPerspectiveTest() : m_operator(0) {}
            void setUp();
            void tearDown();
            
        protected:
            void testManual0();
            void testManual1();
            void testAllocate0();
            
        private:
            runtime::OperatorTester* m_operator;
        };
    }
}

#endif // STROMX_CVIMGPROC_WARPPERSPECTIVETEST_H