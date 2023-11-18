#ifndef CODE_BIMAP_H
#define CODE_BIMAP_H

#include <unordered_set>

template<typename T1, typename T2>
class BiMap { // реализовать бимап если нельзя использовать из буста
public:
    T1 rightByLeft(T2 key);
    T2 leftByRight(T1 key);
    bool containsLeft(T1 value);
    bool constRight(T2 value);
    void removeByLeft(T1 value);
    void removeByRight(T2 value);
    void setLeft(T2 key, T1 value);
    void setRight(T1 key, T2 value);
private:
    std::unordered_set<T1> lefts_;
    std::unordered_set<T2> rights_;
};


#endif //CODE_BIMAP_H
