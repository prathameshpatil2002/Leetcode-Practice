class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> track(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> blocked;
        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; i++) {
            free.push(i);
        }
        sort(meetings.begin(), meetings.end());

        for (auto it : meetings) {
            int start = it[0], end = it[1];

            while (!blocked.empty() && blocked.top().first <= start) {
                int room = blocked.top().second;
                blocked.pop();
                free.push(room);
            }
            if (!free.empty()) {
                int room = free.top();
                free.pop();
                blocked.push({end, room});
                track[room]++;
            } else {
                auto [endTime, room] = blocked.top();
                blocked.pop();
                blocked.push({endTime + end - start, room});
                track[room]++;
            }
        }

        int maxC = 0, room = 0;
        for (int i = 0; i < n; i++) {
            if (track[i] > maxC) {
                maxC = track[i];
                room = i;
            }
        }
        return room;
    }
};