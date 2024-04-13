using Combinatorics
f = map(a -> [a[1], parse(Int, a[2]), split(a[3], ", ")], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rates = Dict(); dists = Dict()
nodes = []; todo = []
for (key, rate, values) in f
    push!(nodes, key)
    if rate != 0
        push!(todo, key)
    end
    rates[key] = rate
    g[key] = Vector{String}()
    dists[key] = Dict{String, Int}()
    dists[key][key] = 0
    for value in values
        dists[key][value] = 1
        push!(g[key], value)
    end
end
for u in nodes, v in nodes
    if !haskey(dists[u], v)
        dists[u][v] = 1e9
    end
end
for u in nodes, v in nodes, k in nodes
    dists[u][v] = min(
        dists[u][v], 
        dists[u][k] + dists[v][k]
    )
end

# for u in nodes, v in nodes 
#     if dists[u][v] == 1 
#         println("$u-$(rates[u]) $v-$(rates[v])")
#     end
# end

p1 = 0
for perm in permutations(todo)
    t = 30; i = 2; cur = 0
    while i <= length(perm)
        d = dists[perm[i - 1]][perm[i]]
        if t <= d break end
        cur += (t - d - 1) * rates[perm[i]]
        i += 1
        t -= d + 1
    end
    global p1 = max(p1, cur)
    if 
end
println(p1)