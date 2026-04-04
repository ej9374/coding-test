import heapq
import sys

input = sys.stdin.readline

v, e = map(int, input().split())
start = int(input())

graph = [[] for _ in range(v + 1)]

for _ in range(e):
    u, n_v, w = map(int, input().split())
    graph[u].append((n_v, w))

dist = [float('inf') for _ in range(v+1)]

def dijkstra(start):
    
    dist[start] = 0

    #거리, 정점
    pq = [(0, start)]

    while pq:
        d, now = heapq.heappop(pq)

        if dist[now] < d:
            continue

        for next_node, weight in graph[now]:
            cost = d + weight

            if cost < dist[next_node]:
                dist[next_node] = cost
                heapq.heappush(pq, (cost, next_node))


dijkstra(start)
for i in range(1, v+1):
    if dist[i] == float('inf'):
        print("INF")
    else:
        print(dist[i])