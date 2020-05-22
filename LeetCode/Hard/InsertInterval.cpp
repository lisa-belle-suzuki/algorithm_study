class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //newIntervalの上限と下限が含まれているIntervalIdxを取得
        int upperIntIdx = -1, lowerIntIdx = -1;
        int lower = newInterval[0], upper = newInterval[1];
        for(int i=0; i<intervals.size(); i++){
            if (isNumIncludedInInterval(lower, intervals[i])){
                lowerIntIdx = i;
            }
            if (isNumIncludedInInterval(upper, intervals[i])){
                upperIntIdx = i;
            }
        }
        
        vector<vector<int>> ans;
        vector<int> mergedInterval;
        // 両方含まれている場合
        if (lowerIntIdx != -1 && upperIntIdx!=-1){
            for(int i=0; i<lowerIntIdx; i++){
                ans.push_back(intervals[i]);
            }
            mergedInterval = {intervals[lowerIntIdx].front(), intervals[upperIntIdx].back()};
            ans.push_back(mergedInterval);
            for(int i=upperIntIdx+1; i<intervals.size(); i++){
                ans.push_back(intervals[i]);
            }
            return ans;
        }
        // 下限だけ含まれている場合
        if (lowerIntIdx!=-1 && upperIntIdx==-1){
            for(int i=0; i<lowerIntIdx; i++){
                ans.push_back(intervals[i]);
            }
            mergedInterval = {intervals[lowerIntIdx].front(), upper};
            ans.push_back(mergedInterval);
            for(int i=lowerIntIdx+1; i<intervals.size(); i++){
                if (intervals[i].front() > upper){
                    ans.push_back(intervals[i]);
                }
            }
            return ans;
        }
        // 上限だけ含まれている場合
        if (lowerIntIdx==-1 && upperIntIdx!=-1){
            int i = 0;
            while(intervals[i].back()<lower){
                ans.push_back(intervals[i]);
                i++;
            }
            mergedInterval = {lower, intervals[upperIntIdx].back()};
            ans.push_back(mergedInterval);
            for(int i=upperIntIdx+1; i<intervals.size(); i++){
                ans.push_back(intervals[i]);
            }
            return ans;
        }
        // どちらも含まれていない場合
        int i = 0;
        mergedInterval = {lower, upper};
        if (intervals.size()==0){
            ans.push_back(mergedInterval);
            return ans;
        }
        while(intervals[i].back()<lower){
            ans.push_back(intervals[i]);
            i++;
            cout << "aaa" << endl;
        }
        ans.push_back(mergedInterval);
        cout << "bbb" << endl;
        for(int i=lowerIntIdx+1; i<intervals.size(); i++){
            if (intervals[i].front() > upper){
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }

    bool isNumIncludedInInterval(int num, vector<int> interval){
        if (interval.front() <= num && num <= interval.back()){
            return true;
        }else{
            return false;
        }
    }
};