class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxPro=nums[0];
        int minPro=nums[0];
        int ans= nums[0];
for(int i =1;i<nums.size();i++){
   int  temp=maxPro;
        maxPro=max({nums[i],nums[i]*maxPro,nums[i]*minPro});
         minPro=min({nums[i],nums[i]*temp,nums[i]*minPro});
         ans=max(ans,maxPro);
        
    }
return ans;
    }
};
