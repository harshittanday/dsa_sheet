class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (mid - 1 >= 0 and mid + 1 <= nums.size() - 1 and nums[mid] < nums[mid + 1] and nums[mid] < nums[mid - 1])
            {
                return nums[mid];
            }
            if (nums[mid] > nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return nums[start];
    }
};