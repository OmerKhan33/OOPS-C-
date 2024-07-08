// dynamic_cast 
#include <iostream> 
#include <exception> 
using namespace std; 
 
class CBase { virtual void dummy() {} }; 
class CDerived: public CBase { int a; }; 
 
int main () 
{ 
   
    CBase * pba = new CDerived; 
    CBase * pbb = new CBase; 
    CDerived * pd; 
 
    pd = dynamic_cast<CDerived*>(pba); 
    if (pd==0) cout << "Null pointer on first type-cast" << endl; 
 
    pd = dynamic_cast<CDerived*>(pbb); 
    if (pd==0) cout << "Null pointer on second type-cast" << endl; 

    return 0; 
} 
// The code tries to perform two dynamic casts from pointer objects of type CBase* (pba and pbb) 
// to a pointer object of type CDerived*, but only the first one is successful.

// Even though both are pointers of type CBase*, pba points to an object of type CDerived, 
// while pbb points to an object of type CBase. Thus, when their respective type-castings are 
// performed using dynamic_cast, pba is pointing to a full object of class CDerived, whereas pbb is 
// pointing to an object of class CBase, which is an incomplete object of class CDerived. 
// When dynamic_cast cannot cast a pointer because it is not a complete object of the required class -as in the second conversion in the previous example- it returns a null pointer to indicate the 
// failure.