#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <fenv.h>

int n, ntop, mx = -1;

struct dagnode_t {
    int nodeid;
    int nchilds;
    int userinfo;
    struct dagnode_t** childs;
};

struct schedarray_t {
    int ndevices;
    int* devicesizes;
};

int max(int x, int y) {
    return (x > y) ? x : y;
}

void mkval(struct dagnode_t** topnodes, int numofnodes) {
    int mxm = 0;
    for (int i = 0; i < numofnodes; ++i) {
        mxm = 0;
        mkval(topnodes[i]->childs, topnodes[i]->nchilds);
        for (int j = 0; j < topnodes[i]->nchilds; ++j) {
            mxm = max(mxm, topnodes[i]->childs[j]->userinfo);
        }
        mxm++;
        topnodes[i]->userinfo = mxm;
        mx = max(mx, mxm);
    }
}

void getans(struct dagnode_t** topnodes, int ntopnodes, struct schedarray_t* ans) {
    for (int i = 0; i < ntopnodes; ++i) {
        if (topnodes[i]->userinfo != -1 && topnodes[i]->nchilds > 0) {
            getans(topnodes[i]->childs, topnodes[i]->nchilds, ans);
        }
        if (topnodes[i]->userinfo != -1) {
            ans->devicesizes[(topnodes[i]->userinfo) - 1]++;
            topnodes[i]->userinfo = -1;
        }
    }
}

struct schedarray_t task_schedule(struct dagnode_t** topnodes, int ntopnodes) {
    struct schedarray_t ans;
    mkval(topnodes, ntopnodes);
    ans.ndevices = mx;
    ans.devicesizes = (int*)calloc(ans.ndevices, sizeof(int));
    getans(topnodes, ntopnodes, &ans);
    return ans;
}

int main() {
    int num, tmp, f, s;
    struct dagnode_t** topnodes, **nodes;
    struct schedarray_t ans;
    scanf("%d%d", &n, &ntop);
    nodes = (struct dagnode_t**)calloc(n, sizeof(struct dagnode_t*));
    topnodes = (struct dagnode_t**)calloc(ntop, sizeof(struct dagnode_t*));
    for (int i = 0; i < n; ++i) {
        nodes[i] = (struct dagnode_t*)malloc(sizeof(struct dagnode_t));
        nodes[i]->nodeid = i;
        nodes[i]->nchilds = 0;
        nodes[i]->userinfo = 0;
        nodes[i]->childs = (struct dagnode_t**)calloc(n, sizeof(struct dagnode_t*));
    }
    for (int i = 0; i < ntop; ++i) {
        scanf("%d", &tmp);
        topnodes[i] = nodes[i];
    }
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%d->%d", &f, &s);
        nodes[f]->childs[nodes[f]->nchilds++] = nodes[s];
    }
    //-----------------------------------------------------------
    ans = task_schedule(topnodes, ntop);
    for (int i = 0; i < n; ++i) {
        free(nodes[i]->childs);
        free(nodes[i]);
    }
    free(nodes);
    free(topnodes);
    for (int i = 0; i < mx; ++i) {
        printf("%d ", ans.devicesizes[i]);
    }
    free(ans.devicesizes);
    return 0;
}