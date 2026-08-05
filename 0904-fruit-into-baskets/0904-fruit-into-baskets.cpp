class Solution {
public:
    int totalFruit(vector<int>& fruits ) {
        
        unordered_map<int,int> basket;
       int low=0,high=0;
       int n=fruits.size();
       int res=0;
       for(high=0;high<n;high++)
       {
           basket[fruits[high]]++;

           
           while(basket.size()>2)
           {
               basket[fruits[low]]--;
               if(basket[fruits[low]] ==0)
               basket.erase(fruits[low]);
               low++;
           }


          
               int len=high-low+1;
               res=max(res,len);
          
       }
       return res;

        
    }
};