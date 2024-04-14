f = open("input", "r")
a = []; w = 0
for l in eachline(f)
    x = 0; global w = length(l)
    for i in eachindex(l)
        x |= ((l[i] == '1') << (length(l) - i))
    end
    push!(a, x)
end
Σ = (i, a) -> o = count(x -> (x >> i) & 1 == 1, a)
ω = (i, λ) -> i == -1 ? 0 : (λ(length(a), Σ(i, a)) << i) | ω(i - 1, λ)
Ψ = (i, a, λ) -> begin
    if length(a) == 1 return a[1] end
    return Ψ(i - 1, filter(x -> (x >> i) & 1 == λ(length(a), Σ(i, a)), a), λ)
end
println(ω(w - 1, (l, o) -> l <= o * 2) * ω(w - 1, (l, o) -> l > o * 2))
println(Ψ(w - 1, a, (l, o) -> l <= o * 2) * Ψ(w - 1, a, (l, o) -> l > o * 2))