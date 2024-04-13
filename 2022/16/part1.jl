
f = map(a -> [a[1], parse(Int, a[2]), split(a[3], ", ")], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rates = Dict(); dists = Dict()
keys = []
for (key, rate, values) in f
    findfirst(keys, key)
    
    rates[i] = rate
    g[i] = Vector{String}()
    for value in values
        push!(g[i], value)
    end
    global i += 1
end
for i in eachindex(g)
    println(g[i])
end