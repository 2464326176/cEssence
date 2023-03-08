/*
 * @Author: yh
 * @Date: 2023-02-02 20:46:11
 * @LastEditTime: 2023-02-02 20:59:35
 * @Description:
 * @FilePath: \cEssence\basicsProgram\stl\container\algorithms\function\function.cpp
 */
template <class InputIterator, class UnaryPredicate> bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
    while (first != last) {
        if (!pred(*first))
            return false;
        ++first;
    }
    return true;
}

template <class InputIterator, class UnaryPredicate> bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
    while (first != last) {
        if (pred(*first))
            return true;
        ++first;
    }
    return false;
}