f = map(a -> [a[1], parse(Int, a[2]), split(a[3], ", ")], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rates = Dict(); dists = Dict()
nodes = []
for (key, rate, values) in f
    push!(nodes, key)
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

t = 30; p1 = 0; u = "AA"
while true
    best = 0; bestv = ""; bestd = 0
    for (v, dist) in dists[u]
        if dist < t
            if best < (t - dist - 1) * rates[v]
                best = (t - dist - 1) * rates[v]
                bestv = v
                bestd = dist
            end
        end
    end
    if best == 0 break end
    global p1 += best
    global u = bestv
    global t -= bestd
    global rates[u] = 0
    println(u)
end
println(p1)