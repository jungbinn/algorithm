/* 정수 n이 주어지면, n개의 여는 괄호 "("와 n개의 닫는 괄호 ")"로 
   만들 수 있는 괄호 조합을 모두 구하시오. (시간복잡도 제한없음) */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void parenthesis (int num, int open, int close, string s, vector<string> *list)
{
    /* completed, push to the list */
    if (close == num)
    {
        (*list).push_back (s);
        return;
    }

    /* can add a opening parenthesis */
    if (open < num)
        parenthesis (num, open + 1, close, s + "(", list);

    /* can add a closing parenthesis */
    if (close < open)
        parenthesis (num, open, close + 1, s + ")", list);
}

int main ()
{
    int num;
    cin >> num;

    vector<string> list;
    parenthesis (num, 0, 0, "", &list);

    for (int i; i < list.size(); i++)
        cout << list[i] << endl;

    return 0;
}
