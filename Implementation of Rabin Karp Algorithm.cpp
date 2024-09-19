#include <iostream>
#include <string>
using namespace std;

#define d 256  // Number of characters in the input alphabet

// Rabin-Karp Algorithm for pattern searching
void search(string pattern, string text, int q) {
    int M = pattern.length();
    int N = text.length();
    int i, j;
    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for text
    int h = 1;

    // The value of h would be "pow(d, M-1) % q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text and pattern
        if (p == t) {
            // If the hash values match, then check for characters one by one
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            // If pattern is found
            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for the next window of text
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;

            // We might get a negative value of t, convert it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    int q = 101;  // A prime number

    search(pattern, text, q);

    return 0;
}
