char kthCharacter(int k) {
    string word = "a", nextWord = "b";
    string res = word + nextWord;

    if (res.size() >= k) {
        return res[k - 1];
    }

    while (res.size() < k) {
        for (int i = 0; i < word.size(); ++i) {
            if (nextWord[i] == 'z') {
                nextWord.push_back('a');
            } else {
                nextWord.push_back(nextWord[i] + 1);
            }
        }
        word = res;
        res += nextWord;
    }

    return res[k - 1];
}