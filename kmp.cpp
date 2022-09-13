#include <iostream>

using namespace std;

int main()
{
  // This piece of code computes the table
  const int m = 9; // m: length of pattern
  int LPS[100];    // Array to store info on prefix/suffix
  LPS[0] = 0;
  // char P[]="AABAACAABAA";
  char P[] = "dsgwadsgz";
  int i = 0;
  int j = 1;

  while (j < m)
  {
    if (P[i] == P[j])
    {
      LPS[j] = i + 1;
      i++;
      j++;
    }
    else if (i > 0)
      i = LPS[i - 1];
    else
    {
      LPS[j] = 0;
      j++;
    }
  }

  // Now, let's perform the search with KMP
  char T[] = "adsgwadsxdsgwadsgz";
  int n = 18;
  i = j = 0;
  while (i < n)
  {
    if (P[j] == T[i])
    {
      j++;
      i++;
    }
    if (j == m)
    {
      printf("Found pattern at index %d ", i - j);
      j = LPS[j - 1];
    }

    // mismatch after j matches
    else if (i < n && P[j] != T[i])
    {
      // Do not match LPS[0..LPS[j-1]] characters,
      // they will match anyway
      if (j != 0)
        j = LPS[j - 1];
      else
        i = i + 1;
    }
  }
}