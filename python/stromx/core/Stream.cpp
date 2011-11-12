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

#include "ExportVector.h"

#include <stromx/core/Stream.h>
#include <stromx/core/Operator.h>

#include <boost/python.hpp>

using namespace boost::python;
using namespace stromx::core;

namespace
{
    void addOperatorWrap(Stream& stream, std::auto_ptr<Operator> op)
    {
        stream.addOperator(op.get());
        op.release();
    }
}

void exportStream()
{    
    stromx::python::exportPtrVector<Operator>("OperatorVector");
    
    enum_<Stream::Status>("StreamStatus")
        .value("INACTIVE", Stream::INACTIVE)
        .value("ACTIVE", Stream::ACTIVE)
        .value("DEACTIVATING", Stream::DEACTIVATING)
    ;
        
    class_<Stream>("Stream")
        .def("name", &Stream::name, return_value_policy<copy_const_reference>())
        .def("setName", &Stream::setName)
        .def("status", &Stream::status)
        .def("operators", &Stream::operators, return_internal_reference<>())
        .def("addOperator", &addOperatorWrap)
        .def("removeOperator", &Stream::removeOperator)
        .def("connect", &Stream::connect)
        .def("disconnect", &Stream::disconnect)
        .def("connectionSource", &Stream::connectionSource)
        .def("start", &Stream::start)
        .def("stop", &Stream::stop)
        .def("join", &Stream::join)
    ;
}