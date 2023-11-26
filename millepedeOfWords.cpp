#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool solution(const std::vector<std::string>& words) 
    {
    vector<string> wordsCopy(words.begin(), words.end());
    sort(begin(wordsCopy), end(wordsCopy));
    int count{0};
    do
    {
        for (auto i = begin(wordsCopy); i != prev(end(wordsCopy)); i++)
        {
            if ((*i).back() == (*next(i)).front())
                count++;
            else
            {
                count = 0;
                break;
            }
        }
        if (count == wordsCopy.size() - 1)
            return true;
    } while (next_permutation(begin(wordsCopy), end(wordsCopy)));

    return false;
    }
};

int main()
{
    Solution sol;
    vector<string> str {"excavate", "endure", "screen", "desire", "theater", "excess", "night"};
    vector<string> art;
    bool res = sol.solution(str);
    if (res) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    
    return 0;
}