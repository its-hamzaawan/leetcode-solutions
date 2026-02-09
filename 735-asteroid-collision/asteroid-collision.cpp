class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
    int n = asteroids.size();
        for (int i=0;i<n;i++) {
            bool destroyed = false;

            while (!st.empty() && asteroids[i] < 0 && st.top() > 0) {
                if (abs(asteroids[i]) > st.top()) {
                    st.pop();              // right asteroid destroyed
                }
                else if (abs(asteroids[i]) == st.top()) {
                    st.pop();              // both destroyed
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;      // left asteroid destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroids[i]);
            }
        }

        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};
