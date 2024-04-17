using DataStructures
g = Dict{String, Vector{String}}()
vis = Set(); twice = false; p2 = 0
dfs = (u) -> begin
push!(vis, u)
    if u == "end"
        global p2 += 1
        return
    end
    for v in g[u]
        if !(v ∈ vis)
            dfs(v)
        elseif !(v ∈ ["start", "end"]) && !twice
            global twice = true
            push!(vis, v)
            dfs(v)
            global twice = false
        end
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
dfs("start")
println(p2)