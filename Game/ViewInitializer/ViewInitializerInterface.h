#ifndef CODE_VIEWINITIALIZERINTERFACE_H
#define CODE_VIEWINITIALIZERINTERFACE_H

#include <vector>
#include <string>

class ViewInitializerInterface {
public:
    virtual void init() = 0;
    virtual ~ViewInitializerInterface() = default;
};

#endif //CODE_VIEWINITIALIZERINTERFACE_H
