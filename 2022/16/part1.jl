using Combinatorics
f = map(l -> match(r".{6}(.[A-Z]).{15}(\d+); [a-z]+\s[a-z]+\s[a-z]+\s[a-z]+\s(.*)", l), readlines("input"))
rate = Dict{String, Int}(); g = Dict{String, Vector{String}}()
visit = Vector{String}(); nodes = Vector{String}()
for m in f
    rate[m[1]] = parse(Int, m[2])
    g[m[1]] = Vector{String}()
    for v in split(m[3], ", ")
        push!(g[m[1]], v)
    end
    push!(nodes, m[1])
    if rate[m[1]] != 0
        push!(visit, m[1])
    end
end

# floyd-warshall over all nodes O(n^3)
n = length(nodes)
dist = Dict{String, Dict{String, Int}}()
for u in nodes
    dist[u] = Dict{String, Int}()
end
for u in nodes, v in nodes
    if u == v
        dist[u][v] = 0
    elseif v ∈ g[u]
        dist[u][v] = 1
    else
        dist[u][v] = Int(1e9)
    end
end
for u in nodes, v in nodes, k in nodes
    if dist[u][k] + dist[k][v] < dist[u][v]
        dist[u][v] = dist[u][k] + dist[k][v]
    end
end

# for a given order of opening non-zero width valves,
# what is the total amount of pressure released
solve = (visit) -> begin    
    t = 30 - dist["AA"][visit[1]] - 1
    res = t * rate[visit[1]]
    curr = visit[1]
    for u in visit[2:end]
        t -= dist[curr][u] + 1
        if t <= 0 break end
        res += t * rate[u]
        curr = u
    end
    return res
end

