#include "kmp.h"

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(const std::string &pat, std::vector<int> &lps) {
//Implement here
    lps[0]=-1;
    int i=1,j=0;
    while(i<pat.size()){
        if(pat[i]==pat[j]){
        lps[i]=lps[j];
    }
    else{
        lps[i]=j;
        while(pat[i]!=pat[j]&&j!=-1){
            j=lps[j];
        }
    }
    j++;i++;
    }
    lps[pat.size()] = j;
}

// KMP search: returns vector of starting indices of pattern in text
std::vector<int> KMPSearch(const std::string &pat, const std::string &txt) {
//Implement here
    std::vector<int> h(pat.length()+1);
    std::vector<int> ret;
    computeLPSArray(pat,h);
    int i=0,j=0;
    while(i<txt.size()){
        if(txt[i]==pat[j]){
            i++;j++;
            if(j==pat.length()){
                ret.push_back(i-j);
                j=h[j];
            }
        }
        else{
            j=h[j];
            if(j==-1){
                j++;i++;
            }
        }
    }
    return ret;
}
