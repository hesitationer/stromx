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

#ifndef BASE_CONSTIMAGE_H
#define BASE_CONSTIMAGE_H

#include <stream/Operator.h>
#include <stream/Image.h>
#include <stream/Enum.h>

namespace stream
{
    class DataContainer;
}

namespace base
{
    class ConstImage : public stream::Operator
    {
    public:
        enum OutputIds
        {
            OUTPUT
        };
        
        enum ParameterIds
        {
            IMAGE
        };
        
        ConstImage();
        virtual ~ConstImage();
        
        virtual void setParameter(unsigned int id, const stream::Data& value);
        virtual const stream::Data& getParameter(unsigned int id);
        virtual void execute(stream::DataProvider& provider);
        
    private:
        static const std::vector<stream::Description*> setupInputs();
        static const std::vector<stream::Description*> setupOutputs();
        static const std::vector<stream::Parameter*> setupParameters();
        
        static const std::string NAME;
        static const std::string PACKAGE;
        static const stream::Version VERSION;   
        
        stream::DataContainer* m_image;
    };
}

#endif // BASE_CONSTIMAGE_H