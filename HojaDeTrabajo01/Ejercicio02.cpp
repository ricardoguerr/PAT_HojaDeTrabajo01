#include "Ejercicio02.h"

bool Ejercicio02::isPalindrome(string& s)
{
    int a = 0;
    int aa = s.length() - 1;

    int con = 0;
    for (int i = 0; i < s.length();i++)
    {
        for (int x = 0;x < s.size();x++)
        {
            if (s[a] == s[aa])
            {
                a++;
                aa--;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
