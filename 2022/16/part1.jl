f = map(l -> match(r".{6}(.[A-Z]).{15}(\d+).{24}\s+(.*)", l), readlines("input"))
rates = Dict{String, Int}(); g = Dict{String, Vector{String}}()
for m in f
    rates[m[1]] = parse(Int, m[2])
    for v in split(m[3], ", ")
end