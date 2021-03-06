//------------------------------------------------------------------------------
// C++ Brian Chau Helper Library
//
// Copyright (c) Brian Chau, 2014
//
// me@brianchau.ca
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
// Author information at http://www.brianchau.ca/
//
// smartobject.h
//------------------------------------------------------------------------------

#ifndef SMARTOBJECT_H_BCLIB
#define SMARTOBJECT_H_BCLIB

#include "helpers.h"

#ifndef SMARTOBJECT_EXCEPTION
#define SMARTOBJECT_EXCEPTION "Cannot decrease reference count."
#endif

#define SMARTOBJECT virtual SmartObject

namespace bclib {

class SmartObject
{
    template<typename U> friend class SmartPointer;
    //template<typename U, typename V> friend class SmartArray;

protected:
    SmartObject() : _refcount(0) {}
    SmartObject(const SmartObject& cSource) : _refcount(0) {}

public:
    virtual ~SmartObject() {}

private:
    UINT _refcount;

    UINT GetReferenceCount() const { return _refcount; }
    void SetReferenceCount(UINT refcount) { _refcount = refcount; }
    UINT IncReferenceCount() { return ++_refcount; }

    UINT DecReferenceCount()
    {
        if (!_refcount) {
            throw SMARTOBJECT_EXCEPTION;
        }
        _refcount--;
        return _refcount;
    }
};

} // namespace bclib

#endif // SMARTOBJECT_H_BCLIB
