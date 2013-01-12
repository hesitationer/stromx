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

#include <stromx/runtime/DataContainer.h>
#include <stromx/runtime/DataVariant.h>
#include <stromx/runtime/Data.h>
#include <stromx/runtime/Image.h>

#include <stromx/base/Image.h>

#include <memory>
#include <boost/python.hpp>

using namespace boost::python;
using namespace stromx::runtime;

namespace
{  
    std::auto_ptr<stromx::base::Image> allocateFromDimension(const unsigned int width, const unsigned int height, const Image::PixelType pixelType)
    {
        return std::auto_ptr<stromx::base::Image>(new stromx::base::Image(width, height, pixelType));
    }
    
    std::auto_ptr<stromx::base::Image> allocateFromFile(const std::string & filename)
    {
        return std::auto_ptr<stromx::base::Image>(new stromx::base::Image(filename));
    } 
    
    std::auto_ptr<stromx::base::Image> allocateFromFileWithAccess(const std::string & filename, const stromx::base::Image::FileAccess access)
    {
        return std::auto_ptr<stromx::base::Image>(new stromx::base::Image(filename, access));
    } 
}

void exportImage()
{
    enum_<stromx::base::Image::FileAccess>("ImageFileAccess")
        .value("UNCHANGED", stromx::base::Image::UNCHANGED)
        .value("GRAYSCALE", stromx::base::Image::GRAYSCALE)
        .value("COLOR", stromx::base::Image::COLOR)
    ;
    
    class_<stromx::base::Image, bases<stromx::runtime::Image>, std::auto_ptr<stromx::base::Image> >("Image", no_init)
        .def("__init__", make_constructor(&allocateFromFile))
        .def("__init__", make_constructor(&allocateFromDimension))
        .def("__init__", make_constructor(&allocateFromFileWithAccess))
        .def<void (stromx::base::Image::*)(const std::string &) const>("save", &stromx::base::Image::save)
        .def<void (stromx::base::Image::*)(const std::string &)>("open", &stromx::base::Image::open)
        .def<void (stromx::base::Image::*)(const std::string &, const stromx::base::Image::FileAccess)>("open", &stromx::base::Image::open)
        .def<void (stromx::base::Image::*)(const unsigned int, const unsigned int, const Image::PixelType)>("resize", &stromx::base::Image::resize)
     ;
     
    implicitly_convertible< std::auto_ptr<stromx::base::Image>, std::auto_ptr<Data> >();
}
