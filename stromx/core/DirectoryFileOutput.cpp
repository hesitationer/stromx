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

#include <boost/filesystem.hpp>
#include "DirectoryFileOutput.h"
#include "Exception.h"

namespace stromx
{
    namespace core
    {
        DirectoryFileOutput::~DirectoryFileOutput()
        {
            if(m_currentFile.is_open())
                m_currentFile.close();
        }

        void DirectoryFileOutput::reset(const std::string& filename)
        {
            m_currentText.clear();
            
            if(m_currentFile.is_open())
                m_currentFile.close();
        
            m_currentFilename = filename;
        }

        const std::string DirectoryFileOutput::getText() const
        {
            return m_currentText.str();
        }

        std::ostream& DirectoryFileOutput::text()
        {
            return m_currentText;
        }

        std::ostream& DirectoryFileOutput::openFile(const std::string& ext, const stromx::core::OutputProvider::OpenMode mode)
        {
            if(m_currentFile.is_open())
                throw WrongState("File has already been opened.");
            
            std::ios_base::openmode iosmode;
            
            if(mode == BINARY)
                iosmode = std::ios_base::binary;
            
            std::string pathSeparator = boost::filesystem::path("/").string();  
            m_currentFile.open((m_directory + pathSeparator + m_currentFilename + "." + ext).c_str(), std::ios_base::in & iosmode);
            
            if(m_currentFile.fail())
                throw FileAccessFailed(m_currentFilename);
            
            return m_currentFile;
        }

        std::ostream& DirectoryFileOutput::file()
        {
            if(! m_currentFile.is_open())
                throw WrongState("File has not been opened.");
            
            return m_currentFile;
        }     
    }
}