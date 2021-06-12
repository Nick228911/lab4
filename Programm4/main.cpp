#include <iostream>
#include <vector>

using namespace std;


template<class T>
bool lesss(T a, T b) {
    if (a < b) return true;
    else return false;
}





template<class iterator, class T>
bool all_of(iterator l, iterator r, bool (&func)(T, T), T comp) {
    for (l; l != r; ++l) {
        if (!func(*l, comp)) return false;
    }
    return true;
}



template<class iterator, class T>
bool any_of(iterator l, iterator r, bool (&func)(T, T), T comp) {
    for (l; l != r; ++l) {
        if (func(*l, comp)) return true;
    }
    return false;
}



template<class iterator, class T>
bool none_of(iterator l, iterator r, bool (&func)(T, T), T comp) {
    for (l; l != r; ++l) {
        if (func(*l, comp)) return false;
    }
    return true;
}



template<class iterator, class T>
bool ant_of(iterator l, iterator r, bool (&func)(T, T), T comp) {
    int count = 0;
    for (l; l != r; ++l) {
        if (func(*l, comp)) ++count;
    }
    if (count == 1) return true;
    return false;
}



template<class iterator, class T>
bool is_sorted(iterator l, iterator r, bool (&func)(T, T)) {
    if (func(*l, *r)) {
        for (l; pref(l) != r; ++l) {
            if (!func(*l, *next(l))) return false;
        }
        return true;
    }
    if (!func(*l, *r)) {
        for (l; pref(l) != r; ++l) {
            if (func(*l, *next(l))) return false;
        }
        return true;
    }
}



template<class iterator, class T>
bool is_partitioned(iterator l, iterator r, bool (&func)(T, T)) {
    iterator l1 = l;
    iterator r1 = r;
    int fc = 0, sc = 0;
    for (l; l != r; ++l){
        if (l != l1){
            for (l1; l1 != r1; ++l1)
                if (func(*l, *l1)) ++fc;
                else ++sc;
        }
    }
    if (sc > 0 and fc > 0) return true;
    return false;
}



template<class iterator, class T>
T ind_not(iterator l, iterator r, T comp) {
    for (l; l != r; l++){
        if (*l != comp) return *l;
    }
}



template<class iterator, class T>
T find_backward(iterator l, iterator r, T comp) {
    for (r; l != r; --r) {
        if (*r == comp) return *r;
    }
}



//template<class iterator, class T>
//bool rice_of(iterator l, iterator r){
//    for (l; next(l) != r; l++){
//        if (*l >= *next(l)) return false;
//    }
//    return true;
//}



template<class iterator, class T>
bool is_palindrome(iterator l, iterator r, bool (&func)(T, T), T comp) {
    int count = 0;
    iterator lr = l;
    iterator rr = r;
    for (l; l != r; ++r) {
        ++count;
    }
    l = lr;
    if (count % 2 == 1){
        while (r != l){
            if (!lesss(*next(l), *l) and !lesss(*pref(r), *r)) return false;
            l++;
            r--;
        }
    } else {
        while (next(l) != pref(pref(r))){
            if (!lesss(*next(l), *l) and !lesss(*pref(r), *r)) return false;
            l++;
            r--;
        }
    }
    return true;
}











int main() {
    vector<int> a = {1, 3, 2, 2};


    all_of(a.begin(), a.end(), lesss, 4);


    return 0;
}
