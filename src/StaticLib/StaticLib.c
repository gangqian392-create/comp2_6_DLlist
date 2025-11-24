#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->pPrev = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
	l->footer = NULL;
}

// 先頭にデータを追加
void push_front(list* l, node* p)
{
    if (!l || !p) return;

    p->pPrev = NULL;
    p->pNext = l->header;

    if (l->header != NULL) {
        l->header->pPrev = p;
    } else {
        // リストが空なら footer も更新
        l->footer = p;
    }

    l->header = p;
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
    if (!l || !p) return;

    p->pNext = NULL;
    p->pPrev = l->footer;

    if (l->footer != NULL) {
        l->footer->pNext = p;
    } else {
        // リストが空なら header も更新
        l->header = p;
    }

    l->footer = p;
}

// p のノードを削除
void remove_node(list* l, node* p)
{
    if (!l || !p) return;

    if (p->pPrev)
        p->pPrev->pNext = p->pNext;
    else
        l->header = p->pNext;

    if (p->pNext)
        p->pNext->pPrev = p->pPrev;
    else
        l->footer = p->pPrev;

    p->pNext = NULL;
    p->pPrev = NULL;
}

// p の次のノードを削除
void remove_next(list* l, node* p)
{
    if (!l || !p) return;
    if (!p->pNext) return;

    remove_node(l, p->pNext);
}

// p の前のノードを削除
void remove_prev(list* l, node* p)
{
    if (!l || !p) return;
    if (!p->pPrev) return;

    remove_node(l, p->pPrev);
}

