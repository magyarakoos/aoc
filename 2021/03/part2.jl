f = open("input", "r")
a = []
for l in eachline(f)
    x = 0
    for i in eachindex(l)
        x |= ((l[i] == '1') << (length(l) - i))
    end
    push!(a, x)
end