class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {

        vector<vector<int>> ans;
        vector<pair<int,int>> merge;

        sort(occupiedIntervals.begin(),occupiedIntervals.end());

        pair<int,int> temp={-1,-1};
        for(auto it:occupiedIntervals){
            int start=it[0];
            int end=it[1];
            if(temp.first==-1 && temp.second==-1){
                temp.first=start;
                temp.second=end;
            }
            else if(temp.second>end){
                continue;
            }
            else if(temp.second>=start){
                temp.second=end;
            }
            else if((temp.second+1)==start){
                temp.second=end;
            }
            else{
                merge.push_back(temp);
                temp.first=start;
                temp.second=end;
            }
        }
        if(temp.first!=-1){
            merge.push_back(temp);
        }
        for(auto it: merge){
            int start=it.first;
            int end=it.second;

            cout<<start<<" "<<end<<endl;

            if(freeStart<=start && freeEnd>=end){
                continue;
            }
            else if(freeStart<=start && freeEnd<=end && freeEnd>=start){
                
                start=freeEnd+1;
                ans.push_back({start,end});
            }
            else if(freeStart<=end && freeEnd>=end){
                end=freeStart-1;
                ans.push_back({start,end});
            }
            else if(freeStart>start && freeEnd<end){
                int newStart=freeEnd+1;
                int newEnd=end;
                int end=freeStart-1;
                ans.push_back({start,end});
                ans.push_back({newStart,newEnd});
            }
            else{
                ans.push_back({start,end});
            }
            cout<<start<<" "<<end<<endl;
            
        }

     

        return ans;
        
    }
};