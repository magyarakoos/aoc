g = Dict{String, Vector{String}}()
vis = Set()
for l in eachline("input")
    v = split(l, "-")
    if !haskey(g, v[1])
        g[v[1]] = []
    end
    push!(g[v[1]], v[2])
end

