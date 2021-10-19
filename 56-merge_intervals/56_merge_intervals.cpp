class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ret;
        for(auto interval : intervals){
            if(ret.empty() || ret.back()[1] < interval[0]){
                ret.push_back(interval);
            }else{
                ret.back()[1] = max(ret.back()[1], interval[1]);
            }
        }
        
        return ret;
        /*
        //<intuitive solution>
        int ptr1 = 0, ptr2 = 1;
        while(ptr2 < intervals.size()){
            if(intervals[ptr1][1] < intervals[ptr2][0]){
                ptr1 = ptr2++;
            }else{
                if(intervals[ptr2][1] > intervals[ptr1][1]){
                    intervals[ptr1][1] = intervals[ptr2][1];
                }
                intervals.erase(intervals.begin()+ptr2);
            }
        }
        return intervals;
        
        gets TLS on last test case
        */
    }
};
