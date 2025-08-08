class Solution {
    public char findKthBit(int n, int k) 
    {
        if( k==1 )
            return '0';
        int l = (1<<n) -1 ;
        int mid = (l+1)/2;
        System.out.println(l+" "+mid);
        if( k==mid )
            return '1';
        else if( k < mid)
            return findKthBit(n-1,k);
        else
            return findKthBit(n-1, l - k +1 ) == '0' ? '1' : '0';
    }
}