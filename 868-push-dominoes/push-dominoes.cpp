class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        int n=dominoes.size();
        vector<int> force(n,0);
        int influence = 0;
        for(int i=0;i<n;i++)
        {
            if(dominoes[i] == 'R')
                influence = n;

            else if(dominoes[i] == 'L')
                influence = 0;

            else
            {
                if(influence > 0)
                    influence --;
            }
            force[i] = influence;
        }

        for(int i=n-1;i>=0;i--)
        {
            if(dominoes[i] == 'L')
                influence = n;
            else if(dominoes[i] == 'R')
                influence = 0;
            else 
            {
                if(influence >0)
                    influence --;
            }
            force[i] -= influence;
            if(force[i] > 0)
                dominoes[i] = 'R';
            else if(force[i] < 0)
                dominoes[i] = 'L';
            else
                dominoes[i] = '.';
        }
        return dominoes;
    }
};