
f = map(a -> [a[1], parse(Int, a[2]), split(a[3], ", ")], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rates = Dict(); dists = Dict()
keys = []
for (key, rate, values) in f
    i = findfirst(x -> x == key, keys)
    if isnothing(i)
        push!(keys, key)
        i = length(keys)
    end
    rates[i] = rate
    g[i] = Vector{Int}()
    for value in values
        j = findfirst(x -> x == value, keys)
        if isnothing(j)
            push!(keys, value)
            j = length(keys)
        end
        push!(g[i], j)
    end
    global i += 1
end
for i in eachindex(g), j in eachindex(g), k in eachindex(g)
    
end