class Solution {
public:
    bool rotateString(string s, string goal) {
        bool isFound = (s + s).find(goal) != string::npos;
        return s.size() == goal.size() && isFound;
    }
};