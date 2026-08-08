class Solution {
 public:
  string smallestNumber(string num, long long t) {
    auto [need, ok] = primeCountOf(t);
    if (!ok) return "-1";

    unordered_map<int,int> fullFactors = toDigits(need);
    if ((int)sumVals(fullFactors) > (int)num.size())
      return build(fullFactors);                    // must extend by 1 digit anyway

    // running total of factors contributed by suffix num[i..]
    unordered_map<int,int> prefixHave = primeCountOfDigits(num);
    int firstZero = num.find('0');
    if (firstZero == string::npos) {
      firstZero = num.size();
      if (isSubset(need, prefixHave)) return num;    // already valid
    }

    for (int i = (int)num.size() - 1; i >= 0; --i) {
      int d = num[i] - '0';
      prefixHave = sub(prefixHave, digitFactors(d));  // remove this digit's contribution
      int space = num.size() - 1 - i;                 // slots strictly after position i
      if (i > firstZero) continue;                    // can't fix past a leading 0

      for (int bigger = d + 1; bigger <= 9; ++bigger) {
        auto remaining = sub(sub(need, prefixHave), digitFactors(bigger));
        auto factors = toDigits(remaining);
        int used = sumVals(factors);
        if (used <= space) {
          int ones = space - used;
          return num.substr(0, i) + char('0' + bigger) +
                 string(ones, '1') + build(factors);
        }
      }
    }

    // no fix of the same length exists -> extend by one digit
    auto factors = toDigits(need);
    return string(num.size() + 1 - sumVals(factors), '1') + build(factors);
  }

 private:
  unordered_map<int,int> digitFactors(int d) {
    static const unordered_map<int, unordered_map<int,int>> m = {
      {0,{}}, {1,{}}, {2,{{2,1}}}, {3,{{3,1}}}, {4,{{2,2}}},
      {5,{{5,1}}}, {6,{{2,1},{3,1}}}, {7,{{7,1}}}, {8,{{2,3}}}, {9,{{3,2}}}};
    return m.at(d);
  }

  pair<unordered_map<int,int>, bool> primeCountOf(long long t) {
    unordered_map<int,int> c{{2,0},{3,0},{5,0},{7,0}};
    for (int p : {2,3,5,7})
      while (t % p == 0) { t /= p; c[p]++; }
    return {c, t == 1};
  }

  unordered_map<int,int> primeCountOfDigits(const string& s) {
    unordered_map<int,int> c{{2,0},{3,0},{5,0},{7,0}};
    for (char ch : s)
      for (auto& [p, f] : digitFactors(ch - '0')) c[p] += f;
    return c;
  }

  // Turn a needed {2:a,3:b,5:c,7:d} exponent requirement into the fewest digits.
  unordered_map<int,int> toDigits(const unordered_map<int,int>& need) {
    int e2 = need.count(2) ? need.at(2) : 0;
    int e3 = need.count(3) ? need.at(3) : 0;
    int e5 = need.count(5) ? need.at(5) : 0;
    int e7 = need.count(7) ? need.at(7) : 0;

    int c8 = e2 / 3, r2 = e2 % 3;
    int c9 = e3 / 2, c3 = e3 % 2;
    int c4 = r2 / 2, c2 = r2 % 2;

    int c6 = 0;
    if (c2 == 1 && c3 == 1) { c2 = 0; c3 = 0; c6 = 1; }
    if (c3 == 1 && c4 == 1) { c2 = 1; c6 = 1; c3 = 0; c4 = 0; }

    return {{2,c2},{3,c3},{4,c4},{5,e5},{6,c6},{7,e7},{8,c8},{9,c9}};
  }

  string build(const unordered_map<int,int>& f) {
    string r;
    for (int d = 2; d <= 9; ++d)
      r += string(f.count(d) ? f.at(d) : 0, char('0' + d));
    return r;
  }

  bool isSubset(const unordered_map<int,int>& need, const unordered_map<int,int>& have) {
    for (auto& [k, v] : need)
      if ((have.count(k) ? have.at(k) : 0) < v) return false;
    return true;
  }

  unordered_map<int,int> sub(unordered_map<int,int> a, const unordered_map<int,int>& b) {
    for (auto& [k, v] : b) a[k] = max(0, (a.count(k) ? a[k] : 0) - v);
    return a;
  }

  int sumVals(const unordered_map<int,int>& m) {
    int s = 0;
    for (auto& [k, v] : m) s += v;
    return s;
  }
};