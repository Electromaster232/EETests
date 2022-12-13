//
//  test151.cpp
//  EETests
//
//  Created by Adam Gilbert (student HH) on 12/5/22.
//

#include "test154.hpp"


typedef std::vector<unsigned int> Exponents;

unsigned int choose(const Exponents& sums, unsigned int n, unsigned int k)
{
  return sums[n] - (sums[n - k] + sums[k]);
}

int test154(std::string str)
{
    std::vector<std::string> v;
 
    std::stringstream ss(str);
 
    while (ss.good()) {
        std::string substr;
        getline(ss, substr, ':');
        v.push_back(substr);
    }
    //std::cout << v[0] << v[4];
    unsigned int layer     = stoi(v[0]);
    unsigned int prime1    =  stoi(v[1]);
    unsigned int exponent1 = stoi(v[2]);
    unsigned int prime2    =  stoi(v[3]);
    unsigned int exponent2 = stoi(v[4]);
    //std::cout << &v;
  //std::cin >> layer >> prime1 >> exponent1 >> prime2 >> exponent2;
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  // analyze for each number between 0 and layer how often they contain prime1 and prime2
  Exponents mulPrime1 = { 0 };
  Exponents mulPrime2 = { 0 };
  for (unsigned int x = 1; x <= layer; x++)
  {
      //std::cout << "loop1";
    auto current = x;
    unsigned int count = 0;
    // extract first prime (=2) as often as possible
    while (current % prime1 == 0)
    {
      current /= prime1;
      count++;
    }
    mulPrime1.push_back(count);

    count = 0;
    // extract second prime (=5) as often as possible
    while (current % prime2 == 0)
    {
      current /= prime2;
      count++;
    }
    mulPrime2.push_back(count);
  }

  // sum1[x] = sum of mulPrime1[0 ... x]
  Exponents sum1;
  unsigned int count = 0;
  for (auto x : mulPrime1)
  {
      //std::cout << "loop2";
    count += x;
    sum1.push_back(count);
  }

  // the same stuff for the other prime
  Exponents sum2;
  count = 0;
  for (auto x : mulPrime2)
  {
      //std::cout << "loop3";
    count += x;
    sum2.push_back(count);
  }

  unsigned long long result = 0;
  for (unsigned int i = 0; i <= layer; i++)
  {
      //std::cout << "loop4";
    // how often is each prime used by C(layer, i) ?
    auto found1 = choose(sum1, layer, i);
    auto found2 = choose(sum2, layer, i);

    // already enough ?
    if (found1 >= exponent1 && found2 >= exponent2)
    {
      // no need to enter the inner-most loop, each iteration would succeed
      result += i + 1;
      continue;
    }

    // note: abort early because of mirrored values
    for (unsigned int j = 0; j <= (i+1) / 2; j++)
    {
        //std::cout << "loop5";
      if (found1 + choose(sum1, i, j) >= exponent1 &&
          found2 + choose(sum2, i, j) >= exponent2)
      {
        // found a match
        result++;
        // left and right side are identical
        if (j < i / 2)
          result++;
      }
    }
  }

  // and we're done !
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    
  std::chrono::duration<double, std::milli> time_span = (t2 - t1);
      
      
  std::cout << result << ",";
  std::cout << time_span.count() << std::endl;
  return 0;
}
