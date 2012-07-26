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

#include "Close.h"

#include <opencv2/imgproc/imgproc.hpp>

namespace stromx
{
    namespace base
    {
        const std::string Close::TYPE("Close");
        
        Close::Close()
          : MorphologicalFilter(TYPE)
        {
        }
        
        void Close::applyMorphologicalFilter(const cv::Mat& in, cv::Mat& out, const cv::InputArray kernel, int iterations)
        {
            cv::erode(in, out, kernel, cv::Point(-1, -1), iterations);
        }
    } 
}