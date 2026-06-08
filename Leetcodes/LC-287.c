int findDuplicate(int* nums, int numsSize) 
{
    int slow1, fast, slow2;
    slow1=fast=slow2=0;

    while(true)
    {
        slow1=nums[slow1];
        fast=nums[nums[fast]];
        if(slow1==fast)
        {
            break;
        }
    }

    while(true)
    {
        slow1=nums[slow1];
        slow2=nums[slow2];
        if(slow1==slow2)
        {
               return slow2;
        }
    }
}
