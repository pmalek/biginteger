#include <gtest/gtest.h>

#include "BigInteger.h"

using namespace ::testing;

TEST(BigIntegerTests, initialization_from_string1)
{
  const BigInteger big("123456789");
  EXPECT_EQ("123456789", std::string(big));
}

TEST(BigIntegerTests, initialization_from_string2)
{
  const BigInteger big("1115");
  EXPECT_EQ("1115", std::string(big));
}

TEST(BigIntegerTests, initialization_from_vector1)
{
  const std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  const BigInteger big(v);
  EXPECT_EQ("123456789", std::string(big));
}

TEST(BigIntegerTests, initialization_from_vector2)
{
  const std::vector<int> v{
      1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2,
  };
  const BigInteger big(v);
  EXPECT_EQ("111111122222", std::string(big));
}

TEST(BigIntegerTests, multiplication_works1)
{
  const BigInteger big1("2");
  const BigInteger big2("3");
  const BigInteger res = big1 * big2;
  EXPECT_EQ("6", std::string(res));
}

TEST(BigIntegerTests, multiplication_works2)
{
  const BigInteger big1("17");
  const BigInteger big2("3");
  const BigInteger res = big1 * big2;
  EXPECT_EQ("51", std::string(res));
}

TEST(BigIntegerTests, multiplication_works3)
{
  const BigInteger big1("23");
  const BigInteger big2("45");
  const BigInteger res = big1 * big2;
  EXPECT_EQ("1035", std::string(res));
}

TEST(BigIntegerTests, multiplication_works4)
{
  const BigInteger big1("354");
  const BigInteger big2("613");
  const BigInteger res = big1 * big2;
  EXPECT_EQ("217002", std::string(res));
}

TEST(BigIntegerTests, multiplication_works5)
{
  const BigInteger big1("65275");
  const BigInteger big2("32516");
  const BigInteger res = big1 * big2;
  EXPECT_EQ("2122481900", std::string(res));
}

TEST(BigIntegerTests, multiplication_works6)
{
  const BigInteger big1("123456789123456789");
  const BigInteger big2("123456789123456789");
  const BigInteger res = big1 * big2;
  EXPECT_EQ("15241578780673678515622620750190521", std::string(res));
}

TEST(BigIntegerTests, multiplication_works7)
{
  const BigInteger big1("876123765128376");
  const BigInteger big2("123456789123456789");
  const BigInteger res = big1 * big2;
  EXPECT_EQ("108163426917502900554003473744664", std::string(res));
}

TEST(BigIntegerTests, multiplication_works8)
{
  const BigInteger big1("15241578780673678515622620750190521");
  const BigInteger big2("108163426917502900554003473744664");
  const BigInteger res = big1 * big2;
  EXPECT_EQ("1648581392550760396562788765036924946456925361135917303999307129944", std::string(res));
}

TEST(BigIntegerTests, multiplication_works9)
{
  const BigInteger big1("16425507603965627887650369249464569253611359173039998581392550760396562788765036924946456925361137");
  const BigInteger big2("108163426917502900554003473744664108163426917502900554003473744664108163426917502900554003473744664");
  const BigInteger res = big1 * big2;
  EXPECT_EQ(
      "177663919130442436827971038604357684196204322180120819924773947190960702220041781395351075427175721667617668628398966232"
      "6970608681641610853834366612822407433255253308845793677170600077095926722968",
      std::string(res));
}

TEST(BigIntegerTests, double_multiplication_works1)
{
  const BigInteger big1("354");
  const BigInteger big2("613");
  const BigInteger res1 = big1 * big2;
  EXPECT_EQ("217002", std::string(res1));
  const BigInteger big3("493");
  const BigInteger res2 = res1 * big3;
  EXPECT_EQ("106981986", std::string(res2));
}

TEST(BigIntegerTests, double_multiplication_works2)
{
  const BigInteger big1("876123765128376");
  const BigInteger big2("123456789123456789");
  const BigInteger res1 = big1 * big2;
  EXPECT_EQ("108163426917502900554003473744664", std::string(res1));
  const BigInteger big3("217002");
  const BigInteger res2 = res1 * big3;
  EXPECT_EQ("23471679967951964426019861809539577328", std::string(res2));
}

