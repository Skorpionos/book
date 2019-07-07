template <class T>
auto get_size(const T& item) -> decltype(item.size())
{
    return item.size();
}

template <class T>
auto get_size(const T& item) -> decltype(item.size)
{
    return item.size;
}

//template<class T, size_t (T::*)() const = &T::size>
//size_t get_size(T const& t)
//{
//    return t.size();
//}
//
//template<class T, size_t (T::*) = &T::size>
//size_t get_size(T const& t)
//{
//    return t.size;
//}

//template<class T>
//using class_method_ptr = size_t(T::*)() const;
//
//template<class T>
//using class_field_ptr = size_t T::*;
//
//template<class T, class_method_ptr<T> = &T::size>
//size_t get_size(const T& item){
//	return item.size();
//}
//
//template<class T, class_field_ptr<T> = &T::size>
//size_t get_size(const T& item) {
//	return item.size;
//}

//int main()
//{
//    std::string s{"Hello"};
//    size_t s_size = get_size(s);   // 5, вызывается метод size()
//
//    std::cout << s_size << "\n";
//
//    struct Struct
//    {
//        size_t size = 0;
//    };
//
//    Struct x{10};
//    std::cout << x.size << "\n";
//    size_t x_size = get_size(x);  // 10, читается поле size
//
//    return util::PrintComplete();
//}
