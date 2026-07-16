class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<n;i++){
            double r = (double)val[i]/wt[i];
            pq.push({r,wt[i]});
        }
        double sum = 0;
        double t;
        while(capacity>0 && !pq.empty()){
            double p1 = pq.top().first * pq.top().second;
            double p2 =  pq.top().first * capacity;
            if(p1<=p2){
                sum += p1;
                capacity -= pq.top().second;
                pq.pop();
            }
            else{
                sum+=p2;
                capacity -= capacity;
                pq.pop();
            }
        }
        return sum;
    }
};
