class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // store the index
        vector<int> nextsmaller(arr.size(), -1); // smaller
        vector<int> prevsmaller(arr.size(), -1); // equal or smaller
        for(int i = 0; i < arr.size(); ++i) {
            nextsmaller[i] = -1;
            prevsmaller[i] = -1;
        }
        stack<int> st;
        
        for(int i = 0; i < arr.size(); ++i) { // keep elements in monotonically increasing order
            while(!st.empty() && arr[st.top()] > arr[i]) {
                nextsmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }        
        
        while(!st.empty()) st.pop();
        
        //find previous element smaller or equal to the current element 
        for(int i = 0; i < arr.size(); ++i) { // keep elements in monotonically increasing order
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if(!st.empty()) prevsmaller[i] = st.top();
            st.push(i);
        }

        long res = 0;
        long mod = 1e9+7;
        for(int i = 0; i < arr.size(); ++i) {
            long leftbrackets = (prevsmaller[i] == -1) ? i+1 : (i-prevsmaller[i]);
            long rightbrackets = (nextsmaller[i] == -1) ? arr.size()-i : (nextsmaller[i]-i);
            // cout << leftbrackets * rightbrackets << " " ;

            res += leftbrackets*rightbrackets*arr[i];
            res %= mod;
        }
                    // cout << endl;
        // for(int i = 0; i < arr.size(); ++i) {
        //     cout << nextsmaller[i] << ", " << prevsmaller[i] << "\n";
        // }
        return res;
    }
};
