class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m > n)
        {
            swap(nums1, nums2);
            swap(m, n);
        }

        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while(iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i<iMax && nums2[j - 1]>nums1[i])
            {
                iMin = iMin + 1; // i is too small
            }
            else if (i > iMin && nums1[i - 1] > nums2[j])
            {
                iMax = iMax - 1; // i is too big
            }
            else
            { // i is perfect
                int maxLeft = 0;
                if (0 == i) 
                {
                    maxLeft = nums2[j - 1];
                }
                else if (j == 0)
                {
                    maxLeft = nums1[i - 1];
                }
                else
                {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }
                if (1 == (m + n) % 2)
                {
                    return maxLeft;
                }

                int minRight = 0;
                if (m == i)
                {
                    minRight = nums2[j];
                }
                else if (n == j)
                {
                    minRight = nums1[i];
                }
                else
                {
                    minRight = min(nums2[j], nums1[i]);
                }

                return (maxLeft + minRight) / 2.0;
            }
        }

        return 0.0;     
    }
};