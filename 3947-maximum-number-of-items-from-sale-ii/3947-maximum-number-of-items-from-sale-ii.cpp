class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        // Count frequency of each factor
        for(auto &it : items) {
            freq[it[0]]++;
            minPrice = min(minPrice, it[1]);
        }

        // Count all multiples
        vector<int> gain(n + 1, 0);

        for(int i = 1; i <= n; i++) {

            for(int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }

            gain[i]--;
        }

        // Store profitable double-value opportunities
        vector<pair<int,int>> v;

        for(auto &it : items) {

            int factor = it[0];
            int price = it[1];

            if(gain[factor] > 0 && price < 2 * minPrice) {
                v.push_back({price, gain[factor]});
            }
        }

        // Sort by price
        sort(v.begin(), v.end());

        int ans = 0;

        // Buy double-value opportunities first
        for(auto &p : v) {

            int price = p.first;
            int count = p.second;

            int take = min(count, budget / price);

            ans += take * 2;
            budget -= take * price;
        }

        // Use remaining budget for cheapest item
        ans += budget / minPrice;

        return ans;
    }
};