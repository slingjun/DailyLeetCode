class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> map;
        for(int i = 0; i < nums1.size(); ++i){
            map[nums1[i]] = i;
        }
        stack<int> st;
        for(int i = 0; i < nums2.size(); ++i){
            while(!st.empty() && st.top() < nums2[i]){
                res[map[st.top()]] = nums2[i];
                st.pop();
            }
            if(map.find(nums2[i])!=map.end())
            st.push(nums2[i]);
        }
        return res;
    }
};
