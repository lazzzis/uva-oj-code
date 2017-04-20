#include <iostream>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Did{
    int passage, ln;
    string line;
    bool operator < (const Did& d1) const {
        if (d1.passage != passage) {
            return d1.passage > passage;
        }
        return d1.ln > ln;
    }
};

Did newDid(int passage, int ln, string line) {
    Did d;
    d.passage = passage;
    d.ln = ln;
    d.line = line;
    return d;
}

map<string, set<Did>> words;

vector<string> passages;

int N;

void init() {
    words.clear();
    passages.clear();
}

void gen_bucket(string line, int passage, int ln) {
    set <string> ln_words; // one line might contain multiple identical words.
    string ori_line = line;
    for (int j = 0; j < line.size(); j ++) {
        if (isalpha(line[j])) {
            line[j] = tolower(line[j]);
        } else {
            line[j] = ' ';
        }
    }
    stringstream ss(line);
    string word;
    while (ss >> word) {
        ln_words.insert(word);
    }
    for (set<string>::iterator it = ln_words.begin(); it != ln_words.end(); it ++) {
        if (!words.count(*it)) {
            set<Did> s;
            words[*it] = s;
        }
        words[*it].insert(newDid(passage, ln, ori_line));
    }
}

void lst_did(set<Did> &dids) {
    map<int, vector<Did>> m;
    for (set<Did>::iterator it = dids.begin(); it != dids.end(); it ++) {
        if (!m.count(it->passage)) {
            std::vector<Did> v;
            m[it->passage] = v;
        }
        m[it->passage].push_back(*it);
    }
    vector<vector<Did>> v;
    for (int i = 0; i < N; i ++) {
        if (m.count(i)) {
            v.push_back(m[i]);
        }
    }
    for (int i = 0; i < v.size(); i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            cout << v[i][j].line << endl;
        }
        if (i != v.size() - 1) {
            cout << "----------" << endl;
        }
    }
    if (v.size() == 0) {
        cout << "Sorry, I found nothing." << endl;
    }
    cout << "==========" << endl;
}

set<Did> and_union(set<Did>& f, set<Did> s) {
    set<int> fs;
    for_each(f.begin(), f.end(), [&](Did did) mutable -> void {
        fs.insert(did.passage);
    });
    set<int> ss;
    for_each(s.begin(), s.end(), [&](Did did) mutable -> void {
        ss.insert(did.passage);
    });
    set<int> ps;
    set_intersection(fs.begin(), fs.end(), ss.begin(), ss.end(), inserter(ps, ps.begin()));
    set<Did> res;
    for_each(f.begin(), f.end(), [&](Did did) mutable -> void {
        if (ps.count(did.passage)) {
            res.insert(did);
        }
    });
    for_each(s.begin(), s.end(), [&](Did did) mutable -> void {
        if (ps.count(did.passage)) {
            res.insert(did);
        }
    });
    return res;
}

void queries() {
    int M;
    cin >> M;
    cin.get();
    while (M --) {
        string q;
        getline(cin, q);
        if (q.find(" ") == -1) {
            lst_did(words[q]);
        } else if (q.find("OR") != -1 || q.find("AND") != -1) {
            stringstream ss(q);
            string first, second;
            ss >> first >> second >> second;
            set<Did>& f = words[first];
            set<Did>& s = words[second];
            set<Did> res;
            if (q.find("OR") != -1) {
                set_union(f.begin(), f.end(), s.begin(), s.end(), inserter(res, res.begin()));
            } else {
                res = and_union(f, s);
            }
            lst_did(res);
        } else if (q.find("NOT") != -1) {
            stringstream ss(q);
            string first;
            ss >> first >> first;
            set<Did>& f = words[first];
            set<int> ps;
            for_each(f.begin(), f.end(), [&](Did did) mutable -> void {
                ps.insert(did.passage);
            });
            vector<string> v;
            for (int i = 0; i < N; i ++) {
                if (!ps.count(i)) {
                    v.push_back(passages[i]);
                }
            }
            for (int i = 0; i < v.size(); i ++) {
                cout << v[i];
                if (i != v.size() - 1) {
                    cout << "----------" << endl;
                }
            }
            if (v.size() == 0) {
                cout << "Sorry, I found nothing." << endl;
            }
            cout << "==========" << endl;
        }
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N) {
        cin.get();
        init();
        for (int i = 0; i < N; i ++) {
            int ln = 0;
            string p = "";
            string line;
            while (true) {
                ln ++;
                getline(cin, line);
                if (line == "**********") {
                    break;
                }
                p += line + '\n';
                gen_bucket(line, i, ln);
            }
            passages.push_back(p);
        }
        queries();
    }
    return 0;
}
