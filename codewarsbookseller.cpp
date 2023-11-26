#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class StockList  {
public:
  static string stockSummary(vector<string> &lstOfArt, vector<string> &categories) {
    if(lstOfArt.size()==0 || categories.size()==0) return "";
    unordered_map<char,int> mp;
    string strc,strn;
    for(auto&& w:lstOfArt) {
      stringstream s(w);
      s>>strc;s>>strn;
      mp[strc[0]]+=atoi(strn.c_str());
    }
    strc = "";
    for(auto&& w:categories) {
      strc = strc+"("+w+" : "+to_string(mp[w[0]])+") - ";
    }
    return strc.substr(0,strc.length()-3);
  }
};


int main()
{
    StockList cc;
    vector<std::string> art = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    std::vector<std::string> cd = {"A", "D"};
    cout<< cc.stockSummary(art,cd) << endl;
    return 0;

}