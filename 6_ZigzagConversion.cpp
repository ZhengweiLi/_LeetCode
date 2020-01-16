class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<2) return s;
        int n=s.size();
        int step=2*numRows-2;
        string res;
        for(int i=0;i<numRows;i++){
            for(int j=i;j<n;j+=step){
                res+=s[j];
                int k=j+step-2*i;
                if(i!=0&&i!=numRows-1&&k<n){
                    res+=s[k];
                }
            }
        }
        return res;
    }
};
