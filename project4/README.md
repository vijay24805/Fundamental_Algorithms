


A function that performs simultaneus search for multiple patterns on a long string,
using the Rabin-Karp algorithm. The function
int multi string search(char *s, char **t, int k, int l)
has the following arguments
- the data string s in which we search,
- the array of pattern strings t,
- the number of pattern strings k,
- the length of the pattern strings l


The function returns the position of the start of the first pattern that occurs in s, or
-1 if none of the patterns occurs. We count the position from 0, so “work” occurs in
“homework” at position 4.
