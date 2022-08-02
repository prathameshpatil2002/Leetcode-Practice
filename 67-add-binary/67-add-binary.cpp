class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();
        
        if(n1<n2){
            reverse(a.begin(),a.end());
            while(n2!=a.length()){
                a.push_back('0');
            }
            reverse(a.begin(),a.end());
        }
        else if(n2<n1){
            reverse(b.begin(),b.end());
            while(n1!=b.length()){
                b.push_back('0');
            }
            reverse(b.begin(),b.end());
        }
        int c = 0;
        string ret = "";
        for(int i=a.length()-1; i>=0; i--){
            if(a[i]=='0'&&b[i]=='0'&&c==0){
                ret.push_back('0');
            }
            else if(a[i]=='0'&&b[i]=='1' && c==0){
                ret.push_back('1');
            }
            else if(a[i]=='1'&&b[i]=='0'&&c==0){
                ret.push_back('1');
            }else if(a[i]=='0'&&b[i]=='0'&&c==1){
                ret.push_back('1');
                c = 0;
            }
            else if(a[i]=='1'&&b[i]=='1'&&c==0 ){
                ret.push_back('0');
                c=1;
            }
            else if(a[i]=='0'&&b[i]=='1'&&c==1 ){
                ret.push_back('0');
                c = 1;
            }
            else if(a[i]=='1'&&b[i]=='0'&&c==1 ){
                ret.push_back('0');
                c=1;
            }
            else if(a[i]=='1'&&b[i]=='1'&&c==1){
                ret.push_back('1');
                c = 1;
            }
        }
        if(c==1){
            ret.push_back('1');
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};