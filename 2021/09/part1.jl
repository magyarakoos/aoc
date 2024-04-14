f = map(l -> split(l, ""), readlines("input"))
m = zeros(Int, length(f), length(f[1]))
for i in eachindex(f), j in eachindex(f[1])
    m[i, j] = parse(Int, f[i][j])
end
for i in eachindex(f), j in eachline(f[1])
    
end