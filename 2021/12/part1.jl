using DataStructures
g = Dict{String, Vector{String}}()
vis = Set()
dfs = (u) -> begin
    if islowercase(u)
        push!(vis, u)
    end
    for v in g[u]
        
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

