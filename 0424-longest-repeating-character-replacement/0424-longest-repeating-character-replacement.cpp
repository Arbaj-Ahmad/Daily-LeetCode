class Solution {
public:
    int find(vector<int> &a)
{
   int maxc=-1;
   for(int i=0;i<256;i++)
   maxc=max(maxc,a[i]);
   return maxc;
}
   int characterReplacement(string s, int k) {
       int n=s.size();
       vector<int> f(256,0);
       int low=0,high=0,res=INT_MIN;
       for(high=0;high<n;high++)
       {
           f[s[high]]++;
           int maxcnt=find(f);
           int len=high-low+1;
           int diff=len-maxcnt;
           while(diff>k)
           {
               f[s[low]]--;
               low++;
               maxcnt=find(f);
               len=high-low+1;
               diff=len-maxcnt;
           }
           len=high-low+1;
           res=max(res,len);
       }
       return res;
   }

};
