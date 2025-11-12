#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();

    int T;
    cin >> T;

    for (int whynotjustmakemoretestcases = 0; whynotjustmakemoretestcases < T;
         whynotjustmakemoretestcases++) {
        int N, C, P;
        cin >> N >> C >> P;

        vector<string> nouns;
        vector<string> conjunctions;
        vector<string> transitive;
        vector<string> intransitive;

        for (int i = 0; i < N; i++) {
            string word, type;
            cin >> word >> type;

            if (type == "noun") {
                nouns.push_back(word);
            } else if (type == "conjunction") {
                conjunctions.push_back(word);
            } else if (type == "intransitive-verb") {
                intransitive.push_back(word);
            } else {
                transitive.push_back(word);
            }
        }

        int max_words = 0;
        int best_tv = 0;
        int best_itv = 0;

        for (int i = 0; i <= transitive.size(); ++i) {
            for (int j = 0; j <= intransitive.size(); ++j) {
                if (nouns.size() >= 2 * i + j && i + j <= P + min(P, (int)conjunctions.size())) {

                    int extra_nouns = (i > 0) ? min((int)nouns.size() - (2 * i + j), C) : 0;
                    int conj_used = min((int)conjunctions.size(), (i + j) / 2);

                    int used_words = 2 * j + 3 * i + extra_nouns + conj_used;

                    if (used_words > max_words) {
                        max_words = used_words;
                        best_tv = i;
                        best_itv = j;
                    }
                }
            }
        }

        vector<string> phrases;
        int noun_at = 0;

        // Build intransitive phrases (noun + itv)
        for (int i = 0; i < best_itv; i++) {
            phrases.push_back(nouns[noun_at++] + " " + intransitive[i]);
        }

        // Build transitive phrases (noun + tv + noun)
        for (int i = 0; i < best_tv; i++) {
            phrases.push_back(nouns[noun_at++] + " " + transitive[i] + " " + nouns[noun_at++]);
        }

        // Add extra nouns to the LAST transitive phrase
        if (best_tv > 0) {
            for (int i = 0; i < C && noun_at < nouns.size(); i++) {
                phrases.back() += ", " + nouns[noun_at++];
            }
        }

        vector<string> sentences;
        int phrase_at = 0;
        int conj_at = 0;

        // Join pairs of phrases with conjunctions
        while (conj_at < conjunctions.size() && phrase_at + 1 < phrases.size()) {
            string first = phrases[phrase_at++];
            string second = phrases[phrase_at++];
            string conj = conjunctions[conj_at++];
            sentences.push_back(first + " " + conj + " " + second);
        }

        // Add any remaining single phrases
        while (phrase_at < phrases.size()) {
            sentences.push_back(phrases[phrase_at++]);
        }

        cout << max_words << "\n";
        string result_string = "";
        for (int i = 0; i < sentences.size(); i++) {
            result_string += sentences[i] + ".";
            if (i < sentences.size() - 1) {
                result_string += " ";
            }
        }
        cout << result_string << "\n";
    }
}
