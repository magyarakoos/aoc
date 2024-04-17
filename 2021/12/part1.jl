using DataStructures
g = Dict{String, Vector{String}}()
dfs = (u) -> begin

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

vis = Set()
