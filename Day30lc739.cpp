class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> res(T.size(), 0);
        for(int i = 0; i < T.size(); ++i) {
            while(!st.empty() && T[st.top()] < T[i]) {
                int index = st.top();
                st.pop();
                res[index] = i-index;
            }
            st.push(i);
        }
        return res;
    }
    
    
};
