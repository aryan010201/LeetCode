class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string start=to_string(low);
        string end=to_string(high);
        string str="123456789";
        vector<int> ans;

        for(int i=start.length();i<=end.length();i++){
            int x=0;

            while((x+i)<=9){
                string temp=str.substr(x,i);
                int num=stoi(temp);
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
                x++;
            }
        }

        return ans;
        
    }
};