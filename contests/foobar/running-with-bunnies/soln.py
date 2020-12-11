import itertools
import copy


# Standard Floyd-Warshall
def floyd_warshall(graph):
    res = copy.copy(graph)

    V = len(graph)
    for k in range(V):
        for i in range(V):
            for j in range(V):
                res[i][j] = min(res[i][j], res[i][k] + res[k][j])

    return res


# If we can still relax any edges after Floyd-Warshall, then we have a negative cycle.
def check_neg_cycle(dist):
    V = len(dist)
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    return True
    return False


def solution(times, times_limit):
    dist = floyd_warshall(times)

    if check_neg_cycle(dist):
        return range(len(times)-2)

    res = []
    total_bunnies = len(times) - 2

    for cur_num_bunnies in range(1, total_bunnies + 1):
        cur_res = []
        for bunny_ids in itertools.combinations(range(total_bunnies), cur_num_bunnies):
            for id_order in itertools.permutations(bunny_ids):
                bunny_nodes = [id+1 for id in id_order]

                order = [0]
                order.extend(bunny_nodes)
                order.append(len(times)-1)

                time = 0
                for i in range(1, len(order)):
                    u, v = order[i-1], order[i]
                    time += dist[u][v]

                # Possible solution found
                if time <= times_limit:
                    cur_res.append(sorted(id_order))

        if len(cur_res) > 0:
            res = cur_res

    return list(min(res))
