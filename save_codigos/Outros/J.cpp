
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node {
    int mn, mx;
};

int m;
vector<Node> seg;
vector<int> a, b;

Node mergeNode(Node x, Node y) {
    return {
        min(x.mn, y.mn),
        max(x.mx, y.mx)
    };
}

void build(int p, int l, int r) {
    if (l == r) {
        seg[p] = {a[l], b[l]};
        return;
    }

    int mid = (l + r) / 2;

    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);

    seg[p] = mergeNode(seg[p * 2], seg[p * 2 + 1]);
}

int firstBad(int p, int l, int r, int L, int R) {

    // Todo o segmento está dentro dos limites.
    if (seg[p].mn >= L && seg[p].mx <= R) {
        return -1;
    }

    if (l == r) {
        return l;
    }

    int mid = (l + r) / 2;

    int ans = firstBad(p * 2, l, mid, L, R);

    if (ans != -1) {
        return ans;
    }

    return firstBad(p * 2 + 1, mid + 1, r, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> m;

    vector<pair<int, int>> comp(n);

    for (int i = 0; i < n; i++) {
        cin >> comp[i].first >> comp[i].second;
    }

    a.resize(m + 1);
    b.resize(m + 1);

    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }

    seg.resize(4 * m + 5);

    build(1, 1, m);

    for (int i = 0; i < n; i++) {
        int l = comp[i].first;
        int r = comp[i].second;

        cout << firstBad(1, 1, m, l, r) << '\n';
    }

    return 0;
}
