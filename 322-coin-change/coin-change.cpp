class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coi(amount+1,0);

        for(int i =0;i<=amount;i++){
            if(i == 0) continue;
            int val = INT_MAX;
            for(int j=0;j<coins.size();j++){
                //cout<<coins[j]<<" "<<i<<"\n";
                //if(i>=coins[j])cout<<coi[i-coins[j]]<<"a\n";
                if(coins[j]<=i && coi[i-coins[j]]>=0 ){
                    //cout<<val<<"a ";
                    val = min(val , 1+coi[i-coins[j]]);
                }
            }
            if(val == INT_MAX)
                coi[i] = -1;
            else
                coi[i] = val;
        }
        return coi[amount];
    }
};