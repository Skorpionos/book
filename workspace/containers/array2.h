template <typename T>
class Array
{
public:
    explicit Array(size_t size, const T& value = T());

    Array() = default;

    Array(const Array& other);

    ~Array();
    Array& operator=(const Array& other);
    size_t size() const;
    size_t itemSize() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void Swap(Array& rhs);

    void Print() const;

private:
    size_t m_size = 0;
    size_t m_itemSize = 0;
    size_t m_dataSize = 0;
    char* m_data = nullptr;

};

template<typename T>
Array<T>::Array(size_t size, const T& value)
{
    m_size = size;
    m_itemSize = sizeof(T);
    m_dataSize = m_size * m_itemSize;

    m_data = new char[m_dataSize];

    for (size_t index = 0; index < m_size; ++index)
        new(&m_data[index * m_itemSize]) T(value);
}


template<typename T>
Array<T>::Array(const Array& other)
{
    m_size = other.size();
    m_itemSize = other.itemSize();
    m_dataSize = m_size * m_itemSize;

    m_data = new char[m_dataSize];

    for (size_t index = 0; index < m_size; ++index)
        new(&m_data[index * m_itemSize]) T(other[index]);

}

template<typename T>
Array<T>::~Array()
{
    auto index = m_size;
    while (index--)
        operator[](index).~T();
    delete[] m_data;
}

template<typename T>
void Array<T>::Swap(Array& rhs)
{
    if (this == &rhs)
        return;

    std::swap(m_size, rhs.m_size);
    std::swap(m_data, rhs.m_data);
    std::swap(m_itemSize, rhs.m_itemSize);
    std::swap(m_dataSize, rhs.m_dataSize);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
        Array<T>(other).Swap(*this);

    return *this;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
    return *reinterpret_cast<T*>(&m_data[index * m_itemSize]);
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
    return *reinterpret_cast<T*>(&m_data[index * m_itemSize]);
}

template<typename T>
size_t Array<T>::size() const
{
    return m_size;
}

template<typename T>
size_t Array<T>::itemSize() const
{
    return m_itemSize;
}

template<typename T>
void Array<T>::Print() const
{
    std::cout << "list:\n";
    for (size_t index = 0; index < m_size; ++index)
        operator[](index).Print();
    std::cout << "\n";
}