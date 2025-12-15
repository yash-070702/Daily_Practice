#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string strWithout3a3b(int a, int b) {
      string str="";
      if(a>=b && a>1){
      str+="aa";
        a-=2;
      }
      else if (a>=b && a==1){
      str+="a";
      a--;
      }
      else if(b>a && b>1){
        str+="bb";
        b-=2;
      }
      else if(b>1 && b==1){
        str+="b";
        b--;
      }

      if(str=="a")
      {
        if(b){
            str+="b";
            b--;
        }
      }
      else if(str=="b"){
        if(a){
            str+="a";
            a--;
        }
      }

      while(a && b){
      int n=str.size();
      if(str[n-1]=='a' && str[n-2]=='a'){
        str+="b";
        b--;
      }

      else if(str[n-1]=='b' && str[n-2]=='b'){
        str+="a";
        a--;
      }

       else if(a>b){
        str+="a";
        a--;
       }
       else if(b>=a){
        str+="b";
        b--;
       } 
      } 
      while(a--)
      str+="a";

      while(b--)
      str+="b";

      return str;
    }
};