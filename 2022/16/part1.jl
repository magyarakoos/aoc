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
while 0 < t
    for v in dists[u]
        println(v)
    end
    sleep(1)
end