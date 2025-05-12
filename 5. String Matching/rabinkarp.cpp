#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int d = 256;  // Number of characters in the input alphabet
const int q = 101;  // A prime number for modulus to avoid overflow

// Rabin-Karp algorithm to find all occurrences of a pattern in a text
void rabinKarp(string text, string pattern) {
    int m = pattern.length();
    int n = text.length();
    int i, j;
    int patternHash = 0;  // Hash value for pattern
    int textHash = 0;     // Hash value for text
    int h = 1;

    // The value of h would be "pow(d, m-1)%q"
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of the pattern and the first window of the text
    for (i = 0; i < m; i++) {
        patternHash = (d * patternHash + pattern[i]) % q;
        textHash = (d * textHash + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++) {
        // Check the hash values of current window of text and pattern. If the hash values match then only check for characters one by one
        if (patternHash == textHash) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            // If pattern is found
            if (j == m) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < n - m) {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % q;

            // We might get negative value of textHash, so converting it to positive
            if (textHash < 0) {
                textHash = (textHash + q);
            }
        }
    }
}

int main() {
    string text, pattern;

    // Input text and pattern
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    // Call Rabin-Karp algorithm to find pattern in the text
    rabinKarp(text, pattern);

    return 0;
}