TEST(BigIntegerTests, equality_works1)
{
  BigInteger big1("7");
  BigInteger big2("7");
  EXPECT_TRUE(big1 == big2);
  BigInteger big3("77");
  EXPECT_FALSE(big1 == big3);
  EXPECT_FALSE(big2 == big3);
  BigInteger big4("77");
  EXPECT_TRUE(big3 == big4);
  EXPECT_FALSE(big1 == big4);
}

TEST(BigIntegerTests, decrement_works1)
{
  BigInteger big1("7");
  --big1;
  EXPECT_EQ("6", std::string(big1));
  --big1;
  --big1;
  --big1;
  --big1;
  --big1;
  EXPECT_EQ("1", std::string(big1));
  --big1;
  EXPECT_EQ("0", std::string(big1));
}

TEST(BigIntegerTests, decrement_works2)
{
  BigInteger big1("23");
  --big1;
  EXPECT_EQ("22", std::string(big1));
  --big1;
  --big1;
  EXPECT_EQ("20", std::string(big1));
  --big1;
  EXPECT_EQ("19", std::string(big1));
}

TEST(BigIntegerTests, decrement_works3)
{
  BigInteger big1("11");
  --big1;
  EXPECT_EQ("10", std::string(big1));
  --big1;
  EXPECT_EQ("9", std::string(big1));
}

TEST(BigIntegerTests, decrement_works4)
{
  BigInteger big1("102");
  --big1;
  --big1;
  EXPECT_EQ("100", std::string(big1));
  --big1;
  EXPECT_EQ("99", std::string(big1));
  --big1;
  EXPECT_EQ("98", std::string(big1));
}

TEST(BigIntegerTests, converstion_to_bool_works)
{
  BigInteger big1("102");
  EXPECT_TRUE(big1);
  BigInteger zero("0");
  EXPECT_FALSE(zero);
  BigInteger one("1");
  EXPECT_TRUE(one);
}

TEST(BigIntegerTests_factorial, 3)
{
  BigInteger b1("3");
  EXPECT_EQ("6", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 4)
{
  BigInteger b1("4");
  EXPECT_EQ("24", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 5)
{
  BigInteger b1("5");
  EXPECT_EQ("120", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 6)
{
  BigInteger b1("6");
  EXPECT_EQ("720", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 9)
{
  BigInteger b1("9");
  EXPECT_EQ("362880", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 10)
{
  BigInteger b1("10");
  EXPECT_EQ("3628800", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 11)
{
  BigInteger b1("11");
  EXPECT_EQ("39916800", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 12)
{
  BigInteger b1("12");
  EXPECT_EQ("479001600", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 20)
{
  BigInteger b1("20");
  EXPECT_EQ("2432902008176640000", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 26)
{
  BigInteger b1("26");
  EXPECT_EQ("403291461126605635584000000", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 30)
{
  BigInteger b1("30");
  EXPECT_EQ("265252859812191058636308480000000", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 40)
{
  BigInteger b1("40");
  EXPECT_EQ("815915283247897734345611269596115894272000000000", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 45)
{
  BigInteger b1("45");
  EXPECT_EQ("119622220865480194561963161495657715064383733760000000000", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 50)
{
  BigInteger b1("50");
  EXPECT_EQ("30414093201713378043612608166064768844377641568960512000000000000", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 60)
{
  BigInteger b1("60");
  EXPECT_EQ("8320987112741390144276341183223364380754172606361245952449277696409600000000000000", std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 70)
{
  BigInteger b1("70");
  EXPECT_EQ("11978571669969891796072783721689098736458938142546425857555362864628009582789845319680000000000000000",
            std::string(b1.factorial()));
}

TEST(BigIntegerTests_factorial, 80)
{
  BigInteger b1("80");
  EXPECT_EQ(
      "71569457046263802294811533723186532165584657342365752577109445058227039255480148842668944867280814080000000000000000000",
      std::string(b1.factorial()));
}
