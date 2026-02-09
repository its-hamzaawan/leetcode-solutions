class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
     vector<pair<int,double>> cars;
     for(int i =0;i<n;i++){
        double time = double(target - position[i])/speed[i];
        cars.push_back({position[i],time});
     }
sort(cars.begin(),cars.end(),greater<>()); // pair in descending order like 5,3,1
     stack<double> st;
     for(int i=0;i<n;i++){
        double currTime = cars[i].second;
        if(st.empty() || currTime > st.top()){
            st.push(currTime);
        }

     }
     return st.size();
    }
};