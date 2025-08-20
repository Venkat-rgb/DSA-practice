/**
 * The function `arrayRankTransform` takes a vector of integers, assigns ranks to each unique element
 * in the vector, and returns a new vector with the ranks corresponding to the elements in the original
 * vector.
 * 
 * @param arr arr is a vector of integers that you want to transform by assigning ranks to each unique
 * element in the array based on their order of appearance.
 * 
 * @return The function `arrayRankTransform` returns a vector of integers, where each element
 * represents the rank of the corresponding element in the input vector `arr`.
 */
vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();

    map <int, int> mp;
    for(int i = 0; i < n; ++i) {
        mp[arr[i]] = i;
    }

    int rank = 1;
    for(auto it : mp) {
        mp[it.first] = rank;
        rank++;
    }

    vector <int> res;
    for(int i = 0; i < n; ++i) {
        res.push_back(mp[arr[i]]);          
    }
    return res;
}