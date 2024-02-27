class Solution {
public:
    string simplifyPath(string path) {
         stringstream ss(path);
        vector<string> dirs;
        string dir;
        
        while (getline(ss, dir, '/')) {
            if (dir == "." || dir.empty()) {
                
            } else if (dir == "..") {
                if (!dirs.empty())
                    dirs.pop_back();
            } else {
                dirs.push_back(dir);
            }
        }
        
        string simplifiedPath = "/";
        for (const string& d : dirs) {
            simplifiedPath += d + "/";
        }
        
        if (simplifiedPath.size() > 1)
            simplifiedPath.pop_back();
        
        return simplifiedPath;
    }
};