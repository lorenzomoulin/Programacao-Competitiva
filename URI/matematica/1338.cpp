
// Program to find the nth square free number 
#include<bits/stdc++.h> 
#include <stdlib.h>
using namespace std; 
  
// Maximum prime number to be considered for square 
// divisibility 
const unsigned long long MAX_PRIME = 10000000; 
  
// Maximum value of result. We do binary search from 1 
// to MAX_RES 
const unsigned long long MAX_RES = 2000000000l; 
  
void SieveOfEratosthenes(vector<unsigned long long> &a) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool* prime = (bool*)malloc((MAX_PRIME + 1)*sizeof(*prime)); 
    memset(prime, true, sizeof(prime)); 
  
    for (unsigned long long p=2; p*p<=MAX_PRIME; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (unsigned long long i=p*2; i<=MAX_PRIME; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Store all prime numbers in a[] 
    for (unsigned long long p=2; p<=MAX_PRIME; p++) 
        if (prime[p]) 
            a.push_back(p); 
} 
  
// Function to count integers upto k which are having 
// perfect squares as factors. i is index of next 
// prime number whose square needs to be checked. 
// curr is current number whos square to be checked. 
unsigned long long countSquares(unsigned long long i, unsigned long long cur, 
                       unsigned long long k, vector<unsigned long long> &a) 
{ 
    // variable to store square of prime 
    unsigned long long square = a[i]*a[i]; 
  
    unsigned long long newCur = square*cur; 
  
    // If value of greatest integer becomes zero 
    if (newCur > k) 
        return 0; 
  
    // Applying inclusion-exclusion principle 
  
    // Counting integers with squares as factor 
    unsigned long long cnt = k/(newCur); 
  
    // Inclusion (Recur for next prime number) 
    cnt += countSquares(i+1, cur, k, a); 
  
    // Exclusion (Recur for next prime number) 
    cnt -= countSquares(i+1, newCur, k, a); 
  
    // Final count 
    return cnt; 
} 
  
// Function to return nth square free number 
unsigned long long squareFree(unsigned long long n) 
{ 
    // Computing primes and storing it in an array a[] 
    vector <unsigned long long> a; 
    SieveOfEratosthenes(a); 
  
    // Applying binary search 
    unsigned long long low = 1; 
    unsigned long long high = MAX_RES; 
  
    while (low < high) 
    { 
        unsigned long long mid = low + (high - low)/2; 
  
        // 'c' contains Number of square free numbers 
        // less than or equal to 'mid' 
        unsigned long long c = mid - countSquares(0, 1, mid, a); 
  
        // If c < n, then search right side of mid 
        // else search left side of mid 
        if (c < n) 
            low = mid+1; 
        else
            high = mid; 
    } 
  
    // nth square free number 
    return low; 
} 
  
// Driver Program 
int main() 
{ 
    unsigned long long n = 500; 
    cout << squareFree(n) << endl; 
    return 0; 
} 

