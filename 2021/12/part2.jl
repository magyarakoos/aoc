using DataStructures
g = Dict{String, Vector{String}}()
vis = Set(); p1 = 0
twice = ""
count = 0
dfs = (u) -> begin
    println(u)
    sleep(1)
    global count += 1
    if count >= 100 exit(0) end
    if u == "end"
        global p1 += 1
        return
    end
    if islowercase(u[1])
        push!(vis, u)
    end
    for v in g[u]
        if !(v ∈ vis) dfs(v)
        elseif !(v ∈ ["start", "end"]) && !twice
            global twice = true
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
println(p1)