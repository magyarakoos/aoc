using DataStructures
g = Dict{String, Vector{String}}()
vis = Set(); p2 = 0; twice = ""
dfs = (u) -> begin
    if u == "end"
        global p2 += 1
        return
    end
    if islowercase(u[1]) push!(vis, u) end
    for v in g[u]
        if !(v ∈ vis) dfs(v)
        elseif !(v ∈ ["start", "end"]) && twice == ""
            global twice = v
            dfs(v)
            global twice = ""
        end
    end
    if twice != u delete!(vis, u) end
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
