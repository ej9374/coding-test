import sys
import heapq

input = sys.stdin.readline

n = int(input())
m = int(input())

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

start_city, end_city = map(int, input().split())

distance = [float('inf')] * (n+1)
pq =[]
pre = [0] * (n+1)

heapq.heappush(pq, (0, start_city))

def func(start):
    distance[start] = 0

    while(pq):
        dist, now = heapq.heappop(pq)

        if distance[now] < dist:
            continue

        for next_node, weight in graph[now]:
            cost = dist + weight

            if distance[next_node] > cost:
                distance[next_node] = cost
                pre[next_node] = now
                heapq.heappush(pq, (cost, next_node))

func(start_city)

print(distance[end_city])

count = 0
p = []
curr = end_city
while curr != 0:
    p.append(curr)
    curr = pre[curr]

p.reverse()

print(len(p))
print(*(p))