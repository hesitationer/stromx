#include "Image.h"

#include "Utilities.h"

#include <stream/Exception.h>

namespace base
{
    Image::Image(const unsigned int width, const unsigned int height, const stream::Image::PixelType pixelType)
    {
        try
        {
            m_image = cvCreateImage(cv::Size(width, height), depth(pixelType) * 8, numChannels(pixelType));
            
            getDataFromCvImage();
            setPixelType(pixelType);
            setDataType(dataTypeFromPixelType(pixelType));
        }
        catch(cv::Exception& e)
        {
            throw stream::OutOfMemoryException("Failed to create new image.");
        }
    }
    
    Image::Image(const stream::Image& image)
    {
        try
        {
            m_image = cvCreateImage(cv::Size(image.width(), image.height()),
                                    depth(image.pixelType()) * 8, numChannels(image.pixelType()));
            
            getDataFromCvImage();
            setPixelType(image.pixelType());
            setDataType(image.type());
        }
        catch(cv::Exception& e)
        {
            throw stream::OutOfMemoryException("Failed to create new image.");
        }
        
        cv::Mat cvInImage = getOpenCvMat(image);
        cv::Mat cvImage(m_image);
        cvInImage.copyTo(cvImage);
    }
    
    Image::Image(const std::string& filename)
    {
        try
        {
            m_image = cvLoadImage(filename.c_str());
            
            getDataFromCvImage();
            setPixelType(pixelTypeFromParameters(m_image->depth, m_image->nChannels));
            setDataType(dataTypeFromPixelType(pixelType()));
        }
        catch(cv::Exception& e)
        {
            throw stream::FileAccessException("Failed to load image '" + filename + "'.");
        }
    }
    
    
    void Image::getDataFromCvImage()
    {
        setBuffer((uint8_t*)(m_image->imageData));
        setSize(m_image->imageSize);
        setData((uint8_t*)(m_image->imageData));
        setStride(m_image->widthStep);
        setWidth(m_image->width);
        setHeight(m_image->height);
    }
    
    void Image::resize(const unsigned int width, const unsigned int height, const stream::Image::PixelType pixelType)
    {
        if(m_image)
            cvReleaseImage(&m_image);
        
        try
        {
            m_image = cvCreateImage(cv::Size(width, height), depth(pixelType), numChannels(pixelType));
            setPixelType(pixelType);
            setDataType(dataTypeFromPixelType(pixelType));
        }
        catch(cv::Exception& e)
        {
            throw stream::OutOfMemoryException("Failed to create new image.");
        }
    }
    
    void Image::save(const std::string& filename) const
    {
        cv::Mat inImage = getOpenCvMat(*this);
        
        switch(pixelType())
        {
        case stream::Image::RGB_24:
        {
            Image tempImage(width(), height(), BGR_24);
            cv::Mat cvTempImage(tempImage.m_image);
            
            cv::cvtColor(inImage, cvTempImage, CV_RGB2BGR); 
                      
            try
            {
                cv::imwrite(filename, tempImage.m_image);
            }
            catch(cv::Exception& e)
            {
                throw stream::FileAccessException("Failed to save image '" + filename + "'.");
            }
            break;
        }
        case stream::Image::BGR_24:
        case stream::Image::MONO_8:
        {
            try
            {
                cv::imwrite(filename, inImage);
            }
            catch(cv::Exception& e)
            {
                throw stream::FileAccessException("Failed to save image '" + filename + "'.");
            }
        }
            break;
        default:
            throw stream::ArgumentException("Unknown pixel type.");    
        }         
    }
    
    Image::~Image()
    {
        cvReleaseImage(&m_image);
    }

    const stream::DataType Image::dataTypeFromPixelType(const stream::Image::PixelType pixelType)
    {
        switch(pixelType)
        {
        case stream::Image::MONO_8:
            return stream::DataType(stream::DataType::MONO_8_IMAGE);
        case stream::Image::BAYERBG_8:
            return stream::DataType(stream::DataType::BAYERBG_8_IMAGE);
        case stream::Image::BAYERGB_8:
            return stream::DataType(stream::DataType::BAYERGB_8_IMAGE);
        case stream::Image::RGB_24:
            return stream::DataType(stream::DataType::RGB_24_IMAGE);
        case stream::Image::BGR_24:
            return stream::DataType(stream::DataType::BGR_24_IMAGE);
        default:
            throw stream::ArgumentException("Unknown pixel type.");  
        }
    }

    const stream::Image::PixelType Image::pixelTypeFromParameters(const int depth, const int numChannels)
    {
        switch(depth)
        {
        case 8:
            switch(numChannels)
            {
            case 1:
                return stream::Image::MONO_8;
            case 3:
                return stream::Image::BGR_24;
            default:
                throw stream::ArgumentException("Unknown combination of depth and number of channels.");
            }
        case 16:
            switch(numChannels)
            {
            default:
                throw stream::ArgumentException("Unknown combination of depth and number of channels.");      
            }
        default:
            throw stream::ArgumentException("Unknown combination of depth and number of channels.");    
        }         
    }
}