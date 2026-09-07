/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
         int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &x,auto&y){
            return x.start<y.start;
        });
        priority_queue<int, vector<int>,greater<int>>minh;
        for(auto& x:intervals){
            if(!minh.empty() && minh.top()<= x.start)
            minh.pop();
            minh.push(x.end);
        }
        return minh.size();
    }
};
