using DataStructures
g = Dict{String, Vector{String}}()
vis = Set(); p1 = 0
dfs = (u) -> begin
    if u == "end"
        global p1 += 1
    end
    if islowercase(u[1])
        push!(vis, u)
    end
    for v in g[u]
        dfs(v)
    end
    delete!(vis, u)
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