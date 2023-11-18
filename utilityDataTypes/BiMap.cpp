#include "BiMap.h"


template<typename T1, typename T2>
bool BiMap<T1, T2>::containsLeft(T1 value) {
    return lefts_.count(value);
}

template<typename T1, typename T2>
bool BiMap<T1, T2>::constRight(T2 value) {
    return rights_.count(value);
}


template<typename T1, typename T2>
T1 BiMap<T1, T2>::rightByLeft(T2 key) {
    if(containsLeft(key)) {
        int pos = lefts_.find(key);
        lefts_.
    }
}



//T2 rightByLeft(T2 key);
//T1 leftByRight(T1 key);
//bool containsLeft(T1 value);
//bool constRight(T2 value);
//void removeByLeft(T1 value);
//void removeByRight(T2 value);
//void setLeft(T2 key, T1 value);
//void setRight(T1 key, T2 value);