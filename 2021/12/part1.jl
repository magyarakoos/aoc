using DataStructures
g = Dict{String, Vector{String}}()
vis = Set(); ans = [0, 0]; twice = false
dfs = (u, i) -> begin
    if u == "end"
        ans[i] += 1
        return
    end
    if islowercase(u[1])
        push!(vis, 1)
    end
    for v in g[u]
        if vis[v] < i dfs(v, i) end
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
    vis[v[1]] = 0; vis[v[2]] = 0
end
vis["start"] = 1
dfs("start", 1); dfs("start", 2)
println("$(ans[1])\n$(ans[2])")