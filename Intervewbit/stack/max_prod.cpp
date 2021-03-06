//https://www.interviewbit.com/problems/maxspprod/

#include <bits/stdc++.h>
using namespace std;

void pv(vector<int> A)
{
    for (int i : A)
    {
        cout << i << " ";
    }
}

vector<long long> nxt_grt(vector<int>& A)
{
    vector<long long> ans(A.size());
    stack<long long> s;
    for (int i = A.size() - 1; i > -1; i--)
    {
        if (s.empty())
        {
            s.push(i);
            ans[i] = 0;
        }
        else
        {
            if (A[i] < A[s.top()]) //34, 35, 27, 42, 5, 28, 39, 20, 28
            {
                ans[i] = s.top();            //1 4 3 4
                s.push(i);
            }
            else
            {
                while (1)
                {
                    s.pop();
                    if (s.empty())
                    {
                        ans[i] = 0;
                        s.push(i);
                        break;
                    }
                    else if (A[i] < A[s.top()])
                    {
                        ans[i] = s.top();
                        s.push(i);
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
    }
    return ans;
}
vector<long long> pre_grt(vector<int>& A)
{
    vector<long long> ans(A.size());
    stack<long long> s;
    for (int i = 0; i < A.size(); i++)
    {
        if (s.empty())
        {
            s.push(i);
            ans[i] = 0;
        }
        else
        {
            if (A[i] < A[s.top()]) //34, 35, 27, 42, 5, 28, 39, 20, 28
            {
                ans[i] = s.top();
                s.push(i);
            }
            else
            {
                while (1)
                {
                    s.pop();
                    if (s.empty())
                    {
                        ans[i] = 0;
                        s.push(i);
                        break;
                    }
                    else if (A[i] < A[s.top()])
                    {
                        ans[i] = s.top();
                        s.push(i);
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
    }
    return ans;
}
int maxprod(vector<int> A)
{
    vector<long long> left(pre_grt(A));
    vector<long long> right(nxt_grt(A));
    long long mo = 1000000007;
    long long _max(-1);
    for (int i = 0; i < A.size(); i++)
    {
        _max = max(_max, left[i] * right[i]);
    }
    return _max%mo;
}

int main()
{
    cout << maxprod({ 1, 4, 3, 4 });
}