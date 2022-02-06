class Solution {
public:
    
    long long small(long long num)
{
    
    long long freq[10] = {0};
     
      
    bool pos = (num>0);
   
      
    num = abs(num);
   
    
    while (num)
    {
        long long d = num % 10; 
        freq[d]++; 
        num = num / 10; 
    }
     
    long long res = 0;
   
      
      if(pos)
    {
      
      for (long long i = 1 ; i <= 9 ; i++)
      {
          if (freq[i])
          {
              res = i;
              freq[i]--;
              break;
          }
      }
 
      
      for (long long i = 0 ; i <= 9 ; i++)
          while (freq[i]--)
              res = res * 10 + i;
    }
    else  
    {
      
      for (long long i = 9 ; i >= 1 ; i--)
      {
         if (freq[i])
         {
            res = i;
            freq[i]--;
            break;
         }
      }
       
      
      for (long long i = 9 ; i >=0 ; i--)
         while (freq[i]--)
            res = res * 10 + i;
 
      
      res = -res;
    }
    return res;
}
    
    long long smallestNumber(long long num) {
//         long long ans;
//         if(num>0){
//             string str = to_string(num);
//             sort(str.begin(), str.end());
//             int i = 0;
//             while (str[i] == '0')
//             i++;
     
//             swap(str[0], str[i]);
//             ans = stol(str, nullptr, 10);
//         }
//         if(num<0){
//             string str = to_string(abs(num));
//             sort(str.begin(), str.end());
//             reverse(str.begin(), str.end());
//             ans = stol(str, nullptr, 10);
//             ans = -ans;
//         }
//         return ans;
        return small(num);
        
    }
};