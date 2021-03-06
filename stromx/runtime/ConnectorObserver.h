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

#ifndef STROMX_RUNTIME_CONNECTOROBSERVER_H
#define STROMX_RUNTIME_CONNECTOROBSERVER_H


namespace stromx
{
    namespace runtime
    {
        class Connector;
        class DataContainer;
        class Thread;

        /** \brief Abstract base class of observers of operator connectors. */
        class ConnectorObserver
        {
        public:
            /** Informs the observer that \c connector was set to \c data. */
            virtual void observe(const Connector & connector, const DataContainer & oldData, const DataContainer & newData, const Thread* const thread) const = 0;
        };
    }
}

#endif // STROMX_RUNTIME_CONNECTOROBSERVER_H
