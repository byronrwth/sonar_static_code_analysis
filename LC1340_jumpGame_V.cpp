class Solution {
public:
    void jump( vector<int>& arr, int d,  unordered_map<int, vector<int>>& graph ) {
        
        deque<int> dq;

        for(int i=0;i < arr.size(); ++i) {

            while( dq.size() && arr[ dq.back() ] < arr[i] ) {
                int j = dq.back() ;
                dq.pop_back();
                if ( abs(i-j) <= d ) {// can jump from j to i
                    graph[j].push_back(i); // low to high: j -> i
                }
            }
            dq.push_back(i);
        }
        
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        
        vector<int> dp(n, 1);

        unordered_map<int, vector<int>> graph;
        
        
        

            
        // 左 往 右 扫一次
        jump( arr, d, graph ) ;

        // 右 往 左 扫一次
        jump( reverse( begin(arr), end(arr) ), d,  graph   ) ;


        
        return *max_element( begin(dp), end(dp) ) ;
    }
};
    



