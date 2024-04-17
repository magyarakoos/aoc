using DataStructures
g = Dict{String, Vector{String}}()
for l in eachline("input")
    v = split(l, "-")
    if !haskey(g, v[1])
        g[v[1]] = []
    end
    push!(g[v[1]], v[2])
end
vis = Set(); q = Queue{Int}(); p1 = 0
enqueue!(q, "start")
while length(q) > 0
    u = dequeue!(q)
    if u == "end"
        global p1 += 1
        continue
    end
    for v in g[u]
        if v ∈ vis continue end
        if isuppercase(v[1])
            push!(vis, v)
        end
        enqueue!(q, v)
    end
end
println(p1)