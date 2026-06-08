int minSwap(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
        int a = 0, b = 1;
        for (int i = 1; i < nums1Size; ++i) {
            int x = a, y = b;
            if (nums1[i - 1] >= nums1[i] || nums2[i - 1] >= nums2[i]) {
                a = y;
                b = x + 1;
            } else {
                b = y + 1;
                if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                    a = fmin(a, y);
                    b = fmin(b, x + 1);
                }
            }
        }
        return fmin(a, b);
}
