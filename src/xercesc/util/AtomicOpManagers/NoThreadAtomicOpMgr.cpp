
/*
 * Copyright 1999-2000,2004-2005 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id$
 */

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/AtomicOpManagers/NoThreadAtomicOpMgr.hpp>

XERCES_CPP_NAMESPACE_BEGIN


NoThreadAtomicOpMgr::NoThreadAtomicOpMgr()
{
}


NoThreadAtomicOpMgr::~NoThreadAtomicOpMgr()
{
}


// Atomic operations
void*
NoThreadAtomicOpMgr::compareAndSwap(void**            toFill
							 , const void* const newValue
							 , const void* const toCompare)
{
    void *retVal = *toFill;
    if (*toFill == toCompare)
        *toFill = (void *)newValue;
    return retVal;
}


int
NoThreadAtomicOpMgr::increment(int &location)
{
    return ++location;
}


int
NoThreadAtomicOpMgr::decrement(int &location)
{
    return --location;
}


XERCES_CPP_NAMESPACE_END