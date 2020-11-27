class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n * 2; ++i) {
            while (st.size() && A[st.top()] < A[i % n]) {
                res[st.top()] = A[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return res;
    }
};
