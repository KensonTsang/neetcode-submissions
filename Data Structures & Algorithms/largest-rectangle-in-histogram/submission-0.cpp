class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0 ; i <= n ; i++) {

            int h = (i == n)? 0 : heights[i];
            
            while (st.size() > 0 && h < heights[st.top()]) {
                int height = heights[st.top()];
                int area = 0;

                st.pop();
                if (st.size() > 0) {
                    area = height * (i - st.top() - 1);
                }
                else {
                    area = height * i;
                }

                maxArea = max(maxArea, area);

            }

            st.push(i);
        }


        return maxArea;

    }
};
