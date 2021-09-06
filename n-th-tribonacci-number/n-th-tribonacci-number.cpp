class Solution {
public:
    int tribonacci(int n) {
        int a0 = 0, a1 = 1, a2 = 1;
        if(n == 0) return a0;
        if(n == 1) return a1;
        if(n == 2) return a2;
        
        for(int i = 3; i <= n; i++){
            int temp = a0 + a1 + a2;
            
            a0 = a1;
            a1 = a2;
            a2 = temp;
        }
        
        return a2;
    }
};