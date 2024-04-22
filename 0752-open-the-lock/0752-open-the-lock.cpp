class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s(deadends.begin(), deadends.end());
        if (s.count("0000")) {
            return -1;
        }
        
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> vis;
        vis.insert("0000");
        
        while (!q.empty()) {
            auto c = q.front();
            q.pop();
            string cc = c.first;
            int moves = c.second;
            
            if (cc == target) {
                return moves;
            }
            
            for (int i = 0; i < 4; i++) {
                for (int d : {-1, 1}) {
                    int newDigit = (cc[i] - '0' + d + 10) % 10;
                    string nc = cc;
                    nc[i] = '0' + newDigit;
                    
                    if (vis.find(nc) == vis.end() && s.find(nc) == s.end()) {
                        vis.insert(nc);
                        q.push({nc, moves + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};