class Solution {
public:
    vector<string> result;

    void dfs(string& num, int target, int index, long currVal, long prev,
             string path) {
        if (index == num.size()) {
            if (currVal == target) {
                result.push_back(path);
            }
            return;
        }
        for (int i = index; i < num.size(); i++) {
            if (i != index && num[index] == '0') break;
            string part = num.substr(index, i - index + 1);
            long val = stol(part);
            if (index == 0) {
                dfs(num, target, i + 1, val, val, part);
            } else {
                dfs(num, target, i + 1, currVal + val, val,
                    path + "+" + part);
                dfs(num, target, i + 1, currVal - val, -val,
                    path + "-" + part);
                dfs(num, target, i + 1,
                    currVal - prev + (prev * val),
                    prev * val,
                    path + "*" + part);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        dfs(num, target, 0, 0, 0, "");
        return result;
    }
};