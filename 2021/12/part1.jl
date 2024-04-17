using DataStructures
g = Dict{String, Vector{String}}()
for l in eachline("input")
    v = split(l, "-")
    if !haskey(g, v[1])
        g[v[1]] = []
    end
    push!(g[v[1]], v[2])
end
vis = Set(); p1 = 0
q = Queue{String}()
push!(q, "start")
exit(0)
while length(q) > 0
    u = front(q)
    
    if u == "end"
        global p1 += 1
        continue
    end
    for v in g[u]
        if v ∈ vis continue end
        if isuppercase(v[1])
            push!(vis, v)
        end
        push!(q, v)
    end
end
println(p1)