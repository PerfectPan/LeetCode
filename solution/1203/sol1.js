const topSort = (deg, G, items) => {
  const Q = [];
  for (const item of items) {
    if (deg[item] === 0) {
      Q.push(item);
    }
  }
  const res = [];
  while (Q.length) {
    const u = Q.shift();
    res.push(u);
    for (let i = 0; i < G[u].length; ++i) {
      const v = G[u][i];
      if (--deg[v] === 0) {
        Q.push(v);
      }
    }
  }
  return res.length == items.length ? res : [];
}

var sortItems = function (n, m, group, beforeItems) {
  const groupItem = new Array(m + 1).fill(0).map(() => []);

  // 组间和组内依赖图
  const groupGraph = new Array(m + 1).fill(0).map(() => []);
  const itemGraph = new Array(n).fill(0).map(() => []);

  // 组间和组内度数数组
  const groupDegree = new Array(m + 1).fill(0);
  const itemDegree = new Array(n).fill(0);

  const id = new Array(m + 1).fill(0).map((v, index) => index);

  // 给未分配的 item 分配一个 groupId
  for (let i = 0; i < n; ++i) {
    if (group[i] === -1) {
      group[i] = m;
    }
    groupItem[group[i]].push(i);
  }
  // 依赖关系建图
  for (let i = 0; i < n; ++i) {
    const curGroupId = group[i];
    for (const item of beforeItems[i]) {
      const beforeGroupId = group[item];
      if (beforeGroupId === curGroupId) {
        itemDegree[i] += 1;
        itemGraph[item].push(i);
      } else {
        groupDegree[curGroupId] += 1;
        groupGraph[beforeGroupId].push(curGroupId);
      }
    }
  }

  // 组间拓扑关系排序
  const groupTopSort = topSort(groupDegree, groupGraph, id);
  if (groupTopSort.length == 0) {
    return [];
  }
  const ans = [];
  // 组内拓扑关系排序
  for (const curGroupId of groupTopSort) {
    const size = groupItem[curGroupId].length;
    if (size == 0) {
      continue;
    }
    const res = topSort(itemDegree, itemGraph, groupItem[curGroupId]);
    if (res.length === 0) {
      return [];
    }
    for (const item of res) {
      ans.push(item);
    }
  }
  return ans;
};
