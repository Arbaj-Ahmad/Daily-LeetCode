class Solution {
    public int maxProduct(int[] nums) {
       int max1 = 1, max2 = 1;

        for(int arr : nums){
            if(max1 <= arr){
                max2 = max1;
                max1 = arr;
            }
            else if(max2 <= arr){
                max2 = arr;
            }
        } 
      return(max1-1)*(max2-1)  ;
    }
}