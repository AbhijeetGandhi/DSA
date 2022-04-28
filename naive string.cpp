#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

void search(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        {
            printf("Pattern found at index %d \n", i);
        }
    }
}

/* Driver program to test above function */
int main()
{
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";
    search(pattern, text);
    return 0;
}
