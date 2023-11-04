class Solution {
public:
    int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) {
        // Find the farthest position among ants moving to the left.
        // If 'left' is empty, set maxLeft to 0.
        int maxLeft = left.empty() ? 0 : *std::max_element(left.begin(), left.end());

        // Find the nearest position among ants moving to the right.
        // If 'right' is empty, set minRight to the right end of the plank (n).
        int minRight = right.empty() ? n : *std::min_element(right.begin(), right.end());

        // Calculate the time when the last ant(s) fall.
        // The last ant(s) to fall will be at the maximum position from the left or
        // the maximum position from the right end of the plank.
        return std::max(maxLeft, n - minRight);
    }
};