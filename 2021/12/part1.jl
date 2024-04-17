using DataStructures
g = Dict{String, Vector{String}}()
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
println(g)
vis = Set(); q = Queue{String}(); p1 = 0
enqueue!(q, "start")
while length(q) > 0
    u = dequeue!(q)
    if u == "end"
        global p1 += 1
        continue
    end
    for v in g[u]
        if v ∈ vis continue end
        if islowercase(v[1])
            push!(vis, v)
        end
        enqueue!(q, v)
    end
end
println(p1)