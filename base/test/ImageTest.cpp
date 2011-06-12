#include "ImageTest.h"

#include <base/Image.h>

#include <cppunit/TestAssert.h>

CPPUNIT_TEST_SUITE_REGISTRATION (base::ImageTest);

namespace base
{
    void ImageTest::setUp ( void )
    {
        m_image = 0;
    }
    
    void ImageTest::testImageFromJpeg()
    {
        CPPUNIT_ASSERT_NO_THROW(m_image = new Image("lenna.jpg"));
        CPPUNIT_ASSERT_EQUAL((unsigned int)(500), m_image->width());
        CPPUNIT_ASSERT_EQUAL((unsigned int)(512), m_image->height());
        CPPUNIT_ASSERT_EQUAL((unsigned int)(1500), m_image->stride());
        CPPUNIT_ASSERT_EQUAL(stream::Image::RGB_24, m_image->pixelType());
        CPPUNIT_ASSERT(m_image->data());
    }
    
    void ImageTest::testImageRgb24()
    {
        CPPUNIT_ASSERT_NO_THROW(m_image = new Image(200, 100, stream::Image::RGB_24));
        CPPUNIT_ASSERT_EQUAL((unsigned int)(200), m_image->width());
        CPPUNIT_ASSERT_EQUAL((unsigned int)(100), m_image->height());
        CPPUNIT_ASSERT_EQUAL((unsigned int)(600), m_image->stride());
        CPPUNIT_ASSERT_EQUAL(stream::Image::RGB_24, m_image->pixelType());
        CPPUNIT_ASSERT(m_image->data());
    }
    
    void ImageTest::testImageMono8()
    {
        CPPUNIT_ASSERT_NO_THROW(m_image = new Image(200, 100, stream::Image::MONO_8));
        CPPUNIT_ASSERT_EQUAL((unsigned int)(200), m_image->width());
        CPPUNIT_ASSERT_EQUAL((unsigned int)(100), m_image->height());
        CPPUNIT_ASSERT_EQUAL((unsigned int)(200), m_image->stride());
        CPPUNIT_ASSERT_EQUAL(stream::Image::MONO_8, m_image->pixelType());
        CPPUNIT_ASSERT(m_image->data());
    }

    void ImageTest::testSaveJpeg()
    {
        m_image = new Image(200, 100, stream::Image::RGB_24);
        CPPUNIT_ASSERT_NO_THROW(m_image->save("testSaveJpeg.jpg"));
        delete m_image;
        m_image = 0;
        m_image = new Image("testSaveJpeg.jpg");
        CPPUNIT_ASSERT_EQUAL((unsigned int)(200), m_image->width());
        CPPUNIT_ASSERT_EQUAL((unsigned int)(100), m_image->height());
    }

    void ImageTest::tearDown ( void )
    {
        delete m_image;
    }
}