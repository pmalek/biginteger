#include <string>
#include <vector>

class BigInteger
{
public:
  BigInteger(const std::string& integer);
  BigInteger(const std::vector<int>& v);
  BigInteger(const BigInteger& b);

  BigInteger factorial();

  BigInteger& operator--();
  operator std::string() const;
  operator bool() const;

  friend BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs);
  friend bool operator==(const BigInteger& lhs, const BigInteger& rhs);

protected:
  std::vector<int> data;
};

BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs);
bool operator==(const BigInteger& lhs, const BigInteger& rhs);
std::ostream& operator<<(std::ostream& os, const BigInteger& b);
