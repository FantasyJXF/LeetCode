  vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      set<vector<int> > res;

      int target = 0;
      for(size_t i = 0; i < nums.size(); i++)
      {
          if(nums[i] > 0) break;

          int l = i + 1, r = nums.size() - 1;
          target = 0 - nums[i];
          while(l < r)
          {
              if(nums[l] + nums[r] > target)
                  r--;
              else if(nums[l] + nums[r] < target)
                  l++;
              else
              {
                  res.insert({nums[i], nums[l], nums[r]});
                  //cout<<nums[i]<<" "<< nums[l]<<" " << nums[r]<<" "<<endl;
                  l++, r--;
              }
          }
      }

      return vector<vector<int> >(res.begin(),res.end());        
  }
