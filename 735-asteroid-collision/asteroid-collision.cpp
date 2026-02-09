class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(a) > st.top()) {
                    st.pop();              // right asteroid destroyed
                }
                else if (abs(a) == st.top()) {
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
                st.push(a);
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
