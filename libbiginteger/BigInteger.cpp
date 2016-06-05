#include "BigInteger.h"

#include <algorithm>
#include <sstream>

BigInteger::BigInteger(const std::string& integer) : data(integer.size())
{
  std::transform(integer.rbegin(), integer.rend(), data.begin(), [](char c)
                 {
                   return c - '0';
                 });
}

BigInteger::BigInteger(const std::vector<int>& v) : data(v.rbegin(), v.rend()) {}

BigInteger::BigInteger(const BigInteger& b) : data(b.data.begin(), b.data.end()) {}

BigInteger BigInteger::factorial()
{
  BigInteger temp(*this);
  BigInteger res(*this);
  while(--temp) res = res * temp;
  return res;
}

BigInteger& BigInteger::operator--()
{
  static const BigInteger zero("0");

  auto it = data.begin();
  while (*it == 0 && it != data.end()) *it++ = 9;
  if (!(*this == zero)) --(*it);

  // remove 'leading' zero
  if(data.size() > 1 && data.back() == 0) data.resize(data.size() - 1);

  return *this;
}

BigInteger::operator std::string() const
{
  std::ostringstream oss;
  for (auto it = data.crbegin(); it != data.crend(); ++it) oss << *it;
  return oss.str();
}

BigInteger::operator bool() const
{
  static const BigInteger zero("0");
  return !(*this == zero);
}

BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs)
{
  const auto lhs_size = lhs.data.size();
  const auto rhs_size = rhs.data.size();
  std::vector<int> res(lhs_size + rhs_size, 0);

  for (size_t il = 0; il < lhs_size; ++il)
  {
    int carry = 0;
    for (size_t ir = 0; ir < rhs_size; ++ir)
    {
      res[il + ir] += carry + lhs.data[il] * rhs.data[ir];
      carry = res[il + ir] / 10;
      res[il + ir] %= 10;
    }
    res[il + rhs_size] += carry;
  }

  /*
   *const auto last0 = std::find_if(res.rbegin(), res.rend(), [](const int digit)
   *                                {
   *                                  return digit != 0;
   *                                });
   *if (last0 != res.rbegin())
   *{
   *  const auto distance_from_last_zero_til_end = std::distance(res.rbegin(), last0);
   *  res.erase(res.end() - distance_from_last_zero_til_end, res.end());
   *}
   */

  if (res.back() == 0)
  {
    auto last0 = res.end() - 1;
    while (*last0 == 0) --last0;
    res.erase(++last0, res.end());
  }
  std::reverse(res.begin(), res.end());
  return BigInteger(res);
}

bool operator==(const BigInteger& lhs, const BigInteger& rhs)
{
  if (lhs.data.size() != rhs.data.size()) return false;
  return lhs.data == rhs.data;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& b)
{
  os << std::string(b);
  return os;
}
