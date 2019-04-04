//template <class T>
//class Singleton
//{
//public:
//    static Singleton* Instance()
//    {
//        if (m_instance == nullptr)
//            m_instance = new Singleton;
//
//        return m_instance;
//    }
//
//    T& Data() { return m_data;}
//
//private:

//    Singleton() {}
//
//    static Singleton* m_instance;
//    T m_data;
//};
//
//template <class T>
//Singleton<T>* Singleton<T>::m_instance = nullptr;

template <class T>
class Singleton
{
public:
    static Singleton& Instance()
    {
        static Singleton singleton;

        return singleton;
    }

    T& Data() { return m_data;}

private:
    Singleton() {}

    Singleton(const Singleton& singleton);
    Singleton operator=(const Singleton& singleton);

    T m_data;
};

//int main()
//{
//    struct God
//    {
//        size_t id = 0;
//        std::string name;
//    };
//
//    auto& god = Singleton<God>::Instance();
//
//    god.Data().id = 1;
//    god.Data().name = "God";
//
//    std::cout << god.Data().id   << "\n";
//    std::cout << god.Data().name << "\n";
//}