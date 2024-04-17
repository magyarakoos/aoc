using DataStructures
g = Dict{String, Vector{String}}()
vis = Dict{String, Int}(); ans = []
dfs = (u, i) -> begin
    if u == "end"
        global p1 += 1
    end
    if islowercase(u[1])
        vis[u] += 1
    end
    for v in g[u]
        if vis[v] < i dfs(v) end
    end
    if islowercase(u[1])
        vis[u] -= 1
    end
end
for l in eachline("input")
    v = split(l, "-")
    for x in v
        if !haskey(g, x)
            g[x] = []
        end
    end
    push!(g[v[1]], v[2])
    push!(g[v[2]], v[1])
end
dfs("start")
println(p1)