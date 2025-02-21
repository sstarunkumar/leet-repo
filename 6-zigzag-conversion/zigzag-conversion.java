class Solution {
    public String convert(String s, int n) 
    {
        List<List<Character>> arr = new ArrayList<> ();
        for(int i=0;i<n;i++)
            arr.add( new ArrayList<>());

        int k=0;
        while(k<s.length())
        {
            for(int i=0;i<n && k<s.length();i++)
                arr.get(i).add(s.charAt(k++));
            for(int i=n-2;i>=1 && k<s.length();i--)
                arr.get(i).add(s.charAt(k++));
        }
        String asshoke="";
        for(int i=0;i<n;i++)
        {
            for(char ch:arr.get(i))
                asshoke+=ch;
        }
        return asshoke;

    }
}