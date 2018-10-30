#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <bitset>
using namespace std;

typedef long long LL;
struct Op {
    char ty;
    LL pos;
    char ins;

    bool operator==(const Op &o) const {
        if (ty != o.ty)
            return false;
        if (ty == 'D')
            return pos == o.pos;
        return pos == o.pos && ins == o.ins;
    }

    string tostring() const {
        char buf[100];
        if (ty == 'D') {
            sprintf(buf, "Del(%c %lld)", ty, pos);
            return string(buf);
        } else if (ty == 'I') {
            sprintf(buf, "Ins(%c %lld %c)", ty, pos, ins);
            return string(buf);
        } else {
            return string("BAD");
        }
    }
};
typedef vector<Op> Ops;

bool bubble(Ops &ops) {
    bool changed = false;
    for (int i = 0; i + 1 < ops.size(); i++) {
        if (ops[i].ty == 'D'  && ops[i+1].ty == 'D') {
            if (ops[i].pos <= ops[i+1].pos) {
                changed = true;
                ops[i+1].pos++;
                Op temp = ops[i];
                ops[i] = ops[i+1];
                ops[i+1] = temp;
            }
        } else if (ops[i].ty == 'I' && ops[i+1].ty == 'I') {
            if (ops[i].pos >= ops[i+1].pos) {
                changed = true;
                ops[i].pos++;
                swap(ops[i], ops[i+1]);
            }
        } else if (ops[i].ty == 'I' && ops[i+1].ty == 'D') {
            changed = true;
            if (ops[i].pos == ops[i+1].pos) {
                ops.erase(ops.begin()+i, ops.begin()+i+2);
                i--;
            } else if (ops[i].pos < ops[i+1].pos) {
                ops[i+1].pos--;
                swap(ops[i], ops[i+1]);
            } else {
                ops[i].pos--;
                swap(ops[i], ops[i+1]);
            }
        }
    }
    return changed;
}

void normalize(Ops &ops) {
    bool keep_going = true;
    while (keep_going)
        keep_going = bubble(ops);
}

Ops ops0, ops1;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string c;
    cin >> c;
    while (c != "E") {
        Op o;
        if (c == "D") {
            o.ty = 'D';
            cin >> o.pos;
        } else {
            o.ty = 'I';
            cin >> o.pos;
            cin >> o.ins;
        }
        ops0.push_back(o);
        cin >> c;
    }
    cin >> c;
    while (c != "E") {
        Op o;
        if (c == "D") {
            o.ty = 'D';
            cin >> o.pos;
        } else {
            o.ty = 'I';
            cin >> o.pos;
            cin >> o.ins;
        }
        ops1.push_back(o);
        cin >> c;
    }

    normalize(ops0);
    normalize(ops1);

    /*
    cout << "First program" << endl;
    for (auto op : ops0) {
        cout << op.tostring() << endl;
    }
    cout << "Second program" << endl;
    for (auto op : ops1) {
        cout << op.tostring() << endl;
    }
    */

    if (ops0 != ops1) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}
