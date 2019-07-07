#include <utility>

template<class T>
void do_math() noexcept(std::is_nothrow_copy_constructible<T>::value &&
                        std::is_nothrow_move_constructible<T>::value &&
                        std::is_nothrow_copy_assignable<T>::value &&
                        std::is_nothrow_move_assignable<T>::value &&
                        noexcept(std::declval<T>() + std::declval<T>()))
{}