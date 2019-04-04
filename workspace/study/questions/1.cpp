#include <iostream>
#include <vector>
#include <list>

template <template <class> class Container>
Container<std::string> ToString(Container<int> const& container)
{
    Container<std::string> result(container.size());
    for (size_t i = 0; i != container.size(); ++i)
        result.get(i) = std::to_string(container.get(i));
    return result;
}

int main()
{
    std::vector<int> list = {2, 4, 5, 6, 7, 4, 3};
    const auto x = ToString<std::vector<int>>(list);
//    for (const auto item : result)
//        std::cout << item << " ";
    std::cout << "\n";
}

//std::cout << __PRETTY_FUNCTION__ << "\n";
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>

namespace containerdisplay
{
  template<typename T, template<class,class...> class C, class... Args>
  std::ostream& operator <<(std::ostream& os, const C<T,Args...>& objs)
  {
    std::cout << __PRETTY_FUNCTION__ << '\n';
    for (auto const& obj : objs)
      os << obj << ' ';
    return os;
  }
}

template< typename K, typename V>
std::ostream& operator << ( std::ostream& os,
                const std::map< K, V > & objs )
{

  std::cout << __PRETTY_FUNCTION__ << '\n';
  for( auto& obj : objs )
  {
    os << obj.first << ": " << obj.second << std::endl;
  }

  return os;
}


int main()
{

  {
    using namespace containerdisplay;
    std::vector<float> vf { 1.1, 2.2, 3.3, 4.4 };
    std::cout << vf << '\n';

    std::list<char> lc { 'a', 'b', 'c', 'd' };
    std::cout << lc << '\n';

    std::deque<int> di { 1, 2, 3, 4 };
    std::cout << di << '\n';
  }

  std::map< std::string, std::string > m1
  {
      { "foo", "bar" },
      { "baz", "boo" }
  };

  std::cout << m1 << std::endl;