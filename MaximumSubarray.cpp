// O(n)
int maxSubArray(int* nums, int numsSize) {
    int max_sum = nums[0];
    int cur_sum = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        cur_sum += nums[i];
        if (cur_sum < nums[i]) cur_sum = nums[i];
        
        if (max_sum < cur_sum ) max_sum = cur_sum ;
        
    }
    
    return max_sum;
}

// O(n log n) with divid & conquer?
// 7 WA 1AC 33 min
int maxSubArray(int* nums, int numsSize) {
    // assert(numsSize>0)
    if (numsSize==1) return nums[0];
    int mid = numsSize/2;
    // assert(mid>=1);
    // ma
    int ma = maxSubArray(nums, mid);
    // mb
    int mb = maxSubArray(nums + mid, numsSize - mid);
    // mc
    int sum[numsSize];
    sum[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum[i] = sum[i-1] + nums[i];
    }
    
    int max_l = sum[mid-1];
    for (int i = mid-2; i >= 0; i--) {
        int tmp = sum[mid-1] - sum[i];
        if (max_l < tmp) max_l = tmp;
    }
    
    int max_r = sum[numsSize-1] - sum[mid-1];
    for (int i = mid; i < numsSize - 1; i++) {
        int tmp = sum[i] - sum[mid-1];
        if (max_r < tmp) max_r = tmp;
    }
    int mc = max_l + max_r;
    // return max(ma,mb,mc)
    cout<< ma << " " <<mb << " "<<mc<< " " << max_l << " " << max_r <<endl;
    int max = ma;
    if (mb > max) max = mb;
    if (mc > max) max = mc;
    return max;
}
