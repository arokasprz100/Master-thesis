template <typename T1,typename T2>
struct mutable_pair
{
  typedef T1 first_type;
  typedef T2 second_type;

  mutable_pair():first(T1()),second(T2()){}
  mutable_pair(const T1& f,const T2& s):first(f),second(s){}
  mutable_pair(const std::pair<T1,T2>& p):first(p.first),second(p.second){}

  T1         first;
  mutable T2 second;
};