class Solution {
public:
    string simplifyPath(string path) {
    stack<string>st;
    string temp = "";
    for(int i = 0;i<=path.size();i++){
      if(path[i]=='/' || i == path.size()){
        if(temp==".."){
          if(!st.empty()){
            st.pop();
          }
        }
        else if(temp!="" && temp!="."){
          st.push(temp);
        }
        temp = "";
      }
      else{
        temp+=path[i];
      }
      
    }


    string str="";
    while(!st.empty()){
      str= "/" +st.top()+str;
      st.pop();
    }

    return str=="" ? "/":str;
        
    }
};