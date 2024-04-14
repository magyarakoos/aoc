f = open("input", "r")
a = []; w = 0
for l in eachline(f)
    x = 0; w = length(l)
    for i in eachindex(l)
        x |= ((l[i] == '1') << (length(l) - i))
    end
    push!(a, x)
end
Ψ = (i, a, λ) -> begin
    if length(a) == 1 return a[1] end
    o = count(x -> (x >> i) & 1 == 1, a)
    return solve(i - 1, 
        filter(x -> λ(length(a) - o, o) ? (x >> i) & 1 == 1 : (x >> i) & 1 == 0, a), λ)
end