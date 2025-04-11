// Time complexity: O(N)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            // Handling collisions
            if (asteroids[i] < 0) {
                int size = abs(asteroids[i]);

                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                    continue;
                }

                if (st.top() < size) {
                    while (!st.empty() && (st.top() > 0 && st.top() < size)) {
                        st.pop();
                    }
                    if (st.empty() || st.top() < 0) {
                        st.push(asteroids[i]);
                    }
                    else if(st.top() == size) {
                        st.pop();
                    }
                } else if (st.top() == size) {
                    st.pop();
                }
            }
            else {
                st.push(asteroids[i]);
            }
        }

        // Storing answer in vector
        vector<int> res;

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        // Reversing the res as the stack is LIFO
        for (int i = 0; i < res.size() / 2; ++i) {
            swap(res[i], res[res.size() - i - 1]);
        }

        return res;
    }
};