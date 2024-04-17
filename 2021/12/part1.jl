g = Dict{String, Vector{String}}()
for line in eachline("input")
    nodes = split(line, "-")
    node = nodes[1]
    adjacent_node = nodes[2]
    if !haskey(g, node)
        g[node] = []
    end
    push!(g[node], adjacent_node)
end
println(g)
