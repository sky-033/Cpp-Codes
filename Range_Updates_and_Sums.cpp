#include <iostream>
#include <vector>
using namespace std;

struct Node {
    long long sum;
    long long lazyAdd;
    long long lazySet;
    bool hasSet;

    Node() {
        sum = 0;
        lazyAdd = 0;
        lazySet = 0;
    }
};

vector<Node> tree;
vector<long long> initial_array;

Node merge(Node a, Node b) {
    Node res;
    res.sum = a.sum + b.sum;
    return res;
}

void applySet(int id, int l, int r, long long val) {
    tree[id].sum = (r - l + 1LL) * val;
    tree[id].lazySet = val;
    tree[id].lazyAdd = 0;
}

void applyAdd(int id, int l, int r, long long val) {
    tree[id].sum += (r - l + 1LL) * val;
    if (tree[id].lazySet != 0)
        tree[id].lazySet += val;
    else
        tree[id].lazyAdd += val;
}

void push(int id, int l, int r) {
    if (l == r) return;

    int mid = (l + r) / 2;

    if (tree[id].lazySet != 0) {
        applySet(id<<1, l, mid, tree[id].lazySet);
        applySet(id<<1|1, mid+1, r, tree[id].lazySet);
        tree[id].lazySet = 0;
    }

    if (tree[id].lazyAdd != 0) {
        applyAdd(id<<1, l, mid, tree[id].lazyAdd);
        applyAdd(id<<1|1, mid+1, r, tree[id].lazyAdd);
        tree[id].lazyAdd = 0;
    }
}

void build(int id, int l, int r) {
    if (l == r) {
        tree[id].sum = initial_array[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);
    tree[id] = merge(tree[id<<1], tree[id<<1|1]);
}

void update(int id, int l, int r, int ql, int qr, long long val, int type) {
    if (ql <= l && r <= qr) {
        if (type == 1) applyAdd(id, l, r, val);
        else applySet(id, l, r, val);
        return;
    }
    push(id, l, r);

    int mid = (l + r) / 2;
    if (ql <= mid) update(id<<1, l, mid, ql, qr, val, type);
    if (qr > mid) update(id<<1|1, mid+1, r, ql, qr, val, type);

    tree[id] = merge(tree[id<<1], tree[id<<1|1]);
}

long long query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[id].sum;

    push(id, l, r);

    int mid = (l + r) / 2;
    long long res = 0;
    if (ql <= mid) res += query(id<<1, l, mid, ql, qr);
    if (qr > mid) res += query(id<<1|1, mid+1, r, ql, qr);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    tree.resize(4*n + 5);
    initial_array.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> initial_array[i];

    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b; long long x;
            cin >> a >> b >> x;
            update(1, 1, n, a, b, x, 1);
        }
        else if (type == 2) {
            int a, b; long long x;
            cin >> a >> b >> x;
            update(1, 1, n, a, b, x, 2);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }
}
