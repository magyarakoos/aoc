
f = map(a -> [a[1], parse(Int, a[2]), split(a[3], ", ")], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rates = Dict(); dists = Dict()
key_list = Vector{String}()  # Renamed from 'keys' to avoid conflicts
for (key, rate, values) in f
    key_str = string(key)  # Convert key to a string
    i = findfirst(key_list, key_str)
    if isnothing(i)
        push!(key_list, key_str)
        i = length(key_list)
    end
    rates[i] = rate
    g[i] = Vector{String}()
    for value in values
        value_str = string(value)  # Convert value to a string
        j = findfirst(key_list, value_str)
        if isnothing(j)
            push!(key_list, value_str)
            j = length(key_list)
        end
        push!(g[i], j)
    end
    global i += 1
end

for i in eachindex(g)
    println(g[i])
end