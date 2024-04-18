using Combinatorics
f = map(l -> match(r".{6}(.[A-Z]).{15}(\d+).{24}\s+(.*)", l), readlines("input"))
rates = Dict{String, Int}(); g = Dict{String, Vector{String}}()
visit = Vector{String}()
for m in f
    rates[m[1]] = parse(Int, m[2])
    g[m[1]] = Vector{String}()
    for v in split(m[3], ", ")
        push!(g[m[1]], v)
    end
    if rates[m[1]] != 0
        push!(visit, m[1])
    end
end

# floyd-warshall on non-zero width pipes O(n^3)
n = length(visit)
dist = Dict{String, Dict{String, Int}}()
for u in visit
    dist[u] = Dict{String, Int}()
end
for u in visit, v in visit
    if u == v
        dist[u][v] = 0
    elseif v ∈ g[u]
        dist[u][v] = 1
    else
        dist[u][v] = Int(1e9)
    end
end
for u in visit, v in visit, k in visit
    if dist[u][k] + dist[k][v] < dist[u][v]
        dist[u][v] = dist[u][k] + dist[k][v]
    end
end

for (k, ux) in g
    for 
end
for u in visit, v in visit
    if dist[u][v] != Int(1e9) && u != v
        println("$u $v $(dist[u][v])")
    end    
end