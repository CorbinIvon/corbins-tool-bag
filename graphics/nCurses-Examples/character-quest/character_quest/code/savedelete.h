#ifndef _FILE_SAVE_DELETE_POINTERS_
#define _FILE_SAVE_DELETE_POINTERS_

#include <stdlib.h>
#include <vector>

// --------------------------- Save delete ---------------------------

// Save delete mas
#define SAVE_DEL_MAS(vector_) \
    for(auto &mVector: vector_) \
    { \
        SAVE_DEL(mVector); \
    }

// Save delete map
#define SAVE_DEL_MAP(map_) \
    for(auto &mMap: map_) \
    { \
        SAVE_DEL(mMap.second); \
    }

// Save delete
#define SAVE_DEL(pointer_) \
    if(pointer_ != NULL) \
{ \
    delete pointer_; \
    pointer_ = nullptr; \
}

#endif // _FILE_SAVE_DELETE_POINTERS_

