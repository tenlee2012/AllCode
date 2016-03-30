#!/usr/bin/env python3
# coding=utf-8


class Rect:
    """
    矩形的定义
    """
    def __init__(self, l, r, h, flag):
        self.l = float(l)  # l是左下角的x坐标,
        self.r = float(r)  # r是右下角的x坐标
        self.h = float(h)  # 纵坐标
        self.flag = int(flag)  # 1是底边, -1是顶边

    def __str__(self):
        return '(l={0}, r={1}, h={2}, flag={3})'.format(
                self.l, self.r, self.h, self.flag)


class Node:
    """
    线段数的节点定义
    """
    def __init__(self, i, l, r, cover, length):
        self.i = int(i)  # 线段树数组的下标
        self.l = int(l)  # 左端点
        self.r = int(r)  # 右端点
        self.cover = int(cover)  # 覆盖的标记
        self.length = float(length)  # 覆盖的线段长度

    def __str__(self):
        return '(i={0}, l={1}, r={2}, cover={3}, length={4})'.format(
                self.i, self.l, self.r, self.cover, self.length)

rect = list()  # 矩形的数组
tree = list()  # 线段树
x = list()  # 所有横坐标值的数组


def Build(i, l, r):
    """
    线段树建树
    """
    tree.append(Node(i, l, r, 0, 0))
    if(l == r):
        return
    mid = (l + r) >> 1  # 或者(l + r) // 2
    Build(i << 1, l, mid)
    Build(i << 1 | 1, mid+1, r)


def PushUp(i):
    """
    线段树向上更新
    """
    if tree[i].cover != 0:  # 代表这段区间被完全覆盖了
        tree[i].length = x[tree[i].r+1] - x[tree[i].l]
    elif tree[i].l == tree[i].r:  # 不是线段了
        tree[i].length = 0
    else:
        tree[i].length = tree[i << 1].length\
                + tree[i << 1 | 1].length


def Update(i, l, r, val):
    """
    线段树的更新
    """
    if tree[i].l == l and tree[i].r == r:
        tree[i].cover += val
        PushUp(i)
        return
    mid = (tree[i].l + tree[i].r) >> 1
    if r <= mid:
        Update(i << 1, l, r, val)
    elif l > mid:
        Update(i << 1 | 1, l, r, val)
    else:
        Update(i << 1, l, mid, val)
        Update(i << 1 | 1, mid + 1, r, val)
    PushUp(i)


def main():
    global rect, tree, x

    n = int(input('测试用例个数: '))  # n 个测试用例
    while n != 0:  # 测试用例的循环
        n -= 1
        m = int(input('矩形个数: '))  # m个矩形
        if m == 0:
            break

        num = 0
        x = set()
        rect.clear()
        tree.clear()
        while m != 0:  # 输入m个矩形
            m -= 1
            x1 = float(input('x1: '))
            y1 = float(input('y1: '))
            x2 = float(input('x2: '))
            y2 = float(input('y2: '))
            x.add(x1)
            rect.append(Rect(x1, x2, y1, 1))
            num += 1
            x.add(x2)
            rect.append(Rect(x1, x2, y2, -1))
            num += 1
        x = sorted(x)  # 在将set转换list,同时排序
        rect = sorted(rect, key=lambda r: r.h)

        tree.append(Node(0, 0, 0, 0, 0))
        Build(1, 0, len(x) - 1)  # 线段树建树
        tree = sorted(tree, key=lambda t: t.i)

        ans = 0.0
        for i in range(num-1):
            l = x.index(rect[i].l)
            r = x.index(rect[i].r) - 1
            Update(1, l, r, rect[i].flag)
            ans += (rect[i+1].h - rect[i].h) * tree[1].length
        print(ans)


if __name__ == '__main__':
    main()

# 测试样例 1
# 1
# 0 0 1 1
# 1
# 测试样例 2
# 2
# 0 0 2 2
# 1 0 3 2
# 6
# 测试样例 3
# 2
# 0 0 2 2
# 1 1 3 3
# 7
# 测试样例 4
# 2
# 0 0 2 2
# 0 0 2 2
# 4
