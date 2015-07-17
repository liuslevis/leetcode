// 11min, 3 WA 10CE
// Notice: faster with less WA CE
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    struct less_than_key
    {
        inline bool operator() (const Interval& struct1, const Interval& struct2)
        {
            if (struct1.start != struct2.start) {
                return (struct1.start < struct2.start);
            } else {
                return (struct1.end < struct2.end);
            }
        }
    };
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) return intervals;
        
        // sort(intervals.begin(), intervals.end(), less_than_key());
        
        sort(intervals.begin(), intervals.end(), [] (const Interval& struct1, const Interval& struct2)-> bool {
            if (struct1.start != struct2.start) {
                return (struct1.start < struct2.start);
            } else {
                return (struct1.end < struct2.end);
            }
        });

        vector<Interval> res;
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            // if i is overlap with i-1, connect
            Interval& last_interval = *(res.end()-1);
            if ( last_interval.end >= intervals[i].start ) {
                if (last_interval.end < intervals[i].end)
                    last_interval.end = intervals[i].end;
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
