#include <bits/stdc++.h>
     
    using namespace std;
     
    /* g++ -g -fsanitize=address -lasan -std=c++11 -Dfoo_ */
     
    /* freopen("input.txt", "rt", stdin); */
    /* freopen("output.txt", "wt", stdout); */
     
    #define ALL(c)          (c).begin(), (c).end()
    #define ALLR(c)         (c).rbegin(), (c).rend()
    #define FOR(i,a,b)      for (int i=(a); i < (b); ++i)
    #define FORR(i,a,b)     for (int i=(a); i > (b); --i)
    #define FOR_ALL(i,c)    for (__typeof((c).begin()) i=(c).begin();   \
                                 i != (c).end(); ++i)
    #define FOR_ALLR(i,c)   for (__typeof((c).rbegin()) i=(c).rbegin(); \
                                 i != (c).rend(); ++i)
    #define SZ(array)       (sizeof(array)/sizeof(array[0]))
    #define lc(x)           (x<<1)     /* 2*x */
    #define rc(x)           (x<<1 | 1) /* 2*x+1 */
    #define lowbit(x)       (x & (-x)) /* 0b10100 -> 0b100 */
     
    typedef long long       LL;
    typedef map<int,int>    MII;
    typedef pair<int,int>   PII;
    typedef set<int>        SI;
    typedef vector<bool>    VB;
    typedef vector<double>  VD;
    typedef vector<int>     VI;
    typedef vector<string>  VS;
     
    /* check if a key is in container C */
    template <class C>
    inline bool in_(const typename C::key_type& k, const C& A)
    { return A.find(k) != A.end(); }
    inline bool in_(const string& s, const string& S)
    { return S.find(s) != string::npos; }
     
    /*
     * Let's write binary numbers for each element, and count the number
     * of places where each bit has a bit. If there is an odd number, no
     * matter how the set is divided, the result of XOR will have one bit in
     * the result of XOR, so there is no influence of the division. So let's
     * remove these bits from A (after taking the sum as a solution).
     *
     * Think about how to divide the rest. Consider choosing some of A as
     * a set and maximizing the xor. Since the number of standing bits in
     * each digit is even, the result of taking the xor of the other set
     * will be the same, so it is best to maximize one set anyway.
     *
     * This has already appeared as a partial problem in the past
     * Codeforces .
     *
     * Codeforces # 532 Div2 F. Ivan and Burgers-
     *
     * https://codeforces.com/blog/entry/68953
     */
     
    const int maxb = 61;
     
    int main()
    {
    #ifdef foo_
        freopen("foo", "rt", stdin);
    #endif
        ios::sync_with_stdio(false);
        cin.tie(0); cout.precision(10); cout << fixed;
        int n;
        while (cin >> n) {
            vector<LL> A(n);
            FOR(i,0,n)
                cin >> A[i];
            int cnt[maxb+1] = {0};
            /* count the occurrence of each bit */
            FORR(b,maxb,-1) FOR(j,0,n) if ((A[j]>>b) & 1)
                cnt[b] ^= 1;
            LL ans = 0;
            /* the odd count bit will be in the result */
            FORR(b,maxb,-1) if (cnt[b])
                ans += (1LL<<b);
            /* remove the bit w/ odd count */
            FORR(b,maxb,-1) FOR(j,0,n) if (((A[j]>>b) & 1) && cnt[b])
                A[j] -= (1LL<<b);
            /* find the subset w/ max XOR */
            int i = 0;
            FORR(b,maxb,-1) {
                int j = -1;
                FOR(k,i,n) if ((A[k]>>b) & 1) {
                    if (j == -1 || A[j] < A[k])
                        j = k;
                }
                if (j == -1)
                    continue;
                swap(A[i],A[j]);
                FOR(k,0,n) if (k != i && ((A[k]>>b) & 1))
                    A[k] ^= A[i];
                i++;
            }
            LL a = 0;
            FOR(j,0,i)
                a ^= A[j];
            ans += 2*a;
            cout << ans << endl;
        }
        return 0;
    }
