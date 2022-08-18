class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int>in(numCourses,0);
        for(auto it : prerequisites){
            graph[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        
        queue<int>q;
        for(int i=0; i<numCourses;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it : graph[node]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        if(count == numCourses){
            return true;
        }
        
        return false;
        
    }
};