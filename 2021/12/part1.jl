using DataStructures
g = Dict{String, Vector{String}}()
for l in eachline("input")
    v = split(l, "-")
    if !haskey(g, v[1])
        g[v[1]] = []
    end
    push!(g[v[1]], v[2])
end
vis = Set(); q = Queue(Int)
enqueue!(q, "start")
while length(q) > 0
    u = dequeue!(q)
    for v in 
end